#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int top=-1,i;
int size[100];
char stack[100];
char input[100],output[100];
void push(char ele)
{
    if(size==top+1)
    {
    printf("Stack Overflow");
    }
else
{
    top++;
    stack[top]=ele;
    printf("%c is pushed \n",stack[top]);
}
}
char pop()
{
    if(top==-1)
    {
        printf("Stack Underflow");
    }
    else
    {
         return stack[top--];
    }
}
void main()
{
    printf("Enter any string to be reversed \n");
    scanf("%s",input);
    for(i=0; i<=strlen(input); i++)
    {
        push(input[i]);
    }
    for(i=0; i<=strlen(input); i++)
    {
        output[i]=pop();
    }
    for(i=0; i<=strlen(input); i++ )
    {
        printf("%c is Popped \n",output[i]);
    }
}