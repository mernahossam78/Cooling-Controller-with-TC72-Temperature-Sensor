#include "stm32f4xx.h"
#include "PollerTimer.h"
#include "poller.h"
#include "device.h"
#include "SPI.h"
#include "LCD.h"
#include "PollingDataClient.h"


int main(void)
{
	/*initialize pin6 portA as output*/
	//	RCC->AHB1ENR |=(1<<0);
	//
	//	GPIOA->MODER |=(1<<10);
	//	GPIOA->MODER &=~(1<<11);

	LCD_Init();

	SPI1_INIT();
	TC72_SELECT();
	TC72_Init(0);
	TC72_UNSELECT();
    PWM_INIT();

	StartTimer();
	EnableInterrupt();
	SetPollingTime(500);
	StartPolling();
	//int temperature;

	while(1)
	{
//		LCD_DisplayString("temp: ");
//		temperature=get_temp();
//		LCD_IntToStr(temperature);
//				for (int i=0; i<500000; i++){}
//				LCD_ClearScreen();


	}

}

void TIM2_IRQHandler(void)
{
	TIM2->SR &=~(1<<0);
	CallPollingFunction();

}


