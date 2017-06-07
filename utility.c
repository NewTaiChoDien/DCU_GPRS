#include  "utility.h"

void uart_send_data(int UARTx,char *data_send){
	switch(UARTx){
		case 0:
			write(fd0,data_send,strlen(data_send));
		break;
		case 1:
			write(fd1,data_send,strlen(data_send));	
		break;
		default:
		break;
	}
}
void uart_recv_data(int UARTx, char *data_recv){
	switch(UARTx){
		case 0:
			read(fd0,data_recv,BUFFSIZE);
		break;
		case 1:
			read(fd1,data_recv,BUFFSIZE);
		break;
		default:
		break;
	}
}
