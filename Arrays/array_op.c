#include <stdio.h>
#include <stdlib.h>
int arr[20],i,j,position,n,ele;
int create_array()
{
	printf("Enter the number of elements in an array \n");
	scanf("%d",&n);
	printf("Enter elements in array \n");
	for(i=0; i<n; i++)
		for(i=0; i<n; i++)
		{
			scanf("%d",&arr[i]);
		}
}
int display_array()
{
	printf("The elements in the array are \n");
	for(i=0; i<n; i++)
	{
		printf("arr[%d] = %d",i,arr[i]);
	}
}
int delete_array()
{
	printf("Enter the position where to delete the elements \n");
	scanf("%d",&position);
	while(position<n)
	{
		arr[position-1]=arr[position];
		position=position+1;
	}
	n=n-1;
	display_array();
	}
int insert_array()
{
	printf("Enter the position where you want to insert the element \n");
	scanf("%d",&position);
	for(i=n; i>=position; i--)
	{
		arr[i+1]=arr[i];
	}
	printf("Enter the elememt to be inserted at arr[%d]",position);
	scanf("%d",&ele);
	for(i=0; i<n; i++)
	{
		arr[position]=ele;
	}
	display_array();
}
int main()
{
	printf("\n 1. Insert an element in array \n");
	printf("2. Delete an element in array \n");
	printf("3.Enter elements in array \n");
	printf("4.Display Array \n 5. Exit \n  Enter your choice \n");
	scanf("%d",&j);
	switch(j)
		{
			while(1)
			{
				case 1:
				insert_array();
				main();
				break;
				case 2:
				delete_array();
				main();
				break;
				case 3:
				create_array();
				main();
				break;
				case 4:
				display_array();
				main();
				break;
				case 5:
				exit(0);
				break;
				default:
				exit(0);
	}
}
}
