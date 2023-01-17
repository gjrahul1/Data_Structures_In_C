#include <stdlib.h>
#include <stdio.h>
struct node
{
    int data;
    struct node *link;
};
int ele,size,i;
struct node *head=NULL;
struct node *temp_node;
struct node *newnode;
int create_list()
{
    printf("Enter the size of linked list \t");
    scanf("%d",&size);
    for(i=0; i<size; i++)
    {
        printf("Enter the elements of the linked list \t");
        scanf("%d",&ele);
        newnode=(struct node*)malloc(sizeof(struct node));
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
}
int display()
{
    for(i=0; i<size; i++)
    {
        printf("%d->",head->data);
        head=head->link;
    }
}
int delete_node()
{
    struct node *ptr;
    ptr=head;
    head=head->link;
    free(ptr);
}
int main()
{
    int choice;
    while(1)
    {
    printf("\n **MENU ** \n");
    printf("1.Create Linked List. \n 2.Delete element at beginning of the node. \n 3.Display. \n 4.Exit \n");
    scanf("%d",&choice);
    if(choice==1)
    {
        create_list();
    }
    else if(choice==2)
    {
        delete_node();
    }
    else if(choice==3)
    {
        display();
    }
    else
    {
        exit(0);
    }
}
}