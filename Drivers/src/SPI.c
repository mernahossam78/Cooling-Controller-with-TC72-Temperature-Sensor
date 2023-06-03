/*
 * SPI.c
 *
 *  Created on: Dec 10, 2022
 *      Author: GHADA ELKASSAS
 */

#include "stm32f4xx.h"
#include "SPI.h"

#define SPI1_AF_EN() (GPIOA->AFR[0] |= 0x555 << (5*4))

void SPI1_INIT(void)
{
	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |=(1U<<0);

	/*Set Alternate function mode*/
	/*sck pin5*/
	GPIOA->MODER &=~(1U<<10);
	GPIOA->MODER |= (1U<<11);
	/*sdo pin6*/
	GPIOA->MODER &=~(1U<<12);
	GPIOA->MODER |= (1U<<13);
	/*sdi pin7*/
	GPIOA->MODER &=~(1U<<14);
	GPIOA->MODER |= (1U<<15);

	SPI1_AF_EN();

	/*Set PA9 as output (ce)*/
	GPIOA->MODER &=~(1U<<19);
	GPIOA->MODER |= (1U<<18);
	GPIOA->OTYPER &=~(1U<<9);

	/*AF05 TO THE THREE PINS*/
	//	GPIOA->AFR[0] &= ~0xAAA00000;
	//	GPIOA->AFR[0] |= 0x55500000;

	/**********************************/
	/*Enable clock access to SPI1*/
	RCC->APB2ENR |=(1U<<12);

	/*SET BAUD RATE TO FPCLK/16*/
	SPI1->CR1 |=(1U<<4);
	SPI1->CR1 |=(1U<<3);


	/*FULL DUPLEX*/
	/*change*/
	SPI1->CR1 &=~(1U<<10);

	/*Set to CPOL, CPHA*/
	//change

	SPI1->CR1 |=(1U<<0);
	SPI1->CR1 &=~(1U<<1);

	/*Set data frame format*/
	SPI1->CR1 &=~(1U<<11);

	/*kona hna  (kant 0)*/
	/*SET LSB FIRST*/
	SPI1->CR1 &=~(1U<<7);

	/*Set Software slave management*/
	SPI1->CR1 |=(1U<<8);
	SPI1->CR1 |=(1U<<9);

	/*Set to master*/
	SPI1->CR1 |=(1U<<2);

	/*SPI enable*/
	SPI1->CR1 |=(1U<<6);

}

//void SPI1_Write(unsigned char data)
//{
//	/*Write data to data register*/
//	SPI1->DR = data;
//	while(!(SPI1->SR & (1U<<1))){}
//}
//
//unsigned char SPI1_Read(void)
//{
//	while(!(SPI1->SR & (1U<<0))){}
//	return SPI1->DR;
//}
//

/*act as a slave*/
void SPI1_CS_ENABLE(void)
{
	GPIOA->ODR |=(1U<<9);
}

/*act as master*/
/*change*/
void SPI1_CS_DISABLE(void)
{
	GPIOA->ODR &=~(1U<<9);
}

unsigned char SPI_Transmit_Receive(unsigned char data)
{
	if (SPI1 -> SR & (1<< 1)){
		SPI1->DR = data;
		while (SPI1 ->SR & (1<<7));
		return SPI1->DR;
	}
	return -1;
}
