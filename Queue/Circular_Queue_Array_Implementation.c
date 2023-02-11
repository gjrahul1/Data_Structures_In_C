#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX];
long rear=-1, front=-1;

//Enqueue Operation
void enqueue()
{
    int item;
    if(((rear+1)%MAX)==front)
    {
        printf("Queue Overflow Condition \n");
    }
    else
    {
        printf("Enter the element \t");
        scanf("%d",&item);
        if((front==-1)&&(rear==-1))
        {
            front=rear=0;
        }
        else
        {
            rear=(rear+1)%MAX;
        }
        queue[rear]=item;
    }
}

void dequeue()
{
    int item;
    if(front==-1)
    {
        printf("Queue Underflow Condition \n");
    }
    else
    {
        item=queue[front];
        printf("Deleted Item is %d \t",item);
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front=(front+1)%MAX;
        }
    }
}

void display()
{
    int i=front;
    while(i!=rear)
    {
        printf("%d \t",queue[i]);
        i=(i+1)%MAX;
    }
    printf("%d",queue[rear]);
}

int main()
{
    printf("**CIRUCULAR QUEUE**\n");
    int choice;
    while(1)
    {
    printf("\n **MENU**\n");
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
        printf("Invalid Option");
    }
}
}