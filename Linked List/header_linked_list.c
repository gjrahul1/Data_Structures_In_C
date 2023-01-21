#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

int i;

struct node *head=NULL;
struct node *ptr;
int create_list(int size)
{
	for(i=0; i<size; i++)
	{
	printf("\n Enter the elements to be entered at node %d \t",i+1);
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	scanf("%d",&newnode->data);
	newnode->link=NULL;
	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->link=newnode;
	}
	else
	{
		ptr=head;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
			ptr->link=newnode;
	}
}
}
void display(int recieve)
{
	printf("\n *** HEADER LINKED LIST *** \n");
	for(i=0; i<recieve+1; i++)
	{
		if(head==NULL)
		{
			printf("Linked List is empty \n");
		}
		else
		{
			printf("%d->",head->data);
			head=head->link;
		}
	}
}

int main()
{
	int choice,size;
	    while(1)
	    {
	printf("\n *** THIS IS AN SIMPLE HEADER LINKED LIST  *** \n");
	printf("1. Create linked list \n 2.Display \n 0.Exit \n");
	printf("Enter your choice \n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		printf("Enter the size of linked list \t");
		scanf("%d",&size);
		create_list(size);
		break;

		case 2:
		display(size);
		break;

		case 0:
		exit(0);

		default:
		printf("INVALID OPTION \n");
	}
	    }
}

	
