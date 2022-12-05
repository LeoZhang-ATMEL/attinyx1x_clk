#include <atmel_start.h>
#include <util/delay.h>
#include "rstctrl.h"
#include <avr/sleep.h>
extern void PWM_0_init();
int main(void)
{
	//ccp_write_io((void*)&(CLKCTRL.MCLKCTRLA),CLKCTRL_CLKSEL_OSC20M_gc /* 16MHz Internal Oscillator (OSC16M) */
	//		 | 1 << CLKCTRL_CLKOUT_bp /* System clock out: disabled */);
	PWM_0_init();
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	/* Replace with your application code */
	uint8_t i;
	for (i = 0; i < 10; i++) {
		_delay_ms(500);
		LED1_toggle_level();	
	}
	
	/* set the alternate pin mux */
	LED3_set_dir(PORT_DIR_OUT);
	PORTMUX.CTRLC = 0x00;
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

void PWM_0_init()
{
	LED3_set_level(
		// <y> Initial level
		// <id> pad_initial_level
		// <false"> Low
		// <true"> High
		false);

		LED3_set_dir(PORT_DIR_OUT);

		/* set the alternate pin mux */
		PORTMUX.CTRLC |= PORTMUX_TCA02_bm;
		

	// TCA0.SINGLE.CMP0 = 0x0; /* Setting: 0x0 */

	// TCA0.SINGLE.CMP1 = 0x0; /* Setting: 0x0 */

	TCA0.SINGLE.CMP2 = 0x5; /* Setting: 0x5 */

	// TCA0.SINGLE.CNT = 0x0; /* Count: 0x0 */

	TCA0.SINGLE.CTRLB = 0 << TCA_SINGLE_ALUPD_bp            /* Auto Lock Update: disabled */
		| 0 << TCA_SINGLE_CMP0EN_bp         /* Setting: disabled */
		| 0 << TCA_SINGLE_CMP1EN_bp         /* Setting: disabled */
		| 1 << TCA_SINGLE_CMP2EN_bp         /* Setting: enabled */
		| TCA_SINGLE_WGMODE_SINGLESLOPE_gc; /*  */

	// TCA0.SINGLE.CTRLC = 0 << TCA_SINGLE_CMP0OV_bp /* Setting: disabled */
	//		 | 0 << TCA_SINGLE_CMP1OV_bp /* Setting: disabled */
	//		 | 0 << TCA_SINGLE_CMP2OV_bp; /* Setting: disabled */

	// TCA0.SINGLE.DBGCTRL = 0 << TCA_SINGLE_DBGRUN_bp; /* Debug Run: disabled */

	// TCA0.SINGLE.EVCTRL = 0 << TCA_SINGLE_CNTEI_bp /* Count on Event Input: disabled */
	//		 | TCA_SINGLE_EVACT_POSEDGE_gc /* Count on positive edge event */;

	// TCA0.SINGLE.INTCTRL = 0 << TCA_SINGLE_CMP0_bp /* Compare 0 Interrupt: disabled */
	//		 | 0 << TCA_SINGLE_CMP1_bp /* Compare 1 Interrupt: disabled */
	//		 | 0 << TCA_SINGLE_CMP2_bp /* Compare 2 Interrupt: disabled */
	//		 | 0 << TCA_SINGLE_OVF_bp; /* Overflow Interrupt Enable: disabled */

	TCA0.SINGLE.PER = 0x9; /* Top Value: 0xa */

	TCA0.SINGLE.CTRLA = TCA_SINGLE_CLKSEL_DIV1_gc /* System Clock */
		| 1 << TCA_SINGLE_ENABLE_bp /* Module Enable: enabled */;

	return;
}