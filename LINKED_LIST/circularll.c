
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void insertatbeg(int item)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        ptr->data = item;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            ptr->next = head;
            temp->next = ptr;
            head = ptr;
        }
    }
}
void insertatend(int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    if (head == NULL)
    {
        head = t;
        t->next = head;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = t;
        t->next = head;
    }
}

void deleteatlast()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("list is empty");
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        temp->next = head;
    }
}
void display()
{
    struct node *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("list is empty");
    }
    else
    {
        while (temp->next != head)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
}
int main()
{
    insertatbeg(50);
    insertatbeg(40);
    insertatbeg(30);
    insertatbeg(20);
    insertatbeg(10);
    deleteatlast();
    insertatend(50);
    display();
}