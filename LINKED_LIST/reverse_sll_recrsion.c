#include <stdio.h>
#include <stdlib.h> /* for exit() */
#include <ctype.h>  /* for isdigit(char ) */
#include <string.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void insertatbeg(int x)
{

    struct node *t;
    t = (struct node *)(malloc(sizeof(struct node)));
    t->data = x;
    if (head != NULL)
        t->next = head;
    head = t;
}
void display()
{
    struct node *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void reverse(struct node *node)
{
    if (node->next == NULL)
    {
        head = node;
        return;
    }
    else
    {
        reverse(node->next);
        struct node *temp = node->next;
        temp->next = node;
        node->next = NULL;
    }
}
int main()
{
    head = (struct node *)(malloc(sizeof(struct node)));
    head = NULL;
    insertatbeg(50);
    insertatbeg(40);
    insertatbeg(30);
    insertatbeg(20);
    insertatbeg(10);
    printf("list after inserting elements\n");
    display();
    printf("list after reversing elements\n");
    reverse(head);
    display(head);
}