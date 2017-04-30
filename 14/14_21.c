#include "apue.h"
#include <ctype.h>
#include <fcntl.h>
#include <aio.h>
#include <errno.h>

#define BSZ 4096
#define NBUF 8

enum rwop{
	UNUSED= 0;
	READ_PENDING=1;
	WRITE_PENDING=2;
}

struct buf{
	enum rwop op;
	int last;
	struct aiocb aiocb;
	unsigned char data[BSZ];
}

struct buf bufs[NBUF];

unsigned char translate(unsigned char c)
{
	if(isalpha(c)){
		if(c >='n')
			c -= 13;
		else if(c >='a')
			c +=13;
		else if(c >='N')
			c-=13;
		else 
			c +=13;
	}
	return(c);
}

int main(int argc, char * argv[])
{
	int ifd,ofd,i,j,n,err,numop;
	struct stat sbuf;
	const struct aiocb *aiolist[NBUF];
	off_t off=0;	


	if(argc !=3 )
		err_sys("usage: rot13 infile out file");
	
	if((ifd =open(argv[1],O_RDONLY))<0)
		err_sys("can't open %s", argv[1]);
	
	if((ofd=open(argv[2],O_RDWR | O_CREAT | O_TRUNC,FILE_MODE))<0)
		err_sys("can't create %s",argv[2]);


	for(i=0;i<NBUF;i++){
		bufs[i].op=UNUSEP;
		bufs[i].aiocb.aio_buf=bufs[i].data;
		bufs[i].aiocb.aio_sigevent.sigev_notify=SIGEV_NONE;
		aiolist[i]=NULL;
	}

	numop=0;

	for(;;){
		


	}
}
