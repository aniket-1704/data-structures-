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
//recursive funnct to insert
struct node* insert_recursive(struct node* root,int key)
{
    struct node* node=getnewnode(key);
    if(root==NULL)
    {
        return node;
    }
    else if(key>root->data)
    {
        root->right=insert_recursive(root->right,key);
    }
    else
    {
        root->left=insert_recursive(root->left,key);
    }
    return root;
}
//delete recursive function
struct node* delete_recursive(struct node* root,int key)
{
    //searching node to be deleted
    if(root==NULL)
    {
        return NULL;
    }
    else if(key>root->data)
    {
        root->right=delete_recursive(root->right,key);
    }
    else if(key<root->data)
    {
        root->left=delete_recursive(root->left,key);
    }
    //found element
    else
    {
        //if 0 children
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            root=NULL;
        }
        //1 child
        else if(root->left==NULL)
        {
            struct node* temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL)
        {
            struct node* temp=root;
            root=root->left;
            free(temp);
        }
        //2 children
        else
        {
            int data=in_suc(root->data);
            root->data=data;
            root->right=delete_recursive(root->right,data);
        }
        return root;       
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
void display_inorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    display_inorder(root->left);
    printf("%d ",root->data);
    display_inorder(root->right);
}
int main()
{
    root=NULL;
    root=insert_recursive(root,100);
    root=insert_recursive(root,50);
    root=insert_recursive(root,40);
    root=insert_recursive(root,30);
    root=insert_recursive(root,45);
    root=insert_recursive(root,80);
    root=insert_recursive(root,70);
    root=insert_recursive(root,60);
    root=insert_recursive(root,90);
    root=insert_recursive(root,200);
    root=insert_recursive(root,150);
    root=insert_recursive(root,300);
    display_inorder(root);
    printf("\n");
    root=delete_recursive(root,45);
    display_inorder(root); printf("\n");
    root=delete_recursive(root,70);
    display_inorder(root); printf("\n");
    root=delete_recursive(root,50);
    display_inorder(root); printf("\n");    
} 