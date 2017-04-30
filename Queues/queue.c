#include <stdio.h>
#define CAPACITY 6
typedef struct queue
{
	int array[CAPACITY];
	int front;
	int size;
} queue;

void enqueue(queue *q, int value);
void printQ(queue *q);
int dequeue(queue *q);

int main(void)
{
	queue q;
	q.front = 0;
	q.size = 0;
	enqueue(&q, 5);
	enqueue(&q, 10);
	enqueue(&q, 7);
	enqueue(&q, 12);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	enqueue(&q, 53);
	enqueue(&q, 15);
	enqueue(&q, 81);
	printQ(&q);
	printf("\n");
}

void enqueue(queue *q, int value)
{
	if (q->size < CAPACITY)
	{
		if ((q->front + q->size) >= CAPACITY)
		{
			q->array[(q->front + q->size) % CAPACITY] = value;
		}
		else
			q->array[(q->front + q->size)] = value;	
		q->size++;
	}
}

int dequeue(queue *q)
{
	int tmp = q->array[q->front];
	q->front++;
	q->size--;
	return tmp;
}

void printQ(queue *q)
{
	int end = q->size + q->front;
	for (int i = q->front; i < end; i++)
	{
		if (i >= CAPACITY)
			printf("%d ", q->array[i % CAPACITY]);
		else
			printf("%d ", q->array[i]);
	}
}
