#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
    int thread;
}node;

node *root=NULL;

node *insert_node(node *root,node *p,node *RT)
{
    if(root==NULL)
    {
        root=p;
        if(RT!=NULL)
        {
            root->right=RT;
            root->thread=1;
        }
    }
    else if(p->data<root->data)
    {
        root->left=insert_node(root->left,p,root);
    }
    else
    {
        if(root->thread==1)
        {
            root->right=insert_node(NULL,p,RT);
            root->thread=0;
        }
        else
        {
            root->right=insert_node(root->right,p,RT);
        }
    }
    return root;
}

node *create_BT()
{
    node *p;
    int n;
    printf("\n Enter the key (Enter -1 for no key):");
    scanf("%d",&n);
    while(n!=-1)
    {
        p=(node*)malloc(sizeof(node));
        p->data=n;
        p->left=p->right=NULL;
        p->thread=0;
        root=insert_node(root,p,NULL);
        printf("\n Enter the key:");
        scanf("%d",&n);
    }
    return root;
}

void inorder(node *root)
{
    node *p=root, *q;
    do
    {
        while(p!=NULL)
        {
            q=p;
            p=p->left;
        }
            if(q!=NULL)
            {
                printf("%d \t",q->data);
                p=q->right;
                while(q!=NULL && q->thread)
                {
                    q=p;
                    printf("%d \t",p->data);
                    p=p->right;
                }
            }
            }while(p!=NULL);
        }

void main()
{
 //   clrscr();
    create_BT();
    printf("\n \n The Inorder Traversal is: \n");
    inorder(root);
    getch();
}