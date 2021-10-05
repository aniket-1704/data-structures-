#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head; //global variable declaration
void insertatend(int x)
{
    struct node *t;
    t = (struct node *)(malloc(sizeof(struct node)));
    t->data = x;
    t->next=NULL;
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
void delete_at_given_val(int x)
{
    if (head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        struct node *temp = head;
        struct node *prev = head;
        if(temp->data==x)
        {
            head=temp->next;
            free(temp);
            return ;
        }
        while (temp->data != x)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
    }
}
void delete_max(struct node *head)
{
    struct node *temp = head;
    int max = temp->data;
    while (temp != NULL)
    {
        if (temp->data > max)
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    delete_at_given_val(max);
}
void find_min(struct node *head)
{
    struct node *temp = head;
    int min = temp->data;
    while (temp != NULL)
    {
        if (temp->data < min)
        {
            min = temp->data;
        }
        temp = temp->next;
    }
    printf("the smallest element in the list is %d \n", min);
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
    int ele2;
    int n;
    int pos;
    printf("\t1.insert at end \t2.delete at beg \t3.insert at pos \t4.delete at val \t5.delete max value  \t6.find min \t7.display \t8.exit\n");
    do
    {
        printf("choose from the above options\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("enter the element u want to insert\n");
            scanf("%d", &ele);
            insertatend(ele);
            break;
        case 2:
            deleteatstart();
            break;
        case 3:
            printf("enter the element u want to insert\n");
            scanf("%d", &ele1);
            printf("enter the position u want to insert\n");
            scanf("%d", &pos);
            insertatpos(pos, ele1);
            break;
        case 4:
            printf("enter the element u want to delete\n");
            scanf("%d", &ele2);
            delete_at_given_val(ele2);
            break;
        case 5:
            delete_max(head);
            break;
        case 6:
            find_min(head);
            break;
        case 7:
            display();
            break;
        }
    } while (n != 8);
    return 0;
}
