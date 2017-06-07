#ifndef _SIGNAL_HANDLING_H_
#define _SIGNAL_HANDLING_H_

#include "config.h"
#include "utility.h"
#include "signal.h"

void enable_fasync(int UARTx);
void enable_signal_uart(int UARTx);
void signal_handler_uart0(char signal);
void signal_handler_uart1(char signal);

#endif