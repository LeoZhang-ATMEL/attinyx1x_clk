#include <atmel_start.h>
#include <util/delay.h>
#include "rstctrl.h"
#include <avr/sleep.h>

int main(void)
{
	ccp_write_io((void*)&(CLKCTRL.MCLKCTRLA),CLKCTRL_CLKSEL_OSC20M_gc /* 16MHz Internal Oscillator (OSC16M) */
			 | 1 << CLKCTRL_CLKOUT_bp /* System clock out: disabled */);
		
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	/* Replace with your application code */
	uint8_t i;
	for (i = 0; i < 10; i++) {
		_delay_ms(500);
		LED1_toggle_level();	
	}
	LED1_set_level(false);
	LED2_set_level(false);
	LED3_set_level(false);
	if(PORTA_INTFLAGS & 0x04)PORTA_INTFLAGS|=0x04;
	PA2_set_isc(PORT_ISC_LEVEL_gc);
	
	EN_set_level(false);
	sleep_mode();

	while (1) {
	}
}

ISR(PORTA_PORT_vect)
{
	if(PORTA_INTFLAGS & 0x04) {
		PORTA_INTFLAGS|=0x04;
		if (PA2_get_level() == false) {
			RSTCTRL_reset();
		}
	}

	PORTA_INTFLAGS = 0xFF;
}