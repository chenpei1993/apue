#include "apue.h"

static void sig_usr(int);

int main(void)
{
	if(signal(SIGUSR1,sig_usr)==SIG_ERR){
		err_sys("can't catch SIGUSR1");
	}

	if(signal(SIGUSR2,sig_usr)==SIG_ERR){
		err_sys("can't catch SIGUSR1");
	}

	for(;;){
		pause();
	}
}

static void sig_usr(int signo)
{
	if(signo==SIGUSR1){
		printf("received SIGUSR1\n");
	}else if(signo==SIGUSR1){
		printf("received SIGUSR1\n");
	}else{
		err_dump("recevied signal %d\n",signo);
	}
}


