/*
 ****************************************************************
 * @file           : I2C implemantation
 * @author         : Jose Luis Figueroa
 * @Date		   : 7 jun, 2022
 * @board		   : Nucleo F401RE
 * @brief          : i2c.c implements an I2C protocol containing
 *                 : all the function implementation.
 *                 : Note: Bus is locked up (busy flag=1 and 
 *                 : SDA pin=0) when stopping in the middle of a 
 *                 : transition.  
 *                 : Disconnect the SCL and SDA wires a lit bit 
 *                 : time while the boards is on to fix the bus.
 ****************************************************************
*/
#include "i2c.h"

/****************************************************************
*Standard functions
*****************************************************************/
void i2c1_init(void)
{
    /* Initialize the I2C1 peripherial.
     * PB8 = SCL and PB9 = SDA 
    */
   /********Configure i2c gpio pin***********/
    /*Enable clock access to GPIOB*/
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    /*Set PB8 and PB9 mode to alternate function.
    PB8*/
    GPIOB->MODER &=~GPIO_MODER_MODER8_0;
    GPIOB->MODER |= GPIO_MODER_MODER8_1;
    /*PB9*/
    GPIOB->MODER &=~GPIO_MODER_MODER9_0;
    GPIOB->MODER |= GPIO_MODER_MODER9_1;
    /*Set PB8 and PB9 output type to open drain source*/
    GPIOB->OTYPER |= GPIO_OTYPER_OT8;
    GPIOB->OTYPER |= GPIO_OTYPER_OT9;
    /*Enable pull up for PB8 and PB9.
    PB8*/
    GPIOB->PUPDR |= GPIO_PUPDR_PUPD8_0;
    GPIOB->PUPDR &=~GPIO_PUPDR_PUPD8_1;
    /*PB9*/
    GPIOB->PUPDR |= GPIO_PUPDR_PUPD9_0;
    GPIOB->PUPDR &=~GPIO_PUPDR_PUPD9_1;
    /*Set PB8 and PB9 alternate function type to I2C (AF4).
    PB8*/
    GPIOB->AFR[1] &=~(1U<<0);
    GPIOB->AFR[1] &=~(1U<<1);
    GPIOB->AFR[1] |= (1U<<2);
    GPIOB->AFR[1] &=~(1U<<3);
    /*PB9*/
    GPIOB->AFR[1] &=~(1U<<4);
    GPIOB->AFR[1] &=~(1U<<5);
    GPIOB->AFR[1] |= (1U<<6);
    GPIOB->AFR[1] &=~(1U<<7);

    /********Configure i2c module***********/
    /*Enable clock access to I2C1*/
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
    /*Software reset*/
    I2C1->CR1 |= I2C_CR1_SWRST;
    /*Come out of reset mode*/
    I2C1->CR1 &=~I2C_CR1_SWRST;
    /*Set peripherial clock frequency = 16MHz */
    I2C1->CR2 |= I2C_CR2_FREQ_4;
    /*Set I2C to standard mode, clock_frequency=100kHz*/
    I2C1->CCR = I2C_100KHZ;
    /*Set maximum rise time*/
    I2C1->TRISE = MAX_RISE_TIME; 
    /*Enable I2C peripherial*/
    I2C1->CR1 |= I2C_CR1_PE;
}


/****************************************************************
*Read functions
*****************************************************************/
void i2c1_byte_read(char slave_add, char memory_add, char* data)
{
    /*Master (MCU) reads a byte of the slave (receiver mode)*/

    volatile int tmp;
    /*Wait until bus flag is not busy (flag=0)*/
    while(I2C1->SR2 & I2C_SR2_BUSY)
    {
        asm("nop");
    }
    /*Start generation*/
    I2C1->CR1 |= I2C_CR1_START;
    /*Wait until start flag is set (flag=1)*/
    while(!(I2C1->SR1 & I2C_SR1_SB))
    {
        asm("nop");
    }
    /*Transmit slave address and R/W bit (write = 0)*/
    I2C1->DR = slave_add << 1;
    /*Wait until the end of the address transmission (flag=1)*/
    while(!(I2C1->SR1 & I2C_SR1_ADDR))
    {
        asm("nop");
    }
    /*Clear address flag (reference manual process)*/
    tmp = I2C1->SR2;
    /*Send memory address (register address)*/
    I2C1->DR = memory_add;
    /*Wait until data register is emphy (send all data)*/
    while (!(I2C1->SR1 & I2C_SR1_TXE))
    {
        asm("nop");
    }
    /*Generate restart*/
    I2C1->CR1 |= I2C_CR1_START;
    /*Wait until start flag is set (flag=1)*/
    while(!(I2C1->SR1 & I2C_SR1_SB))
    {
        asm("nop");
    }
    /*Transmit slave address and R/W bit (Read = 1)*/
    I2C1->DR = slave_add << 1 | 1;
    /*Wait until the end of the address transmission (flag=1)*/
    while(!(I2C1->SR1 & I2C_SR1_ADDR))
    {
        asm("nop");
    }
    /*Disable Acknowledge*/
    I2C1->CR1 &=~I2C_CR1_ACK;
    /*Clear address flag (reference manual process)*/
    tmp = I2C1->SR2;
    /*Stop generation enables the stop condition after data received*/
    I2C1->CR1 |= I2C_CR1_STOP;
    /*Wait until the data is received*/
    while(!(I2C1->SR1 & I2C_SR1_RXNE))
    {
        asm("nop");
    }
    /*Read data from slave(DR). Save the data and increase the 
    address*/
    *data++ = I2C1->DR;
}

void i2c1_burst_read(char slave_add, char memory_add, uint16_t n,
char* data)
{
    /*Master (MCU) reads n bytes of the slave (receiver mode)*/

    volatile int tmp;
    /*Wait until bus flag is not busy (flag=0)*/
    while(I2C1->SR2 & I2C_SR2_BUSY)
    {
        asm("nop");
    }
    /*Start generation*/
    I2C1->CR1 |= I2C_CR1_START;
    /*Wait until start flag is set (flag=1)*/
    while(!(I2C1->SR1 & I2C_SR1_SB))
    {
        asm("nop");
    }
    /*Transmit slave address and R/W bit (write = 0)*/
    I2C1->DR = slave_add << 1;
    /*Wait until the end of the address transmission (flag=1)*/
    while(!(I2C1->SR1 & I2C_SR1_ADDR))
    {
        asm("nop");
    }
    /*Clear address flag (reference manual process)*/
    tmp = I2C1->SR2;
    /*Wait until data register is emphy (send all data)*/
    while (!(I2C1->SR1 & I2C_SR1_TXE))
    {
        asm("nop");
    }
    /*Send memory address (register address)*/
    I2C1->DR = memory_add;
    /*Wait until data register is emphy (send all data)*/
    while (!(I2C1->SR1 & I2C_SR1_TXE))
    {
        asm("nop");
    }
    /*Generate restart*/
    I2C1->CR1 |= I2C_CR1_START;
    /*Wait until start flag is set (flag=1)*/
    while(!(I2C1->SR1 & I2C_SR1_SB))
    {
        asm("nop");
    }
    /*Transmit slave address and R/W bit (Read = 1)*/
    I2C1->DR = slave_add << 1 | 1;
    /*Wait until the end of the address transmission (flag=1)*/
    while(!(I2C1->SR1 & I2C_SR1_ADDR))
    {
        asm("nop");
    }
    /*Clear address flag (reference manual process)*/
    tmp = I2C1->SR2;
    /*Disable Acknowledge*/
    I2C1->CR1 |= I2C_CR1_ACK;
    /*read all the data*/
    while (n > 0U)
    {
        /*if one byte*/
        if(n == 1U)
        {
            /*Disable acknowledge*/
            I2C1->CR1 &=~I2C_CR1_ACK;
            /*Generate stop*/
            I2C1->CR1 |= I2C_CR1_STOP;
        }
        /*Wait until RXNE flag is set*/
        while(!(I2C1->SR1 & I2C_SR1_RXNE))
        {
            asm("nop");
        }
        /*Read data from DR*/
        *data++ = I2C1->DR;
        n--;
    }
}

/****************************************************************
*Write function
*****************************************************************/
void i2c1_burst_write(char slave_add, char memory_add, uint16_t n,
char* data)
{
    /*Master (MCU) writes n bytes to the slave (transmitter mode)*/

    volatile int tmp;
    /*Wait until bus flag is not busy (flag=0)*/
    while(I2C1->SR2 & I2C_SR2_BUSY)
    {
        asm("nop");
    }
    /*Start generation*/
    I2C1->CR1 |= I2C_CR1_START;
    /*Wait until start flag is set (flag=1)*/
    while(!(I2C1->SR1 & I2C_SR1_SB))
    {
        asm("nop");
    }
    /*Transmit slave address and R/W bit (write = 0)*/
    I2C1->DR = slave_add << 1;
    /*Wait until the end of the address transmission (flag=1)*/
    while(!(I2C1->SR1 & I2C_SR1_ADDR))
    {
        asm("nop");
    }
    /*Clear address flag (reference manual process)*/
    tmp = I2C1->SR2;
    /*Wait until data register is emphy (send all data)*/
    while (!(I2C1->SR1 & I2C_SR1_TXE))
    {
        asm("nop");
    }
    /*Send memory address (register address)*/
    I2C1->DR = memory_add;
    /*Write all the data*/
    for (int i=0; i<n; i++)
    {
        /*Wait until data register empty*/
        while(!(I2C1->SR1 & I2C_SR1_TXE))
        {
            asm("nop");
        }
        /*Transmit memory address*/
        I2C1->DR = *data++;
    }
    /*Wait until transfer finished*/
    while(!(I2C1->SR1 & I2C_SR1_BTF))
    {
        asm("nop");
    }
    /*Generate stop condition*/
    I2C1->CR1 |= I2C_CR1_STOP;
}
