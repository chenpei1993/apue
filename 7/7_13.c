#include "apue.h"
#include <setjmp.h>

static void f1(int,int,int,int);

static void f2(void);

static jmp_buf jmpbuffer;
static int globval;

int main(void)
{
	int autoval;
	register int regival;
	volatile volaval;
	static int statval;


	globval=1;
	autoval=2;
	regival=3;
	volaval=4;
	statval=5;
	int num=setjmp(jmpbuffer);
	if(num!=0){
		printf("after longkmp:\n");
		printf("globval=%d,autoval=%d,regival=%d,volaval=%d,statval=%d",globval,autoval,regival,volaval,statval);
		if(num==2){
			printf("2");
		}
		exit(0);
	}
	
	globval=95;
	autoval=96;
	regival=97;
	volaval=98;
	statval=99;

	f1(autoval,regival,volaval,statval);
	exit(0);
}



static void f1(int i,int j,int k,int l)
{
	printf("in f1: \n");
	printf("globval=%d,autoval=%d,regival=%d,volaval=%d,statval=%d\n",globval,i,j,k,l);
	f2();
}

static void f2(void)
{
	longjmp(jmpbuffer,2);
}
















