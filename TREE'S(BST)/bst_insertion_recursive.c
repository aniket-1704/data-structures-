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
} 