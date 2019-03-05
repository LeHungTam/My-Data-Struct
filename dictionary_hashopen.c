#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int masach;
	char tensach[30];
}sach;

struct node{
	sach *s;
	struct node *next;
};

typedef struct node *bucket;
typedef bucket *Dictionary;

int hash(int x){
	return x%7;
}

void initSet(Dictionary *d){
	(*d)=(Dictionary)malloc(sizeof(bucket)*8);
	int i;
	for(i=0; i<8; i++){
		*(*d + i)=0;
	}
}

int search(int masach, Dictionary d){
	int ma=hash(masach);
	struct node *tmp;
	tmp=*(d+ma);
	if(tmp == 0)
		return 0;
	else{
		while(tmp != 0){
			if(tmp->s->masach == masach)
				return 1;
			tmp=tmp->next;
		}
		return 0;
	}
}

void insert(sach s, Dictionary d){
	if(!search(s.masach, d)){
		int value=hash(s.masach);
		struct node *tmp;
		tmp=(struct node*)malloc(sizeof(struct node));
		tmp->s=(sach*)malloc(sizeof(sach));
		tmp->s->masach=s.masach;
		strcpy(tmp->s->tensach, s.tensach);
		tmp->next=*(d+value);
		*(d+value)=tmp;
	}
}

void deleteSet(sach s, Dictionary d){
	if(search(s.masach, d)){
		int value=hash(s.masach);
		struct node *tmp;
		tmp=*(d+value);
		if(tmp->s->masach == s.masach){
			*(d+value)=tmp->next;
			free(tmp);
		}
		else{
			while(tmp->next->s->masach != s.masach)
				tmp=tmp->next;
			struct node *tmp1;
			tmp1=tmp->next;
			tmp->next=tmp1->next;
			free(tmp1);
		}
	}
}

void viewMenu(Dictionary d){
	int i;
	struct node *tmp;
	for(i=0; i<8; i++){
		tmp=*(d+i);
		while(tmp!=0){
			printf("%s \t %d\n",tmp->s->tensach, tmp->s->masach);
			tmp=tmp->next;
		}
	}
}
