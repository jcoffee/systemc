/*
 * Uart_16450.h
 *
 *  Created on: Jun 24, 2015
 *      Author: quytq1
 */

#ifndef PERIPHERALS_JC_REUSE_UART_16450_UART_H_
#define PERIPHERALS_JC_REUSE_UART_16450_UART_H_

#include <stdio.h>

// makefile include path: "${IMPERAS_HOME}/ImperasLib/source"
// Add uart_16450: ARM 16450
#define UART1_BASE 0x49000000


#define UART1_RBR 0
#define UART1_TBR 0
#define UART1_IER 1
#define UART1_IIR 2
#define UART1_LCR 3
#define UART1_MCR 4
#define UART1_LSR 5
#define UART1_MSR 6
#define UART1_SCR 7

#define UART1_IER_THRI   0x02    /* Enable Transmitter holding register int. */
#define UART1_IER_RDI    0x01    /* Enable receiver data interrupt */
#define UART1_IIR_THRI   0x02    /* Transmitter holding register empty */
#define UART1_IIR_RDI    0x04    /* Receiver data interrupt */
#define UART1_LSR_TEMT   0x40    /* Transmitter empty */
#define UART1_LSR_THRE   0x20    /* Transmit-hold-register empty */
#define UART1_LSR_DR     0x01    /* Receiver data ready */


namespace jc_reuse {
namespace uart_16450 {

class uart {
public:
	uart();
	~uart();



	// Add timer0
	static void enable();

	static void sendString(const char* string);

	static void demo();

};

} /* namespace uart_16450 */
} /* namespace flsi_reuse */


#endif /* PERIPHERALS_JC_REUSE_UART_16450_UART_H_ */
