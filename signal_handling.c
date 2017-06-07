#include "signal_handling.h"
extern char uart_buff_recv[BUFFSIZE];

void enable_fasync(int UARTx){
	if(UARTx == 0){
		fcntl (fd0, F_SETOWN, getpid());
		fcntl (fd0, F_SETFL, fcntl(fd0, F_GETFL) | FASYNC);
	}
	if(UARTx == 1){
		fcntl (fd1, F_SETOWN, getpid());
		fcntl (fd1, F_SETFL, fcntl(fd1, F_GETFL) | FASYNC);
	}
}
void enable_signal_uart(int UARTx){
	struct sigaction action;
	memset (&action, 0, sizeof (action)); 
	if(UARTx==0) action.sa_handler = signal_handler_uart0; 
	if(UARTx==1) action.sa_handler = signal_handler_uart1; 
	action.sa_flags = 0; 
	sigaction (SIGIO, &action, NULL);
}
void signal_handler_uart0(char signal){
 	if(signal == SIGIO){
 			uart_recv_data(UART0,uart_buff_recv);
 			tcflush (fd0, TCIOFLUSH);
 	}
}
void signal_handler_uart1(char signal){
 	if(signal == SIGIO){
 			uart_recv_data(UART1,uart_buff_recv);
 			tcflush (fd1, TCIOFLUSH);
 	}
}
