#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;      //global variable declaration
void insertatend(int x)
{
    struct node *t;
    t = (struct node *)(malloc(sizeof(struct node)));
    t->data = x;
    if (head == NULL)
    {
        head = t;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = t;
    }
}
void deleteatstart()
{
    if (head == NULL)
    {
        printf("list empty\n");
    }
    else
    {

        struct node *temp = head;
        if (temp->next == NULL)
        {
            free(temp);
            head = NULL;
        }
        else
        {
            head = temp->next;
            free(temp);
        }
    }
}
void insertatbeg(int x) //insertion at beggining
{

    struct node *t;
    t = (struct node *)(malloc(sizeof(struct node)));
    t->data = x;
    if (head != NULL)
        t->next = head;
    head = t;
}
void insertatpos(int pos, int x)
{
    struct node *t;
    t = (struct node *)(malloc(sizeof(struct node)));
    t->data = x;
    if (pos == 1)
    {
        insertatbeg(x);
    }
    else
    {
        int c = 1;
        struct node *temp = head;
        while (c != pos - 1)
        {
            temp = temp->next;
            c++;
        }
        t->next = temp->next;
        temp->next = t;
    }
}
void deleteatgivval(int key)
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
void deleteatlast()
{
    if (head == NULL)
    {
        printf("list empty\n");
    }
    else
    {
        struct node *temp = head;
        if (temp->next == NULL)
        {
            free(temp);
            head = NULL;
        }
        else
        {
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
        }
    }
}
void maxmin(struct node *head)
{
    struct node *temp = head;
    int min = temp->data;
    int max = temp->data;
    while (temp != NULL)
    {
        if (temp->data > max)
        {
            max = temp->data;
        }
        if (temp->data < min)
        {
            min = temp->data;
        }
        temp = temp->next;
    }
    printf("the smallest element in the list is %d \n", min);
    printf("the largest element in the list is %d \n", max);
}
void display() //method to display the list
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
    int ele1;
    int n;
    int pos;
    printf("\t 1.insertatbeg \t 2.insertatend \t 3.inser at a pos \t 4. delete at start  \t 5.delete at end \t 6.display \t 7.deleteatval  \t 8.exit\n");
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
            printf("enter the element u want to insert\n");
            scanf("%d", &ele);
            insertatend(ele);
            break;
        case 3:
            printf("enter the element u want to insert\n");
            scanf("%d", &ele);
            printf("enter the position u want to insert\n");
            scanf("%d", &pos);
            insertatpos(pos, ele);
            break;
        case 4:
            deleteatstart();
            break;
        case 5:
            deleteatlast();
            break;
        case 6:
            display();
            break;
        case 7:
            printf("enter the element to be deleted\n");
            scanf("%d", &ele1);
            deleteatgivval(ele1);
            display();
            break;
        }
    } while (n != 8);
    return 0;
}
