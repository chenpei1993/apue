#include <pthread.h>
#include <stdlib.h>

struct job{
	struct job *j_next;
	struct job *j_prev;
	pthread_t j_id;
}

struct queue{
	struct job *q_head;
	struct job *q_tail;
	pthread_rwlock_t q_lock;
}


int queue_init(struct queue *qp)
{
	int err;
	qp->head=NULL;
	qp->tail=NULL;
	err=pthread_rwlock_init(&qp->q_lock,NULL);
	
	if(err!=0)
		return err;
	return(0);
}


void job_insert(struct queue *qp,struct job *jp)
{
	pthread_rwlock_wrlock(&qp->q_lock);
	jp->j_next=qp->q_head;
	jp->j_prev=NULL;
	if(qp->head!=NULL)
		qp->q_head
}
