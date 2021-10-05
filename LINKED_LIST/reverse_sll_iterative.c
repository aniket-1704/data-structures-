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
struct node *reverse(struct node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else if (head->next == NULL)
    {
        return head;
    }
    else //3 pointer approach or iterative approach
    {
        struct node *curr = head;
        struct node *prev = NULL;
        struct node *temp = head;
        while (temp != NULL)
        {
            curr = curr->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }
        return prev;
    }
}
void deleteatgivpos(int key)
{
    if (head == NULL)
    {
        printf("list empty\n");
    }
    else
    {
        struct node *temp = head;
        if (head->data == key)
        {
            head = NULL;
        }
        else
        {
            while (temp->next != NULL && temp->next->data != key)
            {
                temp = temp->next;
            }
            if (temp->next->next == NULL)
            {
                temp->next = NULL;
            }
            else
            {
                temp->next = temp->next->next;
            }
        }
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
    head = reverse(head);
    display(head);
}