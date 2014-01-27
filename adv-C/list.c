#include <stdlib.h>
#include "list.h"

void list_push(nodeptr *ptr,int num)
{
	nodeptr temp = *ptr;
	if(temp == NULL){
		temp = (nodeptr)malloc(sizeof(node)); //Compare this line with yours :x
		if(temp == NULL)
			return; //Implement Error condition, return type is void, 
					//keep it int or void *
		else{
			(temp)->data = num;
			(temp)->next = NULL;
			*ptr = temp; //Assign *ptr as temp.
		}
	}
	else{
		(temp) = (temp)->next;
		list_push(&temp,num); //Ever thought Why recursion is not used here?
								//I'll discuss in class remind me!
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
	else if((*ptr)->next == NULL){
		free (*ptr);
		*ptr == NULL; //Don't let Dangling pointers.
		return;
	}
	else{
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
	//nodeptr *temp=NULL; //Why are you using double indirection?
						//Use only when its really necessary!
	/*while(*ptr !=NULL)
	{
		(*temp) = (*ptr)->next;
		free(*ptr);
	}*/ //This was _/\_ Logic! :x Save pointers, you are freeing NULLs too
	
	//Use this >>
	while(*ptr != NULL)
		list_pop(ptr);

}
int list_length(const nodeptr *ptr) //Added const, this function just counts,
									//It does not modify!
{
	//nodeptr *temp=NULL; //Again Double Indirection! Show off!
	nodeptr temp = *ptr;
	//*temp = *ptr; //Stupid, A pointer first points to an initialized memory.
	              //is there any memory where temp is pointing?
				  //temp has to point somewhere first!
	//temp = ptr //Legal
	//*temp = *ptr //Illegal, No memory at *temp!
	int count = 0;
	while(temp != NULL){
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