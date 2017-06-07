#include "config.h"

const char *dev_name_uart0 = "/dev/ttyS1";
const char *dev_name_uart1 = "/dev/ttyS2";

int config_uart(int UARTx , long baurate)
{
	struct termios config;
	switch(UARTx){
		case 0:
			fd0= open(dev_name_uart0, O_RDWR | O_NOCTTY | O_NDELAY);
			if(fd0 == -1){
				printf("-E- can not open dev uart 0");
				return -1;
			}
			if(!isatty(fd0)){
				printf("-E- UART not open!!");
				return -1;
			}
			if(tcgetattr(fd0,&config)<0){
				printf("-E- cannot get current config");
			}	
		break;
		case 1:
			fd1 = open(dev_name_uart1, O_RDWR | O_NOCTTY | O_NDELAY);
			if(fd1== -1){
				printf("-E- can not open dev uart1");
				return -1;
			}
			if(!isatty(fd1)){
				printf("-E- UART not open!!");
				return -1;
			}
			if(tcgetattr(fd1,&config)<0){
				printf("-E- cannot get current config");
			}	
		break;
		default:
		break;
	}
	
	config.c_iflag &= ~(IGNBRK | BRKINT | ICRNL | INLCR |
	PARMRK | INPCK | ISTRIP | IXON);
	config.c_oflag = 0;
	config.c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN | ISIG);
	config.c_cflag &= ~(CSIZE | PARENB);
	config.c_cflag |= CS8;
	config.c_cc[VMIN] = 1;
	config.c_cc[VTIME] = 0;
	
	switch(baurate){
		case 9600:
			if (cfsetispeed (&config, B9600) < 0 || cfsetospeed (&config, B9600) < 0){
				printf ("-E- cannot set baudrate \r\n");
				return -1;
			}
		break;
		case 115200:
			if (cfsetispeed (&config, B115200) < 0 || cfsetospeed (&config, B115200) < 0){
				printf ("-E- cannot set baudrate \r\n");
				return -1;
			}

	}
	switch(UARTx){
		case 0:
			if (tcsetattr (fd0, TCSAFLUSH, &config) < 0){
				printf ("-E- config failed \r\n");
				return -1;
			}
		break;
		case 1:
			if (tcsetattr (fd1, TCSAFLUSH, &config) < 0){
				printf ("-E- config failed \r\n");
				return -1;
			}
		break;
		default:
		break;
    }
	printf ("-I- config success \r\n");
	return 0;
}