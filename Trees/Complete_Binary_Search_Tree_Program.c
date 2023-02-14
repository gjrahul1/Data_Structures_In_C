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

node* find_smallest(node *root)
{
    if(root==NULL)
    return NULL;
    //node with minimum value will have no left Child
    else if(root->left!=NULL)
    //leftmost element will be smallest
    return find_smallest(root->left);
    return root;
}

struct node* delete(node* root,int x)
{
    //searching for the node to be deleted
    if(root==NULL) //base case
    return NULL;
    if(x>root->data)
    {
        root->right=delete(root->right,x);
    }
    else if(x<root->data)
    {
        root->left=delete(root->left,x);
    }
    else
    {
        //Leaf node to be deleted
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        //One Child node to be deleted
        else if(root->left==NULL | root->right==NULL)
        {
            node *temp;
            if(root->left==NULL)
            temp=root->right;
            else
            temp=root->left;
            free(root);
            return temp;
        }
        //Two child nodes to be deleted
        else
        {
            node *temp=find_smallest(root->left);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
    }
    return root;
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
printf("\n \n Enter the key of a node to be deleted:");
scanf("%d",&del_x);
root=delete(root,del_x);
printf("\n The Inorder Traversal of BST after deletion is:");
inorder(root);
return 0;
}


