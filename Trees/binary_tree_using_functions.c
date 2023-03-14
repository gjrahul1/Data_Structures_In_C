#include <stdio.h>
#include <stdlib.h>
struct node
{
        int data;
        struct node *left, *right;
};

struct node* create(int value)
{
        struct node *leaf=(struct node*)malloc(sizeof(struct node));
        leaf->data=value;
        leaf->left=NULL;
        leaf->right=NULL;
}
 struct node* left(struct node* root,int value)
{
        root->left=create(value);
        return root->left;
}

struct node* right(struct node* root, int value)
{
        root->right=create(value);
        return root->right;
}

void preorder(struct node* root)
{
        if(root==NULL)
                return;
        printf("%d \t",root->data);
        preorder(root->left);
        preorder(root->right);
}

void postorder(struct node* root)
{
        if(root==NULL)
                return;
        postorder(root->left);
        postorder(root->right);
        printf("%d \t",root->data);
}

void inorder(struct node* root)
{
        if(root==NULL)
                return;
        inorder(root->left);
        printf("%d \t",root->data);
        inorder(root->right);
}

int main()
{
        struct node* root=create(1);
        left(root,54);
        right(root,45);
        left(root->left,25);
        right(root->left,6);
        left(root->right,7);
        right(root->right,10);

        printf("Binary Tree Traversal \n");
        printf("\n Inorder Traversal \n");
        inorder(root);
        printf("\n Preoder Traversal \n");
        preorder(root);
        printf("\n Postorder Traversal \n");
        postorder(root);
}