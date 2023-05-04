/*
 ******************************************************************************
 * @file           : Led toggle using bit fields header
 * @author         : Jose Luis Figueroa
 * @Date		   : 1 april, 2022
 * @board		   : Nucleo F401RE
 * @brief          : Define the registers using struct.
 ******************************************************************************
 */

#ifndef MAIN_H_
#define MAIN_H_

#include<stdint.h>


typedef struct
{
	volatile uint32_t gpioaen	:1;
	volatile uint32_t gpioben	:1;
	volatile uint32_t gpiocen	:1;
	volatile uint32_t gpioden	:1;
	volatile uint32_t gpioeen	:1;
	volatile uint32_t reserved1	:2;
	volatile uint32_t gpiohen	:1;
	volatile uint32_t reserved2	:4;
	volatile uint32_t crcen		:1;
	volatile uint32_t reserved3	:8;
	volatile uint32_t dma1en	:1;
	volatile uint32_t dma2en	:1;
	volatile uint32_t reserved4	:9;
}RCC_AHB1ENR_t;


typedef struct
{
	volatile uint32_t moder0	:2;
	volatile uint32_t moder1	:2;
	volatile uint32_t moder2	:2;
	volatile uint32_t moder3	:2;
	volatile uint32_t moder4	:2;
	volatile uint32_t moder5	:2;
	volatile uint32_t moder6	:2;
	volatile uint32_t moder7	:2;
	volatile uint32_t moder8	:2;
	volatile uint32_t moder9	:2;
	volatile uint32_t moder10	:2;
	volatile uint32_t moder11	:2;
	volatile uint32_t moder12	:2;
	volatile uint32_t moder13	:2;
	volatile uint32_t moder14	:2;
	volatile uint32_t moder15	:2;
}GPIOx_MODER_t;


typedef struct
{
	volatile uint32_t odr0	:1;
	volatile uint32_t odr1	:1;
	volatile uint32_t odr2	:1;
	volatile uint32_t odr3	:1;
	volatile uint32_t odr4	:1;
	volatile uint32_t odr5	:1;
	volatile uint32_t odr6	:1;
	volatile uint32_t odr7	:1;
	volatile uint32_t odr8	:1;
	volatile uint32_t odr9	:1;
	volatile uint32_t odr10	:1;
	volatile uint32_t odr11	:1;
	volatile uint32_t odr12	:1;
	volatile uint32_t odr13	:1;
	volatile uint32_t odr14	:1;
	volatile uint32_t odr15	:1;
	volatile uint32_t reserved: 16;
}GPIOx_ODR_t;


#endif /* MAIN_H_ */
