#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX];
long rear=-1, front = -1;

//Enqueue Operation
void enqueue()
{
    int item;
    if(rear==MAX-1)
{
    printf("Queue is full : Overflow Condition \t");
}
else
{
    printf("Enter the element \t");
    scanf("%d",&item);
    if((front==-1) && (rear==-1))
    {
        front=rear=0;
    }
    else
    {
        rear=rear+1;
    }
    queue[rear]=item;
}
}

//Dequeue Operation

void dequeue()
{
    int item;
    if(front==-1)
    {
        printf("The queue is empty : Underflow Codition \n");
    }
    else
    {
        item=queue[front];
        printf("Element deleted : %d \t",item);
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front=front+1;
        }
    }
}

//Display Operation
void display()
{
    int i;
    printf("[");
    for(i=front; i<=rear; i++)
    {
        printf("%d,",queue[i]);
    }
    printf("]");
}

int main()
{
    int choice;
    while(1)
    {
    printf("\n ***MENU*** \n");
    printf("1. Enqueue Operation \n 2.Dequeue Operation \n 3. Display \n 0.Exit");
    printf("Enter your choice \n");
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
        printf("INVALID OPTION \n");
    }
}
}
