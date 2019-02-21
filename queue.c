#include <stdio.h>
#include <stdlib.h>

struct element{
	int value;
	struct element *next;
};
struct queue{
	struct element *front;
	struct element *rear;
};

void init(struct queue *q){
	(*q).front = (struct element*)malloc(sizeof(struct element));
	(*q).rear = (struct element*)malloc(sizeof(struct element));
	(*q).front = 00000000;
	(*q).rear = 00000000;
}

int isempty(struct queue q){
	return q.front == 00000000 || q.rear == 00000000;
}

int front(struct queue q){
	return q.front->value;
}

void enqueue(struct queue *q, int value){
	if(isempty(*q)){
		struct element *p;
		p = (struct element*)malloc(sizeof(struct element));
		p->value = value;
		p->next = (*q).rear;
		(*q).rear = p;
		(*q).front = p;
	}
	else{
		struct element *p;
		p = (struct element*)malloc(sizeof(struct element));
		p->value = value;
		p->next = (*q).rear->next;
		(*q).rear->next = p;
		(*q).rear = p;
	}
}

void dequeue(struct queue *q){
	if((*q).front == (*q).rear){
		struct element *p;
		p = (struct element*)malloc(sizeof(struct element));
		p = (*q).front;
		(*q).front = 00000000;
		(*q).rear = 00000000;
		free(p);
	}
	else{
		struct element *p;
		p = (struct element*)malloc(sizeof(struct element));
		p = (*q).front;
		(*q).front = p->next;
		free(p);
	}
}
