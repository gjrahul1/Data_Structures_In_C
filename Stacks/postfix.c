#include <stdio.h>
#include <ctype.h>
#define MAXSIZE 100
#define STACKSIZE 100
int top,arr[MAXSIZE],item,result;
int top=-1;

void push(int ele)
{
	if(top==MAXSIZE-1)
	{
		printf("Stack Overflow Condition \n");
	}
	else
	{
		top=top+1;
		arr[top]=ele;
	}
}

int pop()
{
	if(top==-1)
	{
		printf("Stack underflow condition \n");
	}
	else
	{
		item=arr[top];
		top=top-1;
		return item;
	}
}

void EvalPostfix(char postfix[])
{
	int i,A,B;
	char ch;
	/* Evaluate postfix expression */
	for(i=0; postfix[i]!=')'; i++)
	{
		ch=postfix[i];
		if(isdigit(ch))
		{
			push(ch-'0');
		}
		else if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
		{
			//Pop out last two elements out of the stack
			A=pop();
			B=pop();
			switch(ch)
			{
				case '+':
					result=B+A;
					break;
				case '-':
					result=B-A;
					break;
				case '*':
					result=B*A;
					break;
				case '/':
					result=B/A;
					break;
			}
			push(result);
		}
	}
	int dis=pop();
	printf("The result of the expression is %d \n",dis);
}

int main()
{
	int i;
	char postfix[STACKSIZE];
	printf("Enter postfix expression \n Enter ')' at the end of the expression \n");
	for(i=0; i<STACKSIZE; i++)
	{
		scanf("%c",&postfix[i]);
		if(postfix[i]==')')
		{
			break;
		}
	}
		EvalPostfix(postfix);
		return 0;
}
