
#include <avr/io.h>
#define F_CPU 4000000UL
#include <util/delay.h>
#include "AVR_Ports.h"
#include "AVR_GPIO_Declarations.h"
#include "AVR_Counter_Timer.h"

int main(void)
{
	Pin_Direction(B, 3, output); //OC0 output pin
	Pin_Reset(B, 3);

	uint8_t Duty; //Duty ratio for PWM
	PWM_Initialize();

	while(1)
	{
		for (Duty=0; Duty<255; Duty++)
		{
			OCR0 = Duty; //increase the LED light intensity [from 0V to 5V]
			_delay_ms(5);
		}
		
		for (Duty=255; Duty>0; Duty--)
		{
			OCR0 = Duty; //decrease the LED light intensity [from 5V to 0V]
			_delay_ms(5);
		}
	}
}
