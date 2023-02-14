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

int main()
{
    stack *stk=createStack();
    StackPush(stk,1);
    StackPush(stk,2);
    StackPush(stk,3);
    StackPush(stk,4);
    StackPush(stk,5);
    printf("\n Complete Stack \n");
    StackPrint(stk);
    printf("\n Popped Elements \n");
    printf("\n %d \n",StackPop(stk));
    printf("\n %d \n",StackPop(stk));
    printf("\n Modified Stack \n");
    StackPrint(stk);
}
