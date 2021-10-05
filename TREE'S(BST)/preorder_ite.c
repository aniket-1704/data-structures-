#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root;
struct node* getnewnode(int key)
{
    struct node* t=(struct node*)(malloc(sizeof(struct node)));
    t->data=key;
    t->left=NULL;
    t->right=NULL;
    return t;
}
void insert_iterative(int key)
{
    struct node* node=getnewnode(key);
    struct node* temp=root;
    if(root==NULL)
    {
        root=node;
    }
    else
    {
        struct node* prev;
        while(temp!=NULL)
        {
            prev=temp;
            if(key>temp->data)
            {
                temp=temp->right;
            }
            else
            {
                temp=temp->left;
            }
        }
        if(key>prev->data)
        {
            prev->right=node;
        }
        else
        {
            prev->left=node;
        }
        
    }
}
    int top=-1;
    struct node* a[100];
    int n;
void push(struct node* node)
{
    if(top==n-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        a[++top]=node;
    }
}
struct node* peak()
{
    if(top==-1)
    {
        printf("stack underflow\n");
    }
    else
    {
        return a[top];
    }
}
struct node* pop()
{
    if(top==-1)
    {
        printf("stack underflow\n");
    }
    else
    {
      return a[top--];    
    }
}
int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }    
}
 void display_preorder(struct node* root)
{
      struct node* temp=root;
      push(temp);
      while(isEmpty()!=1)
      {
          struct node* node=pop();
          printf("%d ",node->data);
          if(node->right!=NULL)
          push(node->right);
          if(node->left!=NULL)
          push(node->left);
      }
 }
int main()
{
    n=100;
    root=NULL;
    insert_iterative(100);
    insert_iterative(50);
    insert_iterative(40);
    insert_iterative(30);
    insert_iterative(45);
    insert_iterative(80);
    insert_iterative(70);
    insert_iterative(60);
    insert_iterative(90);
    insert_iterative(200);
    insert_iterative(150);
    insert_iterative(300);
    display_preorder(root);
}