#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int data;
	struct stack *next;
};

struct stack *top=NULL;		//global declaration

void push();
void pop();
void printStack();

//Driver code
int main()
{
	int choice;
	char decision;
	
	do
	{
		system("cls");
		printf("\n			MENU");
		printf("\n	1. Push");
		printf("\n	2. Pop");
		printf("\n	3. Print stack");
		printf("\n\nEnter your choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				printStack();
				break;
			default :
				printf("\nInvalid Input");
				break;
		}
		printf("\nDo you want to continue? (Y/N) : ");
		scanf("%s",&decision);
	}while((decision=='Y')||(decision=='y'));
	return 0;
}

void push()
{
	struct stack *ptr;
	ptr = (struct stack*)malloc(sizeof(struct stack));		//allocate memory
	
	if(ptr==NULL)		//check if the stack is full
	{
		printf("\nStack is overflow");
		exit(1);		//abnormal termination of the program
	}
	printf("\nEnter the value : ");
	scanf("%d",&ptr->data);
	ptr->next=NULL;
	ptr->next=top;
	top=ptr;
}

void pop()
{
	struct stack *curr;
	curr=top;
	if(top==NULL)		//check if the stack is full
	{
		printf("\nThe stack is underflow");
		exit(1);
	}
	top=top->next;		//make the next node as the top
	printf("\n%d is successfully deleted",curr->data);
	free(curr);
	
}

void printStack()
{
	struct stack *temp;
	temp=top;
	while(temp->next!=NULL)		//traverse through the nodes
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("\n%d->NULL",temp->data);
	printf("\n %d is the top element",top->data);
}
