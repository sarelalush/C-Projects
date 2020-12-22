#include "LinkedList.h"
#include "Queue.h"
#include <stdbool.h>
#include <stdio.h>
Element cpyInt(Element e){
	if(!e)
		return NULL;
	int* nInt = (int*)malloc(sizeof(int));
	*nInt = *((int*)e);
	return nInt;
}
void freeInt(Element e){
	free(e);
}

int main(){
	Queue q = QueueCreate(cpyInt,freeInt);
	int user_input = -1;
	int* n = NULL;
	printf("Enter Number [0 to STOP!] :");
	scanf("%d",&user_input);
	while(user_input !=0)
	{
		int* num = (int*)malloc(sizeof(int));
		*num = user_input;
		QueueEnqueue(q,num);
		printf("Enter Number [0 to STOP!] :");
		scanf("%d",&user_input);
	}
	while(!QueueIsEmpty(q))
	{
		n=QueueDequeue(q);
		printf("%d ",*n);
	}
	
}
