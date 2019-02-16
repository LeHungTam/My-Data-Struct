#include <stdio.h>
#include <stdlib.h>

typedef int keytype;
struct node{
	keytype key;
	struct node *next;
};
typedef struct node *position;
typedef struct node *list;

void init(list *l){
	(*l)=(struct node*)malloc(sizeof(struct node));
	(*l)->next=00000000;
}

int isempty(list l){
	return l->next==00000000;
}

int count(list l){
	int count=0;
	position p;
	p = (struct node*)malloc(sizeof(struct node));
	p=l;
	while(p->next!=00000000){
		count++;
		p=p->next;
	}
	return count;
}

void insertfirst(list l, keytype x){
	position p;
	p = (struct node*)malloc(sizeof(struct node));
	p->next = l->next;
	l->next = p;
	p->key = x;
}

void insertlast(list l, keytype x){
	position p, q;
	p = (struct node*)malloc(sizeof(struct node));
	q = (struct node*)malloc(sizeof(struct node));
	p = l;
	while(p->next!=00000000)
		p = p->next;
	q->next = p->next;
	p->next = q;
	q->key = x;
}

void insert(list l, int index, keytype x){
	if(index < 1 || index > count(l)+1)
		printf("Insert sai vi tri !\n");
	else
		if(index==1)
			insertfirst(l, x);
		else
			if(index==count(l)+1)
				insertlast(l, x);
			else{
				int dem = 1;
				position p, q;
				p = (struct node*)malloc(sizeof(struct node));
				q = (struct node*)malloc(sizeof(struct node));
				p = l;
				while(dem!=index){
					dem++;
					p = p->next;
				}
				q->next = p->next;
				p->next = q;
				q->key = x;
			}
}

void deletefirst(list l){
	if(isempty(l))
		printf("Danh sach rong khong the xoa !\n");
	else{
		position p;
		p = (struct node*)malloc(sizeof(struct node));
		p = l->next;
		l->next = p->next;
		free(p);
	}
}

void delete(list l, int index){
	if(isempty(l))
		printf("Danh sach rong khong xoa !\n");
	else
		if(index==1)
			deletefirst(l);
		else{
			int dem = 1;
			position p, q;
			p = (struct node*)malloc(sizeof(struct node));
			q = (struct node*)malloc(sizeof(struct node));
			p = l;
			while(dem!=index){
				dem++;
				p = p->next;
			}
			q = p->next;
			p->next = q->next;
			free(q);
		}
}

void read(list l, int n){
	int i;
	keytype x;
	for(i=0; i<n; i++){
		printf("Nhap gia tri: ");scanf("%d",&x);
		insertlast(l, x);
	}
}

void print(list l){
	if(isempty(l))
		printf("Danh sach rong !\n");
	else{
		position p;
		p = l;
		while(p->next!=00000000){
			printf("%d ",p->next->key);
			p = p->next;
		}
	}
}
