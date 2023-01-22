#include <stdio.h>
#include <stdlib.h>
int val;
int max_capacity=5;
typedef struct Stack
{
    int top;
    int *data;
    int capacity;
} stack;
stack* create_stack() //Create an Stack with initial conditions
{
    stack *stk_create=(stack*)malloc(sizeof(stack)); //Creating Memory
    stk_create->data=(int*)malloc(max_capacity*sizeof(int));
    stk_create->top=-1;
    stk_create->capacity=5;
    return stk_create; //to the pointer variable str
}
int StackIsEmpty(stack *stk)
{
    return (stk->top==-1); //Returns True is top is -1 else return False
}
int StackSize(stack *stk)
{
    return(stk->top+1); //Returns top+1 value
}
int StackPrint(stack *ptr) //paramater has a pointer variable. 
//ptr points the the same memory location of str (Common Memory Space/Memory Location)
{
    printf("[");
    for(int i=ptr->top; i>=0; i--)
    {
        printf("%d",ptr->data[i]);
    }
    printf("]");
}
void StackPush(stack *ptr,int value)
{
    if(ptr->top+1==ptr->capacity)
    {
        printf("Stack is Full");
        return;
    }
    ptr->top++;
    ptr->data[ptr->top]=value;
}
int main()
{
    stack *stk=create_stack(); //pointer variable 'stk' points to the created stack 'Stack'
    printf("***SIZE OF STACK IS 5*** \t");
    printf("\n Enter the element to push in stack \t");
    scanf("%d",&val);
    StackPush(stk,val); // pushes the pointer variable 'str' and integer variable 'val'
    StackPrint(stk);
}
