/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *link;
};
int main()
{
int index,size,ele;
struct node *head=NULL;
struct node *temp_node;
printf("Enter the size of the linked list \t");
scanf("%d",&size);
for(index=0; index<size; index++)
{
    printf("Enter the element for the linked list of %d \t",size);
    scanf("%d",&ele);
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->link=NULL;
    if(head==NULL)
    {
        head=temp_node=newnode;
    }
    else
    {
        temp_node->link=newnode;
        temp_node=newnode;
    }
}
int insert_beginning()
{
    struct node *insert_at_beg=(struct node*)malloc(sizeof(malloc));
    printf("\n \t   Enter the data to be stored at the beginning of the first node \t");
    scanf("%d",&insert_at_beg->data);
    insert_at_beg->link=head;
    head=insert_at_beg;
}
insert_beginning();
//display function
for(index=0; index<size; index++)
{
    printf("%d->",head->data);
    head=head->link;
}
}