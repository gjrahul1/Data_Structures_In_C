#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *link;
}*new,*head,*temp,*tail;

int main()
{
	head=NULL;
	int val,index,counter=0;
	printf("** This is TYPE 2 SINGLE LINKED LIST program ** \n");
	printf("Enter the value for number of nodes \n");
	scanf("%d",&index);
	do
	{
		new=(struct node*)malloc(sizeof(struct node));
		printf("Enter the value for the new node [%d] \n",counter);
		scanf("%d",&val);
		new->data=val;
		new->link=NULL;
		if(head==NULL)
		{
			head=new;
			tail=new;
		}
		else
		{
			tail->link=new;
			tail=new;
		}
		counter=counter+1;
	
	} 
	while(counter!=index);

	//Displaying elements
	
	temp=head;
	printf("Displaying the elements in the linked list \n");
	while(temp!=NULL)
	{
		printf("%d \n",temp->data);
		temp=temp->link;
	}
}

		
