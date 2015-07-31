/*
 * Timer.cpp
 *
 *  Created on: Jun 23, 2015
 *      Author: cuongph8
 */

#include "../../jc_reuse/timer_arm_sp804/Timer.h"

namespace jc_reuse {
namespace timer_arm_sp804 {

Timer::Timer() {
	// TODO Auto-generated constructor stub

}

Timer::~Timer() {
	// TODO Auto-generated destructor stub
}


// Add timer0
void Timer::timer0_init() {

    *(volatile unsigned int *)(BPORT1_AB_T0LOAD) = 0xFFFF;
    *(volatile char *)(BPORT1_AB_T0CONTROL) = (0
						| BPORT1_AB_T0CONTROL_DIV
						| BPORT1_AB_T0CONTROL_IE
						| BPORT1_AB_T0CONTROL_PERIODIC
						| BPORT1_AB_T0CONTROL_ENABLE);
}

void Timer::timer1_init() {

    *(volatile unsigned int *)(BPORT1_AB_T1LOAD) = 0xfff;
    *(volatile char *)(BPORT1_AB_T1CONTROL) = (0
						| BPORT1_AB_T1CONTROL_DIV
						| BPORT1_AB_T1CONTROL_IE
						| BPORT1_AB_T1CONTROL_ENABLE);
}



void Timer::demo() {

	printf("Starting Timer 0\n");
	timer0_init();
	timer1_init();

	int i;

	for (i = 0; i < 2; i++) {
		while (    ((*(volatile int *) (BPORT1_AB_T0RIS)) == 0)
				&& ((*(volatile int *) (BPORT1_AB_T1RIS)) == 0)) {
			printf("Wait for interrupting\n");
			printf("Current Value of Timer 0 is %0x\n", *(volatile int *) (BPORT1_AB_T0VALUE));
			printf("Current Value of Timer 1 is %0x\n", *(volatile int *) (BPORT1_AB_T1VALUE));
		}
		printf("Interrupt is detected!\n");
	}

}



} /* namespace timer_arm_sp804 */
} /* namespace flsi_reuse */

