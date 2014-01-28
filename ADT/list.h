#ifndef _LIST_H
#define _LIST_H//Define _LIST_H if not defined !
/*
	DESCRIPTION:This is the ".h" file which contains all the prototypes required 
	for the ".c" file to be implemented
	AUTHOR:R R SreeKrishna
	EMAIL:krishna1994sree@gmail.com
	VERSION:1.0
*/
typedef struct node node;
typedef node *nodeptr;

struct node{
	int data;
	nodeptr next;
};

int list_push(nodeptr *,int );
void list_pop(nodeptr *);
void list_delete(nodeptr *);
int list_length(const nodeptr *);

#endif