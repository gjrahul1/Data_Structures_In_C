#include <stdio.h>
#include <stdlib.h>
int num[100],element,i,n,j;
int top=-1; //variable 'top' acts as index element 
int push()
{
	if(top==n-1) //check condition that 'top' shouldn't exceed 'size' of number of elements
	{
		printf("Stack Overflow \n");
	}
	else
	{
		printf("Enter the element to be stored in stack \n");
		scanf("%d",&element);
		top++; //increment the 'top' variable
		num[top]=element;  //the array of 'top' which acts as control element
		printf("The element %d is inserted in stack \n",element);
	}
}
int pop()
{
	if(top==-1) //if top is it's initial condition 
	{
		printf("Stack Underflow /n"); //stack holds no element
	}
	else
	{
		top--; //top decrement
		//when we decrement the top, we cannot access the element at that position
		//So, the element is considered as removed
		printf("The element %d is removed from stack\n",element);
	}
}
int display()
{
	if(top==-1)
	{
		printf("Stack is empty \n");
	}
	else
	{
		printf("Displaying the elements \n");
	for(i=top; i>=0; i--) //for loop should begin from top since we cannot make the top as -1
	{
		printf("%d \t",num[i]);
	}
}
}
int main()
{
	printf("Enter the' n' number of elements");
	scanf("%d",&n);
	while(1)
	{
	printf("\n ENTER YOUR CHOICE\n");
	printf("1. PUSH \n 2. POP \n 3. DISPLAY \n 4. EXIT \n");
	scanf("%d",&j);
		switch(j)
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
			default:
				exit(0);
		}
	}
}

