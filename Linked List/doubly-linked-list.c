#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    struct node *link;
    int data;
};

int size,i,value,choice,position;
struct node *head;
struct node *linkedlist;
struct node *newnode;
struct node *pos;

//Creating Linked List
int create_list()
{
    printf("Enter the size of the linked list");
    scanf("%d",&size);
    for(i=0; i<size; i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the value for node %d \t",i+1);
        scanf("%d",&value);
        newnode->data=value;
        newnode->link=NULL;
        newnode->prev=NULL;
        if(head==NULL)
        {
            head=linkedlist=newnode;
        }
        else
        {
            linkedlist->link=newnode;
            newnode->prev=linkedlist;
            linkedlist=newnode;
        }
    }
    size+=1;
}

//Inserting at the front node
int insert_beginning()
{
    struct node *ptr=head;
    struct node *front;
    if(ptr==NULL)
    {
        printf("Linked List is empty \n");
    }
    else
    {
    printf("Enter the value to be inserted in the front \n");
    front=(struct node*)malloc(sizeof(malloc));
    scanf("%d",&front->data);
    front->link=head;
    front->prev=NULL;
    head->prev=front;
    head=front;
    size+=1;
}
}

//Inserting at the end node
int insert_at_end()
{
    struct node *end;
    struct node *ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("Linked List is empty \n");
    }
    else
    {
    printf("Enter the value to be inserted at the end \n");
    end=(struct node*)malloc(sizeof(malloc));
    scanf("%d",&end->data);
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    end->prev=ptr;
    ptr->link=end;
    ptr=end;
    size+=1;
}
}

int insert_at_pos()
{
//    It's advised to understand that in this code we aren't trying to insert at the head 
//  We are trying to insert between head and the tail
    struct node *ptr;
    ptr=head;
    int j,position;  //position is the index value
    j=1; //Considering it as the position of head
    printf("Enter the position of the node you wish to enter the new value \t");
    scanf("%d",&position);
    if(position>size)
    {
        printf("Exceeded the size of the nodes \n");
    }
    else if(position==0)
        {
            printf("Cannot insert element at head \n");
        }
    else
    {
         while(position!=0 && j<position-1)
        {
            ptr=ptr->link; 
            //ptr points to the location after which we want to enter our new node 
            j++;
        }
        printf("Enter the value for the new node at index %d \t",position);
        pos=(struct node*)malloc(sizeof(malloc));
        scanf("%d",&pos->data);
        pos->link=ptr->link;
        pos->prev=ptr;
        pos->link->prev=pos;
        ptr->link=pos;
    }
}

//Display Code
void display()
{
    linkedlist=head;
    for(i=0; i<size; i++)
{
    while(linkedlist!=NULL)
    {
    printf("%d->",linkedlist->data);
    linkedlist=linkedlist->link;
}
}
}
//Deleting the front node
void delete_front()
{
    struct node *ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("Linked List is empty");
    }
    else
    {
        head=head->link;
        head->prev=NULL;
        free(ptr);
    }
}

//Deleting the node at the end

void delete_end()
{
    struct node *ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("Linked List is empty \n");
    }
    else
    {
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        if(ptr==head)
        {
            head=NULL;
        }
        else
        {
            ptr->prev->link=NULL;
    }
    free(ptr);
}
}

//Delete at position
void delete_at_pos(int position)
{
    struct node *temp;
    struct node *ptr;
    int i=1;
    temp=head;
    if(position>size)
    {
        printf("Invalid Position \n");
    }
    else
    {
        while(i<position-1)
        {
            temp=temp->link;
            i++;
        }
        ptr=temp->link;
        temp->link=ptr->link;
        ptr->link->prev=temp;
    }
    free(ptr);
}

int main()
{
    while(1)
    {
    printf("\n ***MENU*** \n");
    printf("1. Create a Linked List \n 2.Insert at front \n 3.Insert at end \n");
    printf("4.Insert at poistion \n 5.Delete at Front \n 6.Delete at End \n");
    printf("7.Delete at position \n 8. Display \n 8.Exit \n");
    printf("\n");
    printf("Enter your choice \n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        create_list();
        break;
        case 2:
        insert_beginning();
        break;
        case 3:
        insert_at_end();
        break;
        case 4:
        insert_at_pos();
        break;
        case 5:
        delete_front();
        break;
        case 6:
        delete_end();
        break;
        case 7:
    printf("Enter the position to delete the element \n");
    scanf("%d",&position);
        delete_at_pos(position);
        break;
        case 8: 
        display();
        break;
        case 0:
        exit(0);
        break;
        default:
        printf("INVALID OPTION \n");
    }
}
}
