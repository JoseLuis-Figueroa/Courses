/*
 ******************************************************************************
 * @file           : LED Toggle Address
 * @author         : Jose Luis Figueroa
 * @Date		   : 7 Jan, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Configure PA5(LED) to toggle
 ******************************************************************************
 */

/******************************************************************************
* Registers definition
******************************************************************************/
//Definitions
#include <stdint.h>
#define __IO volatile

//AHB1 bus Base Address.
#define PERIPH_BASE			(0x40000000UL)
#define AHB1PERIPH_OFFSET	(0x00020000UL)
#define AHB1PERIPH_BASE		(PERIPH_BASE + AHB1PERIPH_OFFSET)

//GPIOA Base Address
#define GPIOA_OFFSET		(0x00000000UL)
#define GPIOA_BASE			(AHB1PERIPH_BASE + GPIOA_OFFSET)
//GPIOA registers
typedef struct
{
	__IO uint32_t MODER;	/*!<GPIO port mode register,Address offset: 0x00*/
	__IO uint32_t OTYPER;	/*!<GPIO port output type register, Address offset: 0x04*/
	__IO uint32_t OSPEEDR;  /*!<GPIO port output speed register, Address offset: 0x08*/
	__IO uint32_t PUPDR;	/*!<GPIO port pull-up/pull-down register, Address offset: 0x0C*/
	__IO uint32_t IDR;		/*!<GPIO port input data register, Address offset: 0x10*/
	__IO uint32_t ODR;		/*!<GPIO port output data register, Address offset: 0x14*/
	__IO uint32_t BSRR; 	/*!<GPIO port bit set/reset register, Address offset: 0x18*/
	__IO uint32_t LCKR;		/*!<GPIO port configuration lock register, Address offset: 0x1C*/
}GPIO_TypeDef;
//Access GPIOA registers (typecast)
#define GPIOA ((GPIO_TypeDef*) GPIOA_BASE)

//Resetting Clock Control Base Address
#define RCC_OFFSET			(0x3800UL)
#define RCC_BASE			(AHB1PERIPH_BASE + RCC_OFFSET)
//RCC registers
typedef struct
{
	__IO uint32_t DUMMY_REG[12];
	__IO uint32_t AHB1ENR; /*!< RCC AHB1 peripheral clock register, Address offset: 0x30*/
}RCC_TypeDef;
//Access RCC registers (typecast)
#define RCC ((RCC_TypeDef*) RCC_BASE)


/******************************************************************************
*Assignation pins
******************************************************************************/
//Pins
//Set GPIOA Enabler
#define GPIOAEN 			(1U<<0)
//Set output pin
#define PIN5				(1U<<5)
#define LED_PIN				PIN5


/******************************************************************************
* Main
******************************************************************************/
int main (void)
{
	//Enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOAEN;
	//Set PA5 as output pin
	GPIOA->MODER |= (1U<<10);	//Set bit 10 to 1
	GPIOA->MODER &=~(1U<<11);	//Set bit 11 to 0

	while(1)
	{
		//Set PA5 high
		//GPIOA_OD_R |= LED_PIN;

		//Toggle PA5
		GPIOA->ODR ^= LED_PIN;
		for(int i=0; i<100000; i++) 	//Make a delay
        {
            asm("nop");
        }
	}

}
