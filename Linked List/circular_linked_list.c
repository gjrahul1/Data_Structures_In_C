#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
struct Node *head=NULL;
struct Node *linkedlist;
struct Node *temp_node;
int size,i,value;
int create_list()
{
printf("Enter the size of the linked list \t");
scanf("%d",&size);
for(i=0; i<size; i++)
{
   temp_node=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the values for the linked list of %d \t",size);
    scanf("%d",&value);
        temp_node->data=value;
        temp_node->link=NULL;
    if(head==NULL)
    {
        head=linkedlist=temp_node;
    }
    else
    {
        linkedlist->link=temp_node;
        linkedlist=temp_node;
    }
}
}
//Insert At End Code
int insert_at_end()
{
    struct Node *ptr;
struct Node *insert_end=(struct Node*)malloc(sizeof(struct Node));
    ptr=head;
    printf("Enter the value to be inserted at the beginning \t");
    scanf("%d",&value);
    insert_end->data=value;
    while(ptr!=head)
    {
        ptr=ptr->link;
    }
    ptr->link=insert_end;
    insert_end->link=head;

}
//Insert At Beginning Code
int insert_at_beg()
{
    struct Node *ptr;
struct Node *insert_beg=(struct Node*)malloc(sizeof(struct Node));
    ptr=head;
    printf("Enter the value to be inserted at the beginning \t");
    scanf("%d",&value);
    insert_beg->data=value;
    while(ptr!=head)
    {
        ptr=ptr->link;
    }
    ptr->link=insert_beg;
    insert_beg->link=head;
    head=insert_beg;

}
//Delete at Front
void delete_at_front()
{
    struct Node *ptr,*first, *del;
    first=ptr=head;
    while(ptr->link!=head)
    {
        ptr=ptr->link;
    }
    ptr->link=first->link;
    del=head;
    head=first->link;
    free(del);
}
//Delete at end
void delete_at_end()
{
    struct Node *pre,*element;
    pre=element=head;
    while(element->link!=head)
    {
        pre=element;
        element=element->link;
    }
    if(element==head)
    {
        head=NULL;
    }
    else
    {
    pre->link=head;
    }
    free(element);
}
void display()

{
    printf("Displaying Elements of the linked list \n");
    linkedlist=head;
    for(i=0; i<size; i++)
    {
        printf("%d->",linkedlist->data);
        linkedlist=linkedlist->link;
    }
}
int main()
{
    int choice;
    while(1)
    {
    printf("\n***MENU***\n");
    printf("\nCIRCULAR LINKED LIST\n");
    printf("1.Create Linked List\n 2.Display \n 3. Insert at beginning \n");
    printf(" 4. Insert at end \n 5. Delete at front \n 6.Delte at end \n  7.Exit \n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        create_list();
        break;
        case 2:
        display();
        break;
        case 3: 
        insert_at_beg();
        break;
        case 4:
        insert_at_end();
        break;
        case 5:
        delete_at_front();
        break;
        case 6:
        delete_at_end();
        break;
        case 7:
        exit(0);
        default:
        printf("Invalid Input \n");
    }
}
}



