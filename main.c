#include "config.h"
#include "utility.h"
#include "signal_handling.h"
char str[]="huy";
extern int x;
extern char uart_buff_recv[BUFFSIZE];
int main(){
	/* creat signal for uart */
	enable_signal_uart(UART1);
	config_uart(UART1,9600);
	enable_fasync(UART1);
	sleep(5);
	printf("%s\r\n",uart_buff_recv);
	while(1)
	{
		usleep(100);
	}
    close (fd1);
	return 0;

}
void clear_buff(char *buff){
	int i;
	for(i=0;i<BUFFSIZE;i++){
		buff[i]='0';
	}
}