#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
struct Node *head=NULL;
struct Node *linkedlist;
struct Node *temp_node;
int size,i,value;
//Creating Linked List
int create_list()
{
printf("Enter the size of the linked list \t");
scanf("%d",&size);
for(i=0; i<size; i++) //iterates size-1 times;
{
   temp_node=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the values for the linked list of %d \t",size);
    scanf("%d",&value);
        temp_node->data=value; 
        //stores currently entered value
        temp_node->link=NULL; 
        //makes the current address link point to NULL
    if(head==NULL) 
    {
        head=linkedlist=temp_node;
        //inserting the first inserted element at index 0
    }
    else
    {
        //Code reads from 2nd iteration
        linkedlist->link=temp_node; 
        //stores current memory location address to the previous element's memory box 
        linkedlist=temp_node; 
        //updates the shared memory location with the current items of the iterative loop
    }
}
}
//Insert At End Code
int insert_end()
{
    struct Node *ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("Linked List is empty \n");
    }
    else
    {
    printf("Enter the value to be inserted at the end \t");
    struct Node *insert_end=(struct Node*)malloc(sizeof(malloc));
    scanf("%d",&insert_end->data);
    while(ptr != head)
    {
        ptr=ptr->link; 
        //points to the last address of the last variable 
        ptr->link=insert_end; 
        //links the address of current data to the last element's address box.
    }
    insert_end->link=head; 
    //points the address box of the address of head to the newly inserted element.
  
    size+=1;
printf("\n Inserted at the end of the node, Successfully \n");
}
}
//Insert At Beginning Code
int insert_at_beg()
{
    struct Node *ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("Linked List is empty \n");
    }
    else
    {
    printf("Enter the value to be inserted at the beginning \t");
    struct Node *insert_beg=(struct Node*)malloc(sizeof(malloc));
    scanf("%d",&insert_beg->data);
    while(ptr != head)
    {
        ptr=ptr->link; 
        //points to the last address of the last variable 
        ptr->link=insert_beg; 
        //links the address of current data to the last element's address box.
    }
    insert_beg->link=head; 
    //points the address box of the address of head to the newly inserted element.
   head=insert_beg; 
   //index 0 gets updated to the new element 
}
size+=1;
printf("\n %d Inserted Successfully \n",head->data);
}
void display()

{
    printf("Displaying Elements of the linked list \n");
    for(i=0; i<size; i++)
    {
        printf("%d->",head->data);
        head=head->link;
    }
}
int main()
{
    int choice;
    while(1)
    {
    printf("\n***MENU***\n");
    printf("\nCIRCULAR LINKED LIST\n");
    printf("1.Create Linked List\n 2.Display \n 3. Insert at beginning \n");
    printf(" 4. Insert at end \n  5.Exit \n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        create_list();
        break;
        case 2:
        display();
        break;
        case 3: 
        insert_at_beg();
        break;
        case 4:
        insert_end();
        break;
        case 5:
        exit(0);
        default:
        printf("Invalid Input \n");
    }
}
}





