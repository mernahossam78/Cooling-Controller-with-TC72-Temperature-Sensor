#include "GPIO.h"
#ifndef INC_DEVICE_H_
#define INC_DEVICE_H_

#define TC72_SELECT() (GPIO_Write(GPIOA, 9, 1))
#define TC72_UNSELECT() (GPIO_Write(GPIOA, 9, 0))

float Get_Data();
void TC72_Init(unsigned char mode);
void TC72_RgisterWrite(unsigned char RegAdd, unsigned char Data);
void TC72_RegisterRead(unsigned char RegAdd, unsigned char *Dataptr);
float get_temp(void);

#endif /* INC_DEVICE_H_ */
