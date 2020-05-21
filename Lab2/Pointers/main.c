void delay(int ms) {
	for(int i = 0; i < 10000 * ms; i++) { }
}

const int T = 10;
const int a2_t = 5;
const int b10_t = 2;

int main(void)
{	
	int *ptr_RCC_APB2ENR = (int*)0x40021018;	
	*ptr_RCC_APB2ENR |= 0x000C;
	
	int *GPIO_A_CRL = (int*)0x40010800;	
	*GPIO_A_CRL = 0x00000300;
	int *GPIO_A_ODR = (int*)0x4001080C;
	*GPIO_A_ODR = 0x00000002;
	
	int *GPIO_B_CRH = (int*)0x40010C04;	
	*GPIO_B_CRH = 0x00000300;
	int *GPIO_B_ODR = (int*)0x40010C0C;
	
	for(;;)
	{
		*GPIO_A_ODR = 0x00000002;
		*GPIO_B_ODR = 0x00000200;
		
		if(a2_t < b10_t)
		{
			delay(a2_t);
			*GPIO_A_ODR = 0x00000000;
			
			delay(b10_t - a2_t);
			*GPIO_B_ODR = 0x00000000;
		
			delay(T - b10_t);
		}
		else
		{
			delay(b10_t);
			*GPIO_B_ODR = 0x00000000;
			
			delay(a2_t - b10_t);
			*GPIO_A_ODR = 0x00000000;
		
			delay(T - a2_t);
		}
	}
}
