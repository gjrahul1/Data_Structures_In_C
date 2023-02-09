#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;

node* create_BT()
{
    node *p;
    int key;
    printf("\n (Enter -1 for no key) \t");
    printf("Enter any key");
    scanf("%d",&key);
    if(key==-1)
    return NULL;
    p=(node*)malloc(sizeof(node));
    p->data=key;
    printf("Enter the left node of %d \n",key);
    p->left=create_BT();
    printf("Enter the right node of %d \n",key);
    p->right=create_BT();
    return p;
}

void preorder(node *T)
{
    if(T!=NULL)
    {
        printf("%d \t",T->data);
        preorder(T->left);
        preorder(T->right);
    }
}

void inorder(node *T)
{
    if(T!=NULL)
    {
        inorder(T->left);
        printf("%d \t",T->data);
        inorder(T->right);
    }
}

void postorder(node *T)
{
    if(T!=NULL)
    {
        postorder(T->left);
        postorder(T->right);
        printf("%d \t",T->data);
    }
}

int main()
{
    printf("SIMPLE BINARY TREE \n");
    node *root;
    root=create_BT();
    printf("\n The Preorder Traversal is: \n");
    preorder(root);
    printf("\n The Inorder Traversal is: \n");
    postorder(root);
    printf("\n The Postorder Traversal is: \n");
    postorder(root);
    return 0;
}
