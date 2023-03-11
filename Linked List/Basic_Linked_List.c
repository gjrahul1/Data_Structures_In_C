#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head=NULL;
int main()
{
    int ele,size,i;
    struct node *temp;
    printf("Enter the size of linked list \t");
    //printf("Enter the size of linked list of integer data type \n");
    scanf("%d",&size);
    for(i=0; i<size; i++)
    {
        printf("Enter the elements for the linked list \t");
        scanf("%d",&ele);
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=ele;
        newnode->link=NULL;
        
        if(head==NULL)
        {
            head=temp=newnode;
            printf("I am of value %d \t \n",head->data);
        }
        else
        {
            temp->link=newnode;
            temp=newnode;
            printf("%d \t is stored in %d \t \n ",temp->data,temp->link);
        }
    }
    //displaying the elements
    for(i=0; i<size; i++)
    {
        if(head==NULL)
        {
            printf("\t \n Linked List is empty");
        }
        else
        {
            printf("%d->",head->data);
     
            head=head->link;
        }
    }
    return 0;
}
