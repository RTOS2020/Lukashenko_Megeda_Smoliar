#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

void delay(int ms) {
	for(int i = 0; i < 10000 * ms; i++) { }
}

const int T = 10;
const int a2_t = 5;
const int b10_t = 2;

int main(void)
{	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	for(;;)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
		GPIO_SetBits(GPIOB, GPIO_Pin_10);
		
		if(a2_t < b10_t)
		{
			delay(a2_t);
			GPIO_ResetBits(GPIOA, GPIO_Pin_2);
			
			delay(b10_t - a2_t);
			GPIO_ResetBits(GPIOB, GPIO_Pin_10);
		
			delay(T - b10_t);
		}
		else
		{
			delay(b10_t);
			GPIO_ResetBits(GPIOB, GPIO_Pin_10);
			
			delay(a2_t - b10_t);
			GPIO_ResetBits(GPIOA, GPIO_Pin_2);
		
			delay(T - a2_t);
		}
	}
}
