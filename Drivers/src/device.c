#include "device.h"
#include "SPI.h"
#include "stm32f4xx.h"


float data;

float Get_Data(void)
{
	return 100.0;
}

void TC72_Init(unsigned char mode)
{
	/*reg address for write and 00 for continuous temp conv */
	TC72_RgisterWrite(0x80,0x00);
}

void TC72_RgisterWrite(unsigned char RegAdd, unsigned char Data)
{
	SPI_Transmit_Receive(RegAdd | (1<<7));
	SPI_Transmit_Receive(Data);
}

void TC72_RegisterRead(unsigned char RegAdd, unsigned char *Dataptr)
{
	SPI_Transmit_Receive(RegAdd & (~(1<<7)));
	*Dataptr = SPI_Transmit_Receive(0x00);
}

float get_temp(void)
{

	unsigned char spidata = 0;
	float temp =0.0f;

	TC72_SELECT();
	TC72_RegisterRead(0x01, &spidata);
	TC72_UNSELECT();

	if(spidata & (1 << 7)){

		temp +=0.5f;
	}
	if(spidata &(1 << 6)){
		temp += 0.25f;
	}
	//			SPI1_CS_ENABLE();

	TC72_SELECT();
	TC72_RegisterRead(0x02, &spidata);
	TC72_UNSELECT();
	//			SPI1_CS_DISABLE();

	temp += (signed char)spidata;
	return temp;
}
