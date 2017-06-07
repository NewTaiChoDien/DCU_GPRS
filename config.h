#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "stdio.h"
#include "string.h"
#include "errno.h"
#include "termios.h"
#include "unistd.h"
#include "fcntl.h"

#define UART0     0
#define UART1     1
int fd0,fd1;
int config_uart(int UARTx , long baurate);
#endif
