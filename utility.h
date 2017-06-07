#ifndef _UTILITY_H_
#define _UTILITY_H_

#include "config.h"

#define BUFFSIZE  1000
void uart_send_data(int UARTx,char *data_send);
void uart_recv_data(int UARTx, char *data_recv);
#endif