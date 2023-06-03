#include "stm32f4xx.h"
#include "PollingDataClient.h"
#include "LCD.h"

void Handle_data(float data)
{
	if(data>900.0)
	{
		GPIOA->ODR |= (1u<<5);
	}
	else
	{
		GPIOA->ODR &= ~(1u<<5);
	}
}


void PID_Controller( float temperature){
	float measured_temperature = temperature;
	float Set_Temperature =30;
	float error = Set_Temperature - measured_temperature;
	float integrator=0;
	float proportional = (0.1) * error;
	integrator = integrator + error;

    int PWM_Signal = ((float)proportional*10 ) + ((0.01) * integrator*10);

    if (PWM_Signal > 186) {

    	PWM_Signal = 186;

    } else if (PWM_Signal < 0) {

    	PWM_Signal = 0;
    }
    TIM5->CCR1 = PWM_Signal;

	LCD_IntToStr(temperature);
	for(int i=0;i<500;i++){

	}
	LCD_ClearScreen();

}


void PWM_INIT(void)
{
	/*PORT B ENABLE*/
	RCC->AHB1ENR |=(1U<<0);
	/*TIM3 CLOCK ENABLE*/
	RCC-> APB1ENR |=(1U<<3);
	/*PIN 4 PORTB AS ULTRNANTE FUNCTION*/
	GPIOA->MODER &=~(1U<<0);
	GPIOA->MODER |= (1U<<1);
	GPIOA->AFR[0] |= 0x00000002;

	//TIM1->CCMR1 &=~(1<<4);
	/*CAPTURE COMPARE REGISTER CHANNEL 1*/
	TIM5->CCER |=(1<<0);
	/* Auto-reload preload enable*/
	TIM5->CR1 |= (1<<7);
	/**/
	TIM5->CCMR1 &=~(1<<4);
	TIM5->CCMR1 |=(1<<5);
	TIM5->CCMR1 |=(1<<6);

	TIM5->CCMR1 |=(1<<3);

	/*SET PWM*/
	TIM5->PSC = 1600-1;
	TIM5->ARR = 255;

	TIM5->EGR |= (1<<0);
	TIM5->CR1 |= (1<<0);


}

