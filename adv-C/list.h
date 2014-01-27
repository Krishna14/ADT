#ifndef _LIST_H
#define _LIST_H//Define _LIST_H if not defined !

typedef struct node node;
typedef node *nodeptr;

struct node{
	int data;
	nodeptr next;
};

void list_push(nodeptr *,int );
void list_pop(nodeptr *);
void list_delete(nodeptr *);
int list_length(const nodeptr *);

#endif