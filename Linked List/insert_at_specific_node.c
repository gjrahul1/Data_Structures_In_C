#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *link;
};
int main()
{
int index,size,ele;
struct node *head=NULL;
struct node *temp_node;
printf("Enter the size of the linked list \t");
scanf("%d",&size);
for(index=0; index<size; index++)
{
    printf("Enter the element for the linked list of %d \t",size);
    scanf("%d",&ele);
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->link=NULL;
    if(head==NULL)
    {
        head=temp_node=newnode;
    }
    else
    {
        temp_node->link=newnode;
        temp_node=newnode;
    }
}
int count=size;
int insert_specific_pos()
{
    int j=1;
    int pos;
    struct node *ptr;
    ptr=head;
    printf("\n \t Enter the position at which you want to insert the new node =");
    scanf("%d",&pos);
    if(pos>count)
    {
        printf("Invalid Position \n");
    }
    else
    {
        while(j<pos-1)
        {
            ptr=ptr->link;
            j++;
        }
        struct node* insert_specific_pos=(struct node*)malloc(sizeof(malloc));
        printf("\n \t Enter the data for the node = ");
        scanf("%d",&insert_specific_pos->data);
        insert_specific_pos->link=ptr->link;
        ptr->link=insert_specific_pos;
    }
}
void display_nodes()
{
    for(index=0; index<size; index++)
    {
        printf("%d->",head->data);
        head=head->link;
    }
}
insert_specific_pos();
display_nodes();
}