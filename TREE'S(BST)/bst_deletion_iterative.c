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
//deletetion
void delete_iterative(int key)
{
    struct node* temp=root;
    if(root==NULL)
    {
        printf("empty tree\n");
    }
    struct node* prev;
    //searching for element and keeping pointer to previous element
        while(temp!=NULL && key!=temp->data)
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
        //0 nodes child
        if(temp->left==NULL && temp->right==NULL)
        {
            if(temp==prev->right)
            {
                prev->right=NULL;
                free(temp);
            }
            else
            {
                prev->left=NULL;
                free(temp);
            }   
        }
        //1 node child
            else if(temp->left==NULL)
            {
              prev->right=temp->right;
              free(temp); 
            }
            else if(temp->right==NULL)
            {
              prev->left=temp->left;
              free(temp);  
            }   
        //2 node children
        //find inorder successor of key and replace it with it
        else
        {
            int data=in_suc(temp->data);
            delete_iterative(in_suc(temp->data));
            temp->data=data;     
        }
}
int in_suc(int key)
{
    struct node* temp=root;
     while(temp->data!=key)
        {
            if(key>temp->data)
            {
                temp=temp->right;
            }
            else
            {
                temp=temp->left;
            }
        }
    temp=temp->right;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp->data;
}
void display_inorder(struct node* roo)
{
    if(roo==NULL)
    {
        return;
    }
    display_inorder(roo->left);
    printf("%d ",roo->data);
    display_inorder(roo->right);
}
int main()
{
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
    display_inorder(root);
    printf("\n");
    delete_iterative(45);
    display_inorder(root);
    printf("\n");
    delete_iterative(70);
    display_inorder(root);
    printf("\n");
    delete_iterative(50);
    display_inorder(root);
}