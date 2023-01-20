#include <stdio.h>
#include <stdlib.h>
int choice, i, size,recieve,r;
struct node
{
    int data;
    struct node *link;
    struct node *prev;
};

struct node *head=NULL;
struct node *linkedlist;

int create_list(int recieve)
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
 for(i=0; i<recieve; i++)
    {
    printf("Enter the data to be inserted at the node %d \t",i+1);
    scanf("%d",&newnode->data);
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
}

int insert_front(int recieve)
{
    struct node *newnode, *ptr;
    if(head==NULL)
    {
        printf("Linked List is empty \n");
    }
    else
    {
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=recieve;
    ptr=head;
    while(ptr->link!=head)
    {
        ptr=ptr->link;
    }
    ptr->link=newnode;
    ptr->link->prev=newnode;
    newnode->link=head;
    newnode->prev=ptr;
    head=newnode;
    printf("%d is inserted \n",head->data);
    size+=1;
}
}
int insert_end(int recieve)
{
    struct node *newnode, *ptr;
    if(head==NULL)
    {
        printf("Linked List is empty \n");
    }
    else
    {
    ptr=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=recieve;
    newnode->link=head;
    while(ptr->link!=head)
    {
        ptr=ptr->link;
    }
    ptr->link=newnode;
    newnode->prev=ptr;
    head->prev=newnode;
    printf("%d is inserted \n",ptr->link->data);
    size+=1;
}
}

void delete_begin()
{
    if (head == NULL) {
        printf("\nList is Empty\n");
        return;
    } else  if (head->link == head) {
        free(head);
        head = NULL;
        return;
    }
 
    struct node* temp = head;
    head->prev->link = head->link;
    head->link->prev = head->prev;
    head = head->link;
 
    free(temp);
    temp = NULL;
} 


void delete_front()
{
    struct node *ptr, *ftr,*temp;
    ftr=ptr=head;
    while(ptr->link!=head)
    {
        ptr=ptr->link;
    }
    ptr->link=ftr->link;
    ftr->link->prev=ptr;
    head=ftr->link;
    temp=head;
    free(temp);
    printf("Front Node deleted \n");
}

void delete_at_end()
{
    struct node *ptr, *end; 
    end=ptr=head;
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
        ptr->prev->link=head;
        head->prev=ptr->prev;
    }
    free(ptr);
}

int display(int r)
{
    for(i=0; i<size; i++)
    {
        printf("%d->",head->data);
        head=head->link;
    }
}

//Delete functions are not called since it runs into run-time error

int main()
{
    while(1)
    {
    printf("\n *** CIRCULAR DOUBLY LINKED LIST *** \n");
    printf("1.Create Linked List \n 2.Insert at front \n 3.Insert at end \n");
    printf(" 6.Display \n ");
    printf(" 0. Exit \n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("Enter the size of the linked list \n");
        scanf("%d",&size);
        create_list(size);
        break;
        
        case 2:
        printf("Enter the element to be inserted at the front \n");
        scanf("%d",&r);
        insert_front(r);
        break;
        
        case 3:
        printf("Enter the element to be inserted at the end \n");
        scanf("%d",&r);
        insert_end(r);
        break;
        
        case 4:
        display(size);
        break;
        
        case 0:
        exit(0);
        
        default:
        printf("INVALID OPTION");
    }
}
}