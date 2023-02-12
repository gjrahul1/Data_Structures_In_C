#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
}node;

node* create()
{
    node *temp;
    printf("Enter the key:");
    temp=(node*)malloc(sizeof(node));
    scanf("%d",&temp->data);
    temp->left=temp->right=NULL;
    return temp;
}

void insert(node *root,node *temp)
{
    if(temp->data<root->data)
    {
        if(root->left!=NULL)
        insert(root->left,temp);
        else
        root->left=temp;
    }
    
    if(temp->data>root->data)
    {
        if(root->right!=NULL)
        insert(root->right,temp);
        else
        root->right=temp;
    }
}

void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d \t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d \t",root->data);
        inorder(root->right);
    }
}

void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d \t",root->data);
    }
}

int main()
{
    char ch;
    node *root=NULL,*temp;
    int del_x;
    do{
        temp=create();
        if(root==NULL)
        root=temp;
        else
        insert(root,temp);
        
        printf("\n Do you wish to enter again \t");
        getchar();
        scanf("%c",&ch);
} while(ch=='y' | ch=='Y');

printf("\n The Preorder Traversal : \t");
preorder(root);
printf("\n The Inorder Traversal : \t");
inorder(root);
printf("\n The Postorder Traversal: \t");
postorder(root);
return 0;
}

