#include "Queue.h"
#include "LinkedList.h"
#include "stdbool.h"
#include <stdlib.h>
struct Queue{
	LinkedList ll;
};

Queue QueueCreate(Element (*cpy)(Element), void (*fre)(Element)){
	Queue q = (Queue)malloc(sizeof(struct Queue));
	q->ll = LLCreate(cpy,fre);
	return q;
}
void QueueDestroy(Queue q){
	LLDestroy(q->ll);
}
void QueueEnqueue(Queue q, Element e){
	int size = LLSize(q->ll);
	LLAdd(q->ll,size,e);
}
Element QueueDequeue(Queue q){
	return LLRemove(q->ll,0);
}
bool QueueIsEmpty(Queue q){
	if(LLSize(q->ll) == 0)
		return true;
	return false;
}


