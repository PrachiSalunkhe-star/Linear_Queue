#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
	int *arr;
	int size;
	int front, rear;
}queue_t;

void queueInit(queue_t *q, int size);
void queueFree(queue_t *q);

void enqueue(queue_t *q, int value);
int dequeue(queue_t *q);
int peek(queue_t *q);

int isEmpty(queue_t *q);
int isFull(queue_t *q);

int main(void)
{
	queue_t q;
	int choice, value;

	queueInit(&q, 4);

	do{
		printf("0. Exit\n1. Enqueue\n2. Dequeue\n3. Peek\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("Enter value to be inserted : ");
				scanf("%d", &value);
				enqueue(&q, value);
				break;
			case 2:
				printf("Poped data = %d\n", dequeue(&q));
				break;

			case 3:
				printf("Peeked data = %d\n", peek(&q));
				break;
		}

	}while(choice != 0);	

	queueFree(&q);

	return 0;
}

void queueInit(queue_t *q, int size)
{
	q->size = size;
	q->arr = (int *)malloc(sizeof(int) * size);
	q->front = q->rear = -1;
}

void queueFree(queue_t *q)
{
	free(q->arr);
}

void enqueue(queue_t *q, int value)
{
	
	if(isFull(q))
		printf("Queue is full\n");
	else
	{
		
		q->rear++;
		//3. add value at rear end
		q->arr[q->rear] = value;
	}
}

int dequeue(queue_t *q)
{
	int temp = -1;

	if(isEmpty(q))
		printf("Queue is empty\n");
	else{
		temp = q->arr[q->front + 1];
		q->front++;
		if(q->front == q->rear)
			q->front = q->rear = -1;
	}
	return temp;
}

int peek(queue_t *q)
{
	int temp = -1;
	if(isEmpty(q))
		printf("Queue is empty\n");
	else{
		
		temp = q->arr[q->front + 1];
	}
	return temp;
}

int isEmpty(queue_t *q)
{
	return q->front == q->rear;
}

int isFull(queue_t *q)
{
	return q->rear == q->size - 1;
}










