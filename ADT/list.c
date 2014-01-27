#include <stdlib.h>
#include "list.h"

void list_push(nodeptr *ptr,int num)
{
	nodeptr *temp = NULL;
	if(*ptr == NULL)
	{
		temp = (nodeptr *)malloc(sizeof(node));
		if(*temp == NULL)
			return;
		else
		{
			(*temp)->data = num;
			(*temp)->next = NULL;
		}
	}
	else
	{
		(*temp) = (*temp)->next;
		list_push(temp,num);
	}
}
void list_pop(nodeptr *ptr)
{
	nodeptr *temp=NULL,*temp_2=NULL;
	(*temp) = (*ptr);
	(*temp_2) = (*ptr);
	while(*temp != NULL)
	{
		(*temp_2) = (*temp);
		(*temp) = (*temp)->next;
	}
	free(*temp);
	(*temp_2)->next = NULL;
}
void list_delete(nodeptr *ptr)
{
	nodeptr *temp=NULL;
	while(*ptr !=NULL)
	{
		(*temp) = (*ptr)->next;
		free(*ptr);
	}
}
int list_length(nodeptr *ptr)
{
	nodeptr *temp=NULL;
	*temp = *ptr;
	int count = 0;
	while(*temp != NULL)
	{
		count++;
		(*temp) = (*temp)->next;
	}
	return count;
}