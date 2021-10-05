#include <stdio.h>
#include <stdlib.h>
#define max (x,y) (x>y)?x:y
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
void display_postorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    display_inorder(root->left);
    display_inorder(root->right);
    printf("%d ",root->data);
}
void display_preorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
     printf("%d ",root->data);
    display_inorder(root->left);
    display_inorder(root->right);
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
int countnodes(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
        return (1 + countnodes(root->left) + countnodes(root->right));
}
int count_leafes(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    //write here any condition to count number of nodes of any type
    else if (root->left == NULL && root->right == NULL)
        return (1 + count_leafes(root->left) + count_leafes(root->right));
    else
    {
        return (0 + count_leafes(root->left) + count_leafes(root->right));
    }
}
int count_parent_nodes(struct node *root)
{
    return (countnodes(root) - count_leafes(root));
}
int maximum_node(struct node* root)
{
    if(root==NULL)
    {
        return ;
    }
    else
    {
        struct node* temp=root;
        struct node* prev=root;
        while(temp->right!=NULL)
        {
            prev=temp;
            temp=temp->right;
        }   
        if(prev==root)
        {
            return prev->data;
        } 
        else
        {
            return prev->right->data;
        }     
    }  
}
int minimum_node(struct node* root)
{
    if(root==NULL)
    {
        return ;
    }
    else
    {
        struct node* temp=root;
        struct node* prev=root;
        while(temp->left!=NULL)
        {
            prev=temp;
            temp=temp->left;
        }   
        if(prev==root)
        {
            return prev->data;
        } 
        else
        {
            return prev->left->data;
        }     
    }  
}
int height(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return (1+maxof(height(root->left),height(root->right)));
    }
}
int maxof(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }   
}
//deletetion iterative
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
int main()
{
    root = NULL;
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
    printf("tree printed in inorder\n");
    display_inorder(root);
    printf("\ntree printed in preorder\n");
    display_preorder(root);
    printf("\ntree printed in postorder\n");
    display_postorder(root);
    printf("\nnodes = %d\n", countnodes(root));
    printf("leaf nodes = %d\n", count_leafes(root));
    printf("paret nodes = %d\n", count_parent_nodes(root));
    printf("maximum element in the tree is : %d",maximum_node(root) );
    printf("\nminimum element in the tree is : %d",minimum_node(root) );
    printf("\nheight of the tree is : %d",height(root));
}