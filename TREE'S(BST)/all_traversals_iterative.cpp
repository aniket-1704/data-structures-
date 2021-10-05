#include <iostream>
#include <stack>
using namespace std;
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
//iterative solution to print inorder of tree
void display_preorder(struct node* root)
{
    stack <pair<struct node*,int>> s;
    pair <struct node*,int> p;
    p.first=root;
    p.second=1; 
    s.push(p);
    while(s.empty()==false)
    {
        //preorder
        //increment second and push left node
        if((s.top()).second==1)
        {
            (s.top()).second=2;
            cout<<(s.top().first)->data<<" ";
            if(((s.top()).first)->left!=NULL)
            {
            pair <struct node*,int> p1;
            p1.first=((s.top()).first)->left;
            p1.second=1;
            s.push(p1);
            }
        }
        //inorder
        //increment second and push right node
        else if((s.top()).second==2)
        {
            (s.top()).second=3;
            if(((s.top()).first)->right!=NULL)
            {
            pair <struct node*,int> p1;
            p1.first=((s.top()).first)->right;
            p1.second=1;
            s.push(p1);
            }
        }
        //postorder
        //pop
        else
        {
            s.pop();
        }
    }
}
void display_inorder(struct node* root)
{
    stack <pair<struct node*,int>> s;
    pair <struct node*,int> p;
    p.first=root;
    p.second=1;
    s.push(p);
    while(s.empty()==false)
    {
        //preorder
        //increment second and push left node
        if((s.top()).second==1)
        {
            (s.top()).second=2;
            if(((s.top()).first)->left!=NULL)
            {
            pair <struct node*,int> p1;
            p1.first=((s.top()).first)->left;
            p1.second=1;
            s.push(p1);
            }
        }
        //inorder
        //increment second and push right node
        else if((s.top()).second==2)
        {
            (s.top()).second=3;
            cout<<(s.top().first)->data<<" ";
            if(((s.top()).first)->right!=NULL)
            {
            pair <struct node*,int> p1;
            p1.first=((s.top()).first)->right;
            p1.second=1;
            s.push(p1);
            }
        }
        //postorder
        //pop
        else
        {
            s.pop();
        }
    }
}
void display_postorder(struct node* root)
{
    stack <pair<struct node*,int>> s;
    pair <struct node*,int> p;
    p.first=root;
    p.second=1;
    s.push(p);
    while(s.empty()==false)
    {
        //preorder
        //increment second and push left node
        if((s.top()).second==1)
        {
            (s.top()).second=2;
            if(((s.top()).first)->left!=NULL)
            {
            pair <struct node*,int> p1;
            p1.first=((s.top()).first)->left;
            p1.second=1;
            s.push(p1);
            }
        }
        //inorder
        //increment second and push right node
        else if((s.top()).second==2)
        {
            (s.top()).second=3;
            if(((s.top()).first)->right!=NULL)
            {
            pair <struct node*,int> p1;
            p1.first=((s.top()).first)->right;
            p1.second=1;
            s.push(p1);
            }
        }
        //postorder
        //pop
        else
        {
            cout<<(s.top().first)->data<<" ";
            s.pop();
        }
    }
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
    cout<<"preorder of tree"<<endl;
    display_preorder(root);
    cout<<endl<<"inorder of tree"<<endl;
    display_inorder(root);
    cout<<endl<<"postorder of tree"<<endl;
    display_postorder(root);

} 