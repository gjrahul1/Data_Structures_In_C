#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
int ele,size,i;
int main()
{
printf("Enter the size of the nodes");
scanf("%d",&size);
struct node *head=NULL;
struct node *nextnode;
for(i=0; i<size; i++)
{
    printf("Enter the elements of the nodes \t");
    scanf("%d",&ele);
    struct node *tempnode=(struct node*)malloc(sizeof(struct node));
    tempnode->data=ele;
    tempnode->link=NULL;
    if(head==NULL)
    {
        head=nextnode=tempnode;
    }
    else
    {
        nextnode->link=tempnode;
        nextnode=tempnode;
    }
}
int insert_at_end()
{
    struct node *ptr;
    struct node *insert_at_end=(struct node*)malloc(sizeof(malloc));
    printf("Enter the element to be inserted at the end \t");
    scanf("%d",&insert_at_end->data);
    insert_at_end->link=NULL;
    ptr=head;
    while(ptr->link != NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=insert_at_end;
  // printf("\n We reached here ->%d \n ",head->data);
}
insert_at_end();
//display
for(i=0; i<=size; i++)
{
    printf("%d->",head->data);
    head=head->link;
}
}