#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *link;
}*ptr,*temp,*rear,*front;

struct queue *front = NULL;
struct queue *rear=NULL;
 void enqueue()
 {
     int item;
    printf("Enter the value to be inserted in queue \t");
     if(rear==NULL)
     {
     rear=(struct queue*)malloc(sizeof(struct queue));
     scanf("%d",&item);
     rear->data=item;
     rear->link=NULL;
     front=rear;
     }
     else
     {
         temp=(struct queue*)malloc(sizeof(struct queue));
         scanf("%d",&item);
         temp->data=item;
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
         printf("Queue Underflow Condition");
     }
     else
     {
         if(ptr->link!=NULL)
         {
             ptr=ptr->link;
             printf("Deleted Element %d \t",front->data);
             free(front);
             front=ptr;
         }
         else
         {
             printf("Deleted Element %d \t",front->data);
             free(front);
             front=rear=NULL;
         }
     }
 }
 
 void display()
 {
     ptr=front;
     if(ptr==NULL)
     {
         printf("Queue is empty \n");
     }
     while(ptr->link!=NULL)
     {
         printf("%d \t",ptr->data);
         ptr=ptr->link;
     }
     if(ptr->link==NULL)
     {
         printf("%d \t",ptr->data);
         //This if statement runs only for one time, if the condition is true;
     }
 }
 
 int main()
 {
     int choice;
     printf("**CIRCULAR QUEUE USING LINKED LIST** \n");
     while(1)
     {
         printf("\n **MENU**\n");
         printf("1.Enqueue \n 2.Dequeue \n 3.Display \n 0.Exit \n");
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
             printf("Invalid Input");
         }
     }
 }