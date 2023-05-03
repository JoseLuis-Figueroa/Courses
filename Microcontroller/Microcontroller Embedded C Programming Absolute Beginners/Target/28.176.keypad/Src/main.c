/*
 ******************************************************************************
 * @file           : Keypad
 * @author         : Jose Luis Figueroa
 * @Date		   : 4 april, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Implement a keypad
 ******************************************************************************
 */
#include <stdio.h>
#include <stdint.h>

static void delay(void);

int main(void)
{
    /*Register's address*/
	uint32_t volatile *const rcc_ahb1enr = (uint32_t*)0x40023830;
	uint32_t volatile *const gpioc_moder = (uint32_t*)0x40020800;
	uint32_t volatile *const gpioc_pupdr = (uint32_t*)0x4002080c;
	uint32_t volatile *const gpioc_idr =   (uint32_t*)0x40020810;
	uint32_t volatile *const gpioc_odr =   (uint32_t*)0x40020814;

	/*Enable the peripheral clock of GPIOC*/
	*rcc_ahb1enr |= (1<<2);

	/*Configure PC0 to PC3 as output(rows)*/
	*gpioc_moder |= 0x55;

	/*Configure PC4 to PC7 as input (columns)*/
	*gpioc_moder &=~(0xFF<<8);

	/*Enable internal pull-up resistors for PC4 to PC7*/
	*gpioc_pupdr |= (0x55<<8);

	while(1)
	{
		/*PC0 to PC3 (rows) are high state*/
		*gpioc_odr |= 0x0F;

		/*Make R1 low state*/
		*gpioc_odr &=~(1U<<0);
		/*Review if a column of row1 is pressed. Condition review if the bit is
		 * True or False. Enter if the condition is false in this case*/
		if(!(*gpioc_idr & (1U<<4)))
		{
			delay();
			printf("1\n");
		}

		if(!(*gpioc_idr & (1U<<5)))
		{
			delay();
			printf("2\n");
		}

		if(!(*gpioc_idr & (1U<<6)))
		{
			delay();
			printf("3\n");
		}

		if(!(*gpioc_idr & (1U<<7)))
		{
			delay();
			printf("A\n");
		}

		/*Make R2 low state*/
		*gpioc_odr = 0x0F;
		*gpioc_odr &=~(1U<<1);
		/*Review if a column of row2 is pressed*/
		if(!(*gpioc_idr & (1U<<4)))
		{
			delay();
			printf("4\n");
		}

		if(!(*gpioc_idr & (1U<<5)))
		{
			delay();
			printf("5\n");
		}

		if(!(*gpioc_idr & (1U<<6)))
		{
			delay();
			printf("6\n");
		}

		if(!(*gpioc_idr & (1U<<7)))
		{
			delay();
			printf("B\n");
		}

		/*Make R3 low state*/
		*gpioc_odr = 0x0F;
		*gpioc_odr &=~(1U<<2);
		/*Review if a column of row3 is pressed*/
		if(!(*gpioc_idr & (1U<<4)))
		{
			delay();
			printf("7\n");
		}

		if(!(*gpioc_idr & (1U<<5)))
		{
			delay();
			printf("8\n");
		}

		if(!(*gpioc_idr & (1U<<6)))
		{
			delay();
			printf("9\n");
		}

		if(!(*gpioc_idr & (1U<<7)))
		{
			delay();
			printf("C\n");
		}

		/*Make R4 low state*/
		*gpioc_odr = 0x0F;
		*gpioc_odr &=~(1U<<3);
		/*Review if a column of row4 is pressed*/
		if(!(*gpioc_idr & (1U<<4)))
		{
			delay();
			printf("*\n");
		}

		if(!(*gpioc_idr & (1U<<5)))
		{
			delay();
			printf("0\n");
		}

		if(!(*gpioc_idr & (1U<<6)))
		{
			delay();
			printf("#\n");
		}

		if(!(*gpioc_idr & (1U<<7)))
		{
			delay();
			printf("D\n");
		}

	}

}


static void delay(void)
{
	for(uint32_t i=0; i<300000; i++);
}
