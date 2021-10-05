#include <stdio.h>
struct node
{
    int data;
    struct node* right;
    struct node* left;
    int height;
};
//avl tree is a self balancing tree
//at any node the difference in the heights of the sub trees is not more than 1
//normal bst travrsall gives o(h) time where h is the height of tthe tree
//this gives o(logn) time where n is the number of nodes
//insertion and deletion is same except the balancing steps
struct node* root;
struct node* get_new_node(int x)
{
    struct node* t=(struct node*)(malloc(sizeof(struct node)));
    t->data=x;
    t->right=NULL;
    t->left=NULL;
    t->height=1;
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
//return the height of the node
int height_node(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return root->height;
    } 
}
//check whether node is balanced or not
int balanced(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return (height_node(root->left)-height_node(root->right));
    } 
}
//right rotate
struct node* right_rotate(struct node* root)
{
    struct node* x=root->left;
    struct node* y=x->right;

    x->right=root;
    root->left=y;

    root->height=1+maxof(height_node(root->left),height_node(root->right));
    x->height=1+maxof(height_node(x->left),height_node(x->right));

    return x;
} 
//left rotate
struct node* left_rotate(struct node* root)
{
    struct node* x=root->right;
    struct node* y=x->left;

    x->left=root;
    root->right=y;

    root->height=1+maxof(height_node(root->left),height_node(root->right));
    x->height=1+maxof(height_node(x->left),height_node(x->right));

    return x;
}

struct node* insert_recursive(struct node* root,int key)
{
    struct node* node=get_new_node(key);
    if(root==NULL)
    {
        return node;
    }
    else if(key>root->data)
    {
        root->right=insert_recursive(root->right,key);
    }
    else if(key<root->data)
    {
        root->left=insert_recursive(root->left,key);
    }
    else
    {
         return root;
    }
    //till here normal insertion of element in bst


    //update the height of the current node
    root->height=1+maxof(height_node(root->left),height_node(root->right));

    //find balance factor of the node
    int bal=balanced(root);


    //left-left rotate
    if(bal>1 && key<root->left->data)
    {
        return right_rotate(root);
    }
    //right-right rotate
    if(bal<-1 && key>root->right->data)
    {
        return left_rotate(root);
    }
    //right-left
   if(bal<-1 && key<root->right->data)
    {
        root->right=right_rotate(root->right);
        return left_rotate(root);
    }
    //left-right
    if(bal>1 && key>root->left->data)
    {
        root->left=left_rotate(root->left);
        return right_rotate(root);
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
    printf("the inorder traversal of the bst is :\n");
    display_inorder(root);
} 