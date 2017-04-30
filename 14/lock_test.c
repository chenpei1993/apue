#include "apue.h"
#include <fcntl.h>

pid_t lock_reg(int fd, int cmd, int type,off_t offset,int whence, off_t len)
{
	struct flock lock;
	lock.l_type=type;
	lock.l_start=offset;
	lock.l_whence=whence;
	lock.l_len=len;

	if (fcntl(fd,cmd,&lock)<0)
		err_sys("fcntl error");

	if(lock.l_type ==F_UNLCK)
		return 0;

	return (lock.l_pid);
}
