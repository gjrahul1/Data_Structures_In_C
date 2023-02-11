#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int data;
    struct Queue* link;
}*ptr,*temp,*front,*rear;

struct Queue *front=NULL;
struct Queue *rear=NULL;

void enqueue()
{
    int num;
    printf("Enter the element to be inserted in Queue \t");
    if(rear==NULL)
    {
     temp=(struct Queue*)malloc(sizeof(struct Queue*));
     scanf("%d",&num);
     temp->data=num;
     temp->link=NULL;
     rear=temp;
     front=rear;
    }
    else
    {
        temp=(struct Queue*)malloc(sizeof(struct Queue*));
        scanf("%d",&num);
        temp->data=num;
        temp->link=NULL;
        rear->link=temp;
        rear=temp;
        
    }
    
}

void dequeue()
{
    ptr=front;
    if(ptr==NULL)
    {
        printf("Queue Underflow Condition \n");
    }
    else
    {
        if(ptr->link!=NULL)
        {
            ptr=ptr->link;
            printf("Element Deleted %d",front->data);
            free(front);
            front=ptr;
        }
    }
}

int display()
{
    struct Queue *print=front;
    if(print==NULL)
    {
        printf("Queue is empty \n");
    }
    while(print->link!=NULL)
    {
        printf("%d \t",print->data);
        print=print->link;
    }
    if(print->link==NULL)
    {
        printf("%d \t",print->data);
    }
}

int main()
{
    int choice;
    printf("\n This is Queue Program using Linked List\n");
    while(1)
    {
        printf("\n**MENU**\n");
        printf("1.Enqueue \n 2.Dequeue\n 3.Display\n 0.Exit \n");
        printf("Enter your choice \t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 0:
            exit(0);
            default:
            printf("Invalid Option \t");
        }
    }
}
