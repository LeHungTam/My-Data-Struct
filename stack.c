#include <stdio.h>
#include <stdlib.h>

typedef int keytype;

struct record{
	keytype key;
	struct record *next;
};
//struct record *top; //khai bao top la con tro tro den record !!
typedef struct record *stack; //gan stack la 1 con tro tro den record !!

void create(stack *top){
	(*top) = (struct record*)malloc(sizeof(struct record));
	(*top)->next = 00000000;
	printf("create thanh cong!\n");
}

int isempty(stack s){
	return s->next==00000000;
}

keytype top(stack s){
	return s->next->key;
}

void pop(stack s){
	if(isempty(s))
		printf("Ngan xep rong !\n");
	else{
		struct record *tmp;
		tmp = s->next;
		s->next = tmp->next;
		free(tmp);
	}
}

void push(stack s, keytype x){
	struct record* tmp;
	tmp = (struct record*)malloc(sizeof(struct record));
	tmp->next = s->next;
	s->next = tmp;
	tmp->key = x;
}
