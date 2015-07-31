/*
 * Uart_16450.cpp
 *
 *  Created on: Jun 24, 2015
 *      Author: quytq1
 */

#include "../../jc_reuse/uart_16450/Uart.h"
#include <iostream>
using std::cout;
using std::endl;

namespace jc_reuse {
namespace uart_16450 {

uart::uart() {
	// TODO Auto-generated constructor stub

}

uart::~uart() {
	// TODO Auto-generated destructor stub
}


// Add timer0
void uart::enable() {
	cout << "uart_16450: Enabled!" << endl;

	// enable with no interrupts
	*(volatile char *) (UART1_BASE + UART1_IER) = 0; //(UART1_IER_THRI | UART1_IER_RDI );
}

void uart::sendString(const char* string) {
	char * out = (char *) string;
	cout << "uart_16450: Send String" << endl;

	while (*out != 0) {
		unsigned int retry = 100;
		while (retry--) {
			char lsr;
			if ((lsr = *(volatile char *) (UART1_BASE + UART1_LSR))
					& (UART1_LSR_TEMT | UART1_LSR_THRE)) {
				// Transmit buffer empty
				break;
			}
			cout << "uart_16450: LSR: 0x" << std::hex << lsr << endl;
		}
		cout << "uart_l16450: send char " << *out << " (0x" << std::hex << *out <<")" << endl;
		*(volatile char *) (UART1_BASE + UART1_TBR) = *out;
		out++;
	}
}



void uart::demo() {
	cout << "uart_16450: start send data" << endl;
	enable();
	cout << "uart_16450: send string" << endl;
	sendString("UART_16450 Sending String\n");
	cout << "uart_16450: sent" << endl;
}




} /* namespace uart_16540 */
} /* namespace flsi_reuse */
