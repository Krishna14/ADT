#include <stdio.h>
#include "list.h"
int main()
{
	nodeptr ptr = NULL;
	int choice,num;
choice:
	printf("Enter what do you want to do: ");
	scanf("%d",&choice);
	switch(choice){
		case 1: 
			printf("Enter the number to be entered");
			scanf("%d",&num);
			list_push(&ptr,num); //Again a stupid mistake. We initialize
								//pointer to the list,
								//not pointer to pointer to list.
			goto choice;
		case 2:
			printf("You want to delete the number right?");
			list_pop(&ptr);
			goto choice;
		case 3:
			printf("Delete the whole list");
			list_delete(&ptr);
			goto choice;
		case 4:
			printf("Calculating the number of elements in the list");
			int n =list_length(&ptr);
			printf("The length of the list is %d",n);
			goto choice;
		case 5:
			printf("Want to display the list\n");
			nodeptr temp = ptr;
			while(temp != NULL)
			{
				printf("%d",(temp)->data);
				printf(" -> ");
				(temp) = (temp)->next;
			}
			printf("\n");
			goto choice;
		case 6:
			printf("Quit!\n");
			break;
		default:
			printf("Wrong choice!\n");
			goto choice;
	}
	return 0;
}