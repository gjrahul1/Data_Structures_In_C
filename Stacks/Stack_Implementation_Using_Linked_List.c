#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *link;
};

struct stack *top=NULL;

void push()
{
    int item;
    struct stack *temp=(struct stack*)malloc(sizeof(struct stack));
    printf("Enter the item to be pushed in stack");
    scanf("%d",&item);
    temp->data=item;
    temp->link=top;
    top=temp;
}

void pop()
{
    int item;
    //stack *temp=(stack*)malloc(sizeof(stack));
    struct stack *ptr;
    ptr=top;
    if(ptr==NULL)
    {
        printf("Stack Underflow Condition");
    }
    else
    {
        top=top->link;
        printf("Element Popped %d \t",ptr->data);
        free(ptr);
    }
}

void display()
{
    struct stack *temp;
    temp=top;
    while(temp!=NULL)
    {
        printf("%d \t",temp->data);
        temp=temp->link;
    }
}

int main()
{
    int choice;
    printf("**Stack Implementation Using Linked List** \n");
    while(1)
    {
        printf("\n**MENU**\n");
        printf("1.Push () \n 2.Pop() \n 3.Display() \n 0. Exit \n");
        printf("Enter your choice \t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 0:
            exit(0);
            default:
            printf("Invalid Option \n");
        }
    }
}