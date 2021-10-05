#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head; //global variable declaration
struct node *getnewnode(int x)
{
    struct node *t;
    t = (struct node *)(malloc(sizeof(struct node)));
    t->data = x;
    t->next = NULL;
    t->prev = NULL;
    return t;
}
void insertatbeg(int x) //insertion at beggining
{
    struct node *t = getnewnode(x);
    if (head != NULL)
    {
        t->next = head;
        head->prev = t;
    }
    head = t;
}
void convert_to_dcll()
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->prev = temp;
}
void display_dcll()
{
    struct node *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while (temp->next != head)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
        printf("\n");
    }
}
void display_dll() //method to display the list
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

int main()
{
    int ele;
    int n;
    printf("\t 1.insertatbeg of dll  \t 2.display dll  \t 3.convert dll to dcll \t 4.display dcll \t 5.exit\n");
    do
    {
        printf("choose from the above options\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("enter the element u want to insert\n");
            scanf("%d", &ele);
            insertatbeg(ele);
            break;
        case 2:
            display_dll();
            break;
        case 3:
            convert_to_dcll();
            break;
        case 4:
            display_dcll();
            break;
        }
    } while (n != 5);
    return 0;
}