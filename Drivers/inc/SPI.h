/*
 * SPI.h
 *
 *  Created on: Dec 10, 2022
 *      Author: GHADA ELKASSAS
 */

#ifndef INCLUDES_SPI_H_
#define INCLUDES_SPI_H_

void SPI1_INIT(void);
void SPI1_CS_ENABLE(void);
void SPI1_CS_DISABLE(void);
unsigned char SPI_Transmit_Receive(unsigned char data);
//void SPI1_Write(unsigned char data);
//unsigned char SPI1_Read(unsigned char read_data);


#endif /* INCLUDES_SPI_H_ */
