#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct Stack
{
    int *data;
    int top;
    int capacity;
}stack;

stack* createStack()
{
    stack *stk=(stack*)malloc(sizeof(stack));
    stk->data=(int*)malloc(MAX*sizeof(int)); //Array of Pointers
    stk->top=-1;
    stk->capacity=MAX;
    return stk;
}

int StackIsEmpty(stack *stk)
{
    return(stk->top==-1);
}

int StackSize(stack *stk)
{
    return (stk->top+1);
}

void StackPrint(stack *stk)
{
    printf("[ ");
    for(int i=stk->top; i>=0; i--)
    {
        printf("%d \t",stk->data[i]);
    }
    printf("]");
}
void StackPush(stack *stk,int value)
{
    if(stk->top==stk->capacity)
    {
        printf("Stack is Full \n");
        return;
    }
    else
    {
        stk->top++;
        stk->data[stk->top]=value;
    }
}

int StackPop(stack *stk)
{
    if(stk->top==-1)
    {
        printf("Stack Undeflow Condition \n");
    }
    else
    {
        int item;
        item=stk->data[stk->top];
        stk->top--;
        return item;
    }
}

int StackTop(stack *stk)
{
    return(stk->data[stk->top]); //returning the first element in stack
}
int main()
{
    stack *stk=createStack();
   int j,k,check;
   j=0,k=0;
   printf("'Stack is created' \n");
   while(j!=5)
   {
       StackPush(stk,j);
       j+=1;
   }
   printf("\n");
   printf(" 'Displaying Stack' \n");
   StackPrint(stk);
   printf("\n");
   printf("Top Value Of Stack = %d \t \n",StackTop(stk));
   printf("\n");
   printf("Stack Size = %d \t \n",StackSize(stk));
   printf("\n");
   printf("Stack Condition:");
   check=StackIsEmpty(stk);
   if(check==0)
   {
       printf("Stack Contains Element \n");
   }
   else
   {
       printf("Stack Is Empty \n");
   }
   printf("\n");
   printf("Popping Elements Out Of Stack \n \n");
   while(k!=5)
   {
       printf("[");
   printf("%d ",StackPop(stk));
   printf("]");
   k=k+1;
   printf("\n");
   }
   check=StackIsEmpty(stk);
   printf("\n Stack Condition:");
   if(check==0)
   {
       printf("Stack Contains Elements \n");
   }
   else
   {
       printf("Stack Is Empty");
   }
   
}