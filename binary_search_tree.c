#include <stdio.h>
#include <stdlib.h>
struct node{
	int value;
	struct node *parent;
	struct node *left;
};
typedef struct node *binary_search_tree;

binary_search_tree initTree(int value){
	struct node *n;
	n=(struct node*)malloc(sizeof(struct node));
	n->value=value;
	n->parent=0;
	n->left=0;
	n->right=0;
	return n;
}

int isEmpty(binary_search_tree bt){
	return bt == 0;
}

struct node* getRoot(binary_search_tree bt){
	return bt;
}

struct node* getMax(binary_search_tree bt){
	if(bt->right != 0)
		return getMax(bt->right);
	else return bt;
}

struct node* getMin(binary_search_tree bt){
	if(bt->left != 0)
		return getMin(bt->left);
	else return bt;
}

void preOrther(binary_search_tree bt){
	if(bt != 0){
		printf("%d ",bt->value);
		preOrther(bt->left);
		preOrther(bt->right);
	}
}

void inOrther(binary_search_tree bt){
	if(bt != 0){
		inOrther(bt->left);
		printf("%d ",bt->value);
		inOrther(bt->right);
	}
}

void postOrther(binary_search_tree bt){
	if(bt != 0){
		postOrther(bt->left);
		postOrther(bt->right);
		printf("%d ",bt->value);
	}
}

int getValue(struct node *n, binary_search_tree bt){
	return n->value;
}

struct node* getParent(struct node *n, binary_search_tree bt){
	return n->parent;
}

struct node* getRight(struct node *n, binary_search_tree bt){
	return n->right;
}

struct node* getLeft(struct node *n, binary_search_tree bt){
	return n->left;
}

int isLeaf(struct node *n, binary_search_tree bt){
	return n->left==0 && n->right==0;
}

struct node* search(int value, binary_search_tree bt){
	if(bt != 0)
		if(bt->value < value)
			return search(value, bt->right);
		else
			if(bt->value > value)
				return search(value, bt->left);
			else return bt;
	else return 0;
}

void insert(int value, binary_search_tree bt){
	if(bt->value < value)
		if(bt->right == 0){
			struct node *n;
			n=(struct node*)malloc(sizeof(struct node));
			n->value=value;
			bt->right=n;
			n->parent=bt;
			n->left=0;
			n->right=0;
		}
		else insert(value, bt->right);
	else
		if(bt->value > value)
			if(bt->left == 0){
				struct node *n;
				n=(struct node*)malloc(sizeof(struct node));
				n->value=value;
				bt->left=n;
				n->parent=bt;
				n->left=0;
				n->right=0;
			}
			else insert(value, bt->left);
}

void deleteNode(int value, binary_search_tree bt){
	if(bt != 0)
		if(bt->value < value)
			deleteNode(value, bt->right);
		else
			if(bt->value > value)
				deleteNode(value, bt->left);
			else
				if(isLeaf(bt, bt)){
					if(getParent(bt, bt)->right != 0 && getParent(bt, bt)->right->value == value)
						getParent(bt, bt)->right=0;
					else
						if(getParent(bt, bt)->left != 0 && getParent(bt, bt)->left->value == value)
							getParent(bt, bt)->left=0;
					free(bt);
				}
				else{
					struct node *replace;
					replace=(struct node*)malloc(sizeof(struct node));
					if(bt->right != 0)
						replace=getMin(bt->right);
					else
						replace=getMax(bt->left);
					bt->value=replace->value;
					deleteNode(replace->value, replace);
				}
}

int main(){
	binary_search_tree bt;
	bt=initTree(50);
	insert(25, bt);
	insert(75, bt);
	insert(63, bt);
	insert(88, bt);
	insert(13, bt);
	insert(6, bt);
	insert(19, bt);
	insert(37, bt);
	insert(31, bt);
	insert(43, bt);
	insert(35, bt);
	insert(32, bt);
	insert(36, bt);
	preOrther(bt);printf("\n");
	deleteNode(25, bt);
	deleteNode(50, bt);
	preOrther(bt);
	return 0;
}
