#include <stdio.h>
#define Max_Lenght 10

typedef int ElementType;
typedef int Position;
typedef struct{
	ElementType Element[Max_Lenght];
	int size;
}List;

void Init(List *L){
	L->size=0;
}

int Isempty(List L){
	return L.size==0;
}

int Isfull(List L){
	return L.size==Max_Lenght;
}

Position First(List L){
	return 1;
}

Position Last(List L){
	return L.size;
}

Position Previous(List L, Position P){
	return P-1;
}

Position Next(List L, Position P){
	return P+1;
}

ElementType Retrieve(List L, Position P){
	return L.Element[P-1];
}

Position Locate(List L, ElementType X){
	int i;
	for(i=0; i<L.size; i++)
		if(Retrieve(L,i+1)==X)
			break;
	return i+1;
}

void Insert(List *L, Position P, ElementType X){
	if(P<1 || P>L->size+1)
		printf("Vi tri khong hop le !\n");
	else
		if(Isfull(*L))
			printf("Danh sach day !\n");
		else{
			L->size++;
			Position Q = L->size;
			while(Q>P){
				L->Element[Q-1]=Retrieve(*L, Q-1);
				Q=Previous(*L,Q);
			}
			L->Element[Q-1]=X;
		}
}

void Delete(List *L, Position P){
	if(P<1 || P>L->size)
		printf("Vi tri khong hop le !\n");
	else
		if(Isempty(*L))
			printf("Danh sach rong !\n");
		else{
			while(P<L->size){
				L->Element[P-1]=Retrieve(*L, P+1);
				P=Next(*L,P);
			}
			L->size--;
		}
}

void Read(List *L, int n){
	if(n + L->size > Max_Lenght)
		printf("Danh sach se bi tran\n");
	else{
		int i, X;
		for(i=0; i<n; i++){
			printf("Nhap gia tri: ");scanf("%d",&X);
			Insert(L, Last(*L)+1, X);
		}
	}
}

void Print(List L){
	if(Isempty(L))
		printf("Danh sach rong khong in\n");
	else{
		Position P = First(L);
		while(P<=Last(L)){
			printf("%d ", Retrieve(L, P));
			P=Next(L, P);
		}
		printf("\n");
	}
}
