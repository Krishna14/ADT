/*
	DESCRIPTION:This is the ".c" file for the ADT list.h .
	"list.h" is an attempt to implement the basic operations on a linkedlist.
	Many more functions are yet to be implemented.So stay tuned for Updates.
	AUTHOR:R R SreeKrishna
	EMAIL:krishna1994sree@gmail.com
	VERSION:1.0
*/
/* LOGIC:The Logic to be implemented is that Linked lists are structures with 
one or more piece(s) of data and a self-referential Pointer. We have used typedef
for our convenience and have tried implementing Append, Delete,Delete the whole 
list and count the number of elements in the list"
*/
//Header Files

#include <stdlib.h>
#include "list.h"

int list_push(nodeptr *ptr,int num)
{
	nodeptr temp = *ptr,temp_2;
	if(temp == NULL)
	{
		temp = (nodeptr)malloc(sizeof(node)); 
		if(temp == NULL)
			return -1; 
		else
		{
			(temp)->data = num;
			(temp)->next = NULL;
			*ptr = temp;
		}
	}
	else
	{
		for(;(temp)->next!=NULL;temp=(temp)->next)
			;
		temp_2 = (nodeptr)malloc(sizeof(node));
		temp->next = temp_2;
		temp_2->data = num;
		temp_2->next = NULL;
	}
}
void list_pop(nodeptr *ptr)
{
	nodeptr temp = *ptr;
	if(*ptr == NULL)
		return;
	else 
		if((*ptr)->next == NULL)
		{
			free (*ptr);
			*ptr == NULL; //Don't let Dangling pointers.
			return;
		}
		else
		{
			while((temp)->next->next != NULL)
			(temp) = temp->next;
		}
	free(temp->next);
	temp->next = NULL;
	return;
	
}
void list_delete(nodeptr *ptr)
{
	while(*ptr != NULL)
		list_pop(ptr);

}
int list_length(const nodeptr *ptr) //Added const, this function just counts,
									//It does not modify!
{
	nodeptr temp = *ptr;
	int count = 0;
	while(temp != NULL)
	{
		count++;
		(temp) = (temp)->next;
	}
	return count;
}


