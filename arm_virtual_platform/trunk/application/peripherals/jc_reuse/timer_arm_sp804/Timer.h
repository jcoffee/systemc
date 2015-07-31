/*
 * Timer.h
 *
 *  Created on: Jun 23, 2015
 *      Author: cuongph8
 */

#ifndef PERIPHERALS_FLSI_REUSE_TIMER_H_
#define PERIPHERALS_FLSI_REUSE_TIMER_H_

#include <stdio.h>

// makefile include path: "${IMPERAS_HOME}/ImperasLib/source"
// Add timer0: ARM TimerSP804
#define BPORT1 0x49300000

// #include "/opt/Imperas.20150205/ImperasLib/source/arm.ovpworld.org/peripheral/TimerSP804/1.0/pse/pse.macros.igen.h"
#include <arm.ovpworld.org/peripheral/TimerSP804/1.0/pse/pse.macros.igen.h>


namespace jc_reuse {
namespace timer_arm_sp804 {

class Timer {
public:
	Timer();
	~Timer();



	// Add timer0
	static void timer0_init();

	static void timer1_init();

	static void demo();

};

} /* namespace timer_arm_sp804 */
} /* namespace flsi_reuse */


#endif /* PERIPHERALS_FLSI_REUSE_TIMER_H_ */
