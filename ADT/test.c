#include <stdio.h>
#include "list.h"
int main()
{
	nodeptr *ptr = NULL;
	int choice,num;
	printf("Enter what do you want to do");
	scanf("%d",&choice);
	switch(choice){
		case 1: 
			printf("Enter the number to be entered");
			scanf("%d",&num);
			list_push(ptr,num);
			break;
		case 2:
			printf("You want to delete the number right?");
			list_pop(ptr);
			break;
		case 3:
			printf("Delete the whole list");
			list_delete(ptr);
			break;
		case 4:
			printf("Calculating the number of elements in the list");
			int n =list_length(ptr);
			printf("The length of the list is %d",n);
			break;
		case 5:
			printf("Want to display the list");
			while(ptr != NULL)
			{
				printf("%d",(*ptr)->data);
				printf(" -> ");
				(*ptr) = (*ptr)->next;
			}
			break;
	}
	return 0;
}