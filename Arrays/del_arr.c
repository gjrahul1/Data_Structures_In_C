#include <stdio.h>
#define MAX 4
int main()
{
	int arr[MAX]={1,2,5,7};
	int i,j,n=4;
	int del_pos=2;
	printf("The original elements are \n");
	{
		for(i=0; i<n; i++)
	printf("arr[%d] = %d\n",i,arr[i]);
	}
	while(del_pos<n)
		{
			arr[del_pos-1]=arr[del_pos];
			del_pos=del_pos+1;
		}
	n=n-1;
	printf("ELements after deletation \n");
	for(i=0; i<n; i++)
	{
		printf("arr[%d] = %d \n",i,arr[i]);
	}
}
