
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
struct node *getnewnode(int key)
{
    struct node *t = (struct node *)(malloc(sizeof(struct node)));
    t->data = key;
    t->left = NULL;
    t->right = NULL;
    return t;
}
void insert_iterative(int key)
{
    struct node *node = getnewnode(key);
    struct node *temp = root;
    if (root == NULL)
    {
        root = node;
    }
    else
    {
        struct node *prev;
        while (temp != NULL)
        {
            prev = temp;
            if (key > temp->data)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        if (key > prev->data)
        {
            prev->right = node;
        }
        else
        {
            prev->left = node;
        }
    }
}
void display_inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    display_inorder(root->left);
    printf("%d ", root->data);
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
    else if (root->left == NULL && root->right == NULL)
        return (1 + count_leafes(root->left) + count_leafes(root->right));
    else
    {
        return (0 + count_leafes(root->left) + count_leafes(root->right));
    }
}
int count_nodes_2_children(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left != NULL && root->right != NULL)
        return (1 + count_nodes_2_children(root->left) + count_nodes_2_children(root->right));
    else
    {
        return (count_nodes_2_children(root->left) + count_nodes_2_children(root->right));
    }
}
int count_nodes_1_children(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
        return (1 + count_nodes_1_children(root->left) + count_nodes_1_children(root->right));
    else
    {
        return (count_nodes_1_children(root->left) + count_nodes_1_children(root->right));
    }
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
    printf("tree\n");
    display_inorder(root);
    printf("\nnodes = %d\n", countnodes(root));
    printf("leaf nodes = %d\n", count_leafes(root));
    printf("nodes with 1 child = %d\n", count_nodes_1_children(root));
    printf("nodes with 2 children  = %d\n", count_nodes_2_children(root));
}
