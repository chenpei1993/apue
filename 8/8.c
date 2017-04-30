/*子子孙孙无穷无尽*/
#include "apue.h"
#include <sys/wait.h>
int main(void)
{
	pid_t pid;
	if((pid=fork())<0){
		err_sys("fork error");	
	}else if(pid != 0){
		printf("-----------------------------------\n");
		printf("parent my uid=%d\n",getpid());
	}else if(pid == 0){
		printf("-----------------------------------\n");
		sleep(2);
		printf("i am frist child my uid=%d ,my parent uid=%d\n",getpid(),getppid());
	}

	
	if((pid=fork())<0){
		err_sys("fork error");	
	}else if(pid == 0){
		sleep(4);
		printf("-----------------------------------\n");
		printf("child my uid=%d ,my parent uid=%d\n",getpid(),getppid());
	}else if (pid !=0){
		printf("myself uid=%d ,my parent uid=%d\n",getpid(),getppid());
	}
	
		if((pid=fork())<0){
		err_sys("fork error");	
	}else if(pid == 0){
		printf("who is my parent my uid=%d ,my parent uid=%d\n",getpid(),getppid());
	}
	
	if(waitpid(pid,NULL,WNOHANG)<0)
		err_sys("waitpid error");
	exit(0);

	
	
}
