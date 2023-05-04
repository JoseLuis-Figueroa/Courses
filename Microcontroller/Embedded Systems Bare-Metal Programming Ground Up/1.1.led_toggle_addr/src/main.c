/*
 ******************************************************************************
 * @file           : led_toogle_addr
 * @author         : Jose Luis Figueroa
 * @Date		   : 7 Jan, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Configure PA5(LED) to toggle
 ******************************************************************************
 */

/******************************************************************************
* Registers and pins definition
******************************************************************************/
/*Set AHB1 bus. AHB1 bus contains 0x40020000 to 0x4002 67FF boundary address*/
#define PERIPH_BASE			(0x40000000UL)
#define AHB1PERIPH_OFFSET	(0x00020000UL)
#define AHB1PERIPH_BASE		(PERIPH_BASE + AHB1PERIPH_OFFSET)

/*General Purpose Input Output A*/
#define GPIOA_OFFSET		(0x00000000UL)
#define GPIOA_BASE			(AHB1PERIPH_BASE + GPIOA_OFFSET)
/*GPIO MODER Register*/
#define MODE_R_OFFSET		(0x00UL)
#define GPIOA_MODE_R		(*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))
/*GPIO Port Output Data Register*/
#define OD_R_OFFSET			(0x14UL)
#define GPIOA_OD_R			(*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))

/*Resetting Clock Control Base*/
#define RCC_OFFSET			(0x3800UL)
#define RCC_BASE			(AHB1PERIPH_BASE + RCC_OFFSET)
/*RCC AHB1 Enable Register*/
#define AHB1EN_R_OFFSET		(0x30UL)
#define RCC_AHB1EN_R		(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))

/*Pins definition*/
/*Set GPIOA Enabler*/
#define GPIOAEN 			(1U<<0)
/*Set output pin*/
#define PIN5				(1U<<5)
#define LED_PIN				PIN5


/******************************************************************************
* Main
******************************************************************************/
int main (void)
{
	/*Enable clock access to GPIOA*/
	RCC_AHB1EN_R |= GPIOAEN;
	/*Set PA5 as output pin*/
	GPIOA_MODE_R |= (1U<<10);	/*Set bit 10 to 1*/
	GPIOA_MODE_R &=~(1U<<11);	/*Set bit 11 to 0*/

	while(1)
	{
		/*Set PA5 high*/
		GPIOA_OD_R |= LED_PIN;

		/*Toggle PA5*/
		/*GPIOA_OD_R ^= LED_PIN;*/
		for(int i=0; i<100000; i++)	/*Make a delay*/
		{
			asm("nop");
		}
	}

}
