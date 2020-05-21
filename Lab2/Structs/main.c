#include "stm32f10x.h"

void delay(int ms) {
	for(int i = 0; i < 10000 * ms; i++) { }
}

const int T = 10;
const int a2_t = 5;
const int b10_t = 2;

int main(void)
{	
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN;
	
	GPIOA->CRL |= GPIO_CRL_MODE2;
	GPIOA->CRL &= ~GPIO_CRL_CNF2;
	
	GPIOB->CRH |= GPIO_CRH_MODE10;
	GPIOB->CRH &= ~GPIO_CRH_CNF10;
	
	for(;;)
	{
		GPIOA->ODR |= GPIO_ODR_ODR2;
		GPIOB->ODR |= GPIO_ODR_ODR10;
		
		if(a2_t < b10_t)
		{
			delay(a2_t);
			GPIOA->ODR &= ~GPIO_ODR_ODR2;
			
			delay(b10_t - a2_t);
			GPIOB->ODR &= ~GPIO_ODR_ODR10;
		
			delay(T - b10_t);
		}
		else
		{
			delay(b10_t);
			GPIOB->ODR &= ~GPIO_ODR_ODR10;
			
			delay(a2_t - b10_t);
			GPIOA->ODR &= ~GPIO_ODR_ODR2;
		
			delay(T - a2_t);
		}
	}
}
