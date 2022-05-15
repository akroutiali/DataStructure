#include<stdio.h>
#include<stdlib.h>
struct queue {
int front,rear,capacity,size;
int *array;
};

struct queue*createQueue(int capacity)
{
	struct queue*q=(struct queue*)malloc(sizeof(struct queue));
	q->array=(int*)malloc(sizeof(int)*capacity);
	q->size=0;
	q->capacity=capacity;
	q->rear=0;
}

int  isfull(struct queue*q)
{
   if(q->size==q->capacity)
	   return 1;
   return 0;
   
}
int  isempty(struct queue*q)
{
	if(q->size==0)
		return 1 ;
	return 0;
}


void enqueue(struct queue*q,int element)
{
  if (isfull(q))
  {
	  printf("queue overflow \n");
	  return ;
  }
  q->array[q->rear]=element;
  q->rear+=1;
  q->size++;

}
void dequeue(struct queue*q )
{
	if(isempty(q))
	{
		printf("the queue is empty");
	}
	int element=q->array[q->front];
	q->front=q->front+1;
	q->size=q->size-1;
	printf("the value %d is dequeued from the queue",element);
}
int front(struct queue *q)
{
	if(isempty(q))
		return 0;
	return q->array[q->front];

}
int rear(struct queue*q)
{
	if(isempty(q))
		return 0;
	return q->array[q->rear-1];
}
int main()
{
struct queue*q=createQueue(10);
enqueue(q,1);
enqueue(q,2);
enqueue(q,3);
dequeue(q);
printf("front===%d",front(q));
printf("rear==%d",rear(q));

}
