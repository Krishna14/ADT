#include <stdlib.h>
#include "list.h"

int list_push(nodeptr *ptr,int num)
{
	nodeptr temp = *ptr,temp_2;
	if(temp == NULL)
	{
		temp = (nodeptr)malloc(sizeof(node)); //Compare this line with yours :x
		if(temp == NULL)
			return -1; //Implement Error condition, return type is void, 
					//keep it int or void *
		else
		{
			(temp)->data = num;
			(temp)->next = NULL;
			*ptr = temp; //Assign *ptr as temp.
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
/*	There are three cases:
	1. *ptr is NULL
	2. (*ptr)->next is NULL
	3. (*ptr)->next->next-> ... ... ->next is NULL (The usual case)
*/  
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
	/*nodeptr temp=NULL,temp_2=NULL;
	temp = *ptr;
	temp_2 = *ptr;
	while(temp != NULL)
	{
		(temp_2) = (temp);
		(*temp) = (*temp)->next;
	}*/
//free(*temp); //What if *temp is null, here you will be freeing a NULL pointer

	// (*temp_2)->next = NULL;
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

/*PHEW*/
/*	Where are the optional pieces of code?
	Also Who is gonna write comments?
	And revise pointers!
*/
