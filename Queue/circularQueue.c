#include <stdio.h>

struct cQueue {
	int Front,rear,size,capacity;
	int *tab;
};

typedef struct cQueue circularQueue;
struct circularQueue* CircularQueue(int capacity) {
	circularQueue*cqueue=(circularQueue*)malloc(sizeof(circularQueue));
	cqueue->Front=-1;
	cqueue->rear=0 ;
	cqueue->size=capacity;
	cqueue->tab=(int*)malloc(sizeof(int)*capacity);
	return cqueue;
}
int isFull(circularQueue*cqueue)
{
	if((cqueue->rear+1 == cqueue->Front)|| (cqueue->rear==cqueue->size -1 && cqueue->Front ==0))
			return 1;
	return 0;
}
int isempty(circularQueue*cqueue)
{
        if (cqueue == NULL)
	return;
	return (cqueue->Front==-1);
}
void enqueue(circularQueue*cqueue,int element)
{
        if (cqueue == NULL)
	return;
	if(isFull(cqueue))
	{
	   printf("CQUEUE is FULL\n");
	}
	else 
	{
	if(cqueue->Front==-1)
	cqueue->Front=0;
	cqueue->tab[cqueue->rear]=element;
	cqueue->rear=cqueue->rear+1;
	printf("Inserted elment %d\n",element);
}
}

void dequeue(circularQueue*cqueue)
{
	if(cqueue ==NULL)
		return;
	if(isempty(cqueue))
	{
		printf("Queue is empty \n");
	}
	else
	{
		if(cqueue->Front ==cqueue->rear)
		{
			cqueue->Front=-1;
			cqueue->rear=0;
		}
	   int element =cqueue->tab[cqueue->Front];
	   cqueue->Front=cqueue->Front+1;
	   printf("element %d is dequeued\n",element);
	}
}
void printQueue(circularQueue*cqueue)
{
	if(cqueue == NULL)
		return;
	int start=cqueue->Front;
	int end=cqueue->rear;
	printf("the elment of the queue are :\n");
	while(start<=end)
	{
		printf("%d\n",cqueue->tab[start]);
		start=start+1;
	}
}
int main()
{
	circularQueue*cqueue;
        cqueue=CircularQueue(5);
	enqueue(cqueue,1);
	enqueue(cqueue,2);
        enqueue(cqueue,3);
        enqueue(cqueue,4);
	dequeue(cqueue);
	enqueue(cqueue,5);
	enqueue(cqueue,6);
	return 0;

}
