#include <stdio.h>
#include <string.h>
char stack[40];
int size=40, top=-1;
int i;
char str[40];
void push(char ele)
{
	if(top==size-1)
	{
		printf("Stack Overflow \n");
	}
	else
	{
		top++;
		stack[top]=ele;
		printf("%c is pushed \n",stack[top]);
	}
}
void pop()
{
	if(top==-1)
	{
		printf("Stack Underflow \n");
	}
	else
	{
		printf("Popped %c",stack[top--]);
	}
}
void check()
{
	for(i=0; i<=strlen(str); i++)
	{
		if(str[i]=='(')
	{
		push(str[i]);
	}
	else if(str[i]==')')
	{
		pop();
	}
	}
	if(top==-1)
	{
		printf("Parenthesis is Balanced  \n");
	}
	else
	{
		printf("Parenthesis is unbalanced \n");
	}
}
void  main()
{
	printf("Enter an expression with parenthesis \n");
	scanf("%s",str);
	check();
}
	

