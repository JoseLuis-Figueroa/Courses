/*
 ****************************************************************
 * @file           : SPI implemantation
 * @author         : Jose Luis Figueroa
 * @Date		   : 8 jul, 2022
 * @board		   : Nucleo F401RE
 * @brief          : spi.c implements an spi protocol containing
 *                 : all the function implementation.
 ****************************************************************
*/
#include "spi.h"

/****************************************************************
*Standard functions
*****************************************************************/
void spi1_gpioa_init(void)
{
    /* Configure the GPIOA to be used as SPI.
     * PA5 => CLk | PA6 => MISO | PA7 => MOSI | PA9 => SS
    */

   /********Configure spi gpio pin***********/
   /*Enable clock access to GPIOA*/
   RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
   /*Set PA5, PA6 and PA7 mode to alternate function*/
   /*PA5*/
   GPIOA->MODER &=~GPIO_MODER_MODER5_0;
   GPIOA->MODER |= GPIO_MODER_MODER5_1;
   /*PA6*/
   GPIOA->MODER &=~GPIO_MODER_MODER6_0;
   GPIOA->MODER |= GPIO_MODER_MODER6_1;
   /*PA7*/
   GPIOA->MODER &=~GPIO_MODER_MODER7_0;
   GPIOA->MODER |= GPIO_MODER_MODER7_1;
   /*Set PA9 as output pin*/
   GPIOA->MODER |= GPIO_MODER_MODER9_0;
   GPIOA->MODER &=~GPIO_MODER_MODER9_1;
   /*Set PA5, PA6 and PA7 mode to alternate function*/
   /*PA5*/
   GPIOA->AFR[0] |= GPIO_AFRL_AFRL5_0;
   GPIOA->AFR[0] &=~GPIO_AFRL_AFRL5_1;
   GPIOA->AFR[0] |= GPIO_AFRL_AFRL5_2;
   GPIOA->AFR[0] &=~GPIO_AFRL_AFRL5_3;
   /*PA6*/
   GPIOA->AFR[0] |= GPIO_AFRL_AFRL6_0;
   GPIOA->AFR[0] &=~GPIO_AFRL_AFRL6_1;
   GPIOA->AFR[0] |= GPIO_AFRL_AFRL6_2;
   GPIOA->AFR[0] &=~GPIO_AFRL_AFRL6_3;
   /*PA7*/
   GPIOA->AFR[0] |= GPIO_AFRL_AFRL7_0;
   GPIOA->AFR[0] &=~GPIO_AFRL_AFRL7_1;
   GPIOA->AFR[0] |= GPIO_AFRL_AFRL7_2;
   GPIOA->AFR[0] &=~GPIO_AFRL_AFRL7_3;
}

void spi1_config(void)
{
    /*Configure spi1 module*/
    /*Enable clock access to spi1*/
    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
    /*Set baut rate control(Fpckl/4= 16MHz/4= 4MHz)*/
    SPI1->CR1 |= SPI_CR1_BR_0;
    SPI1->CR1 &=~SPI_CR1_BR_1;
    SPI1->CR1 &=~SPI_CR1_BR_2;
    /*Set clock polarity and clock phase. Mode 3 is configured*/
    SPI1->CR1 |= SPI_CR1_CPOL;
    SPI1->CR1 |= SPI_CR1_CPHA;
    /*Set full duplex comunication*/
    SPI1->CR1 &=~SPI_CR1_RXONLY;
    /*Set the frame format to MSB transmitted first*/
    SPI1->CR1 &=~SPI_CR1_LSBFIRST;
    /*Set the MCU as master device*/
    SPI1->CR1 |= SPI_CR1_MSTR;
    /*Set data frame format to 8 bits*/
    SPI1->CR1 &=~SPI_CR1_DFF;
    /*Select software slave management by setting SSM and SSI*/
    SPI1->CR1 |= SPI_CR1_SSI;
    SPI1->CR1 |= SPI_CR1_SSM;
    /*Enable the SPI module*/
    SPI1->CR1 |= SPI_CR1_SPE;
}

/****************************************************************
*Communication functions
*****************************************************************/
void spi1_transmit(uint8_t *data, uint32_t size)
{
    /*Handle the transmition of the data*/
    uint32_t i=0;
    uint8_t temp;
    
    /*To send all the date*/
    while (i<size)
    {
        /*Wait until TXE is set(buffer empty)*/
        while(!(SPI1->SR & SPI_SR_TXE))
        {
            asm("nop");
        }
        /*Write the data to the data register*/
        SPI1->DR = data[i];
        /*Increase the data size*/
        i++;
    }
    /*Wait until TXE is set. To ensure the bus is empty*/
    while(!(SPI1->SR & SPI_SR_TXE))
    {
        asm("nop");
    }
    /*Wait until bus is not busy to reset*/
    while(SPI1->SR & SPI_SR_BSY)
    {
        asm("nop");
    }
    /*Clear OVR flag. If no, the following data will be incorrect*/
    temp = SPI1->DR;
    temp = SPI1->SR;
}

void spi1_receive(uint8_t *data, uint32_t size)
{
    /*Manage the reception of the data*/

    /*Finish with all data is received*/
    while (size)
    {
        /*Send dummy data. Recommended*/
        SPI1->DR = 0;
        /*Wait for RXEN flag to be set*/
        while(!(SPI1->SR & SPI_SR_RXNE))
        {
            asm("nop");
        }
        /*Read the data*/
        *data++ = SPI1->DR;
        size--;
    }
}

void cs_enable(void)
{
    /*Enable the slave 1 (accelerometer)*/
    GPIOA->ODR &=~ ADXL345_PIN;
}

void cs_disable(void)
{
    /*Disable the slave 1 (accelerometer)*/
    GPIOA->ODR |= ADXL345_PIN;
}