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
void insertatend(int x)
{
    struct node *t = getnewnode(x);
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
        t->prev = temp;
    }
}
void insertbefvalue(int value, int before)
{
    if (head == NULL)
    {
        printf("list is empty");
    }
    else if (head->data == value)
    {
        struct node *temp = getnewnode(before);
        temp->next = head;
        temp->next->prev = temp;
        head = temp;
    }
    else
    {
        struct node *temp = head;
        struct node *new = getnewnode(before);
        while (temp->next->data != value)
        {
            temp = temp->next;
        }
        struct node *temp1 = temp->next;
        temp->next = new;
        new->prev = temp;
        new->next = temp1;
        temp1->prev = new;
    }
}
void deletemid()
{
    int count = 1;
    struct node *temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
        count++;
    }
    temp = head;
    if (count == 1)
    {
        printf("only 1 elemnt in the list");
    }
    else
    {
        int p = 1;
        while (p!=(count/2))
        {
            temp = temp->next;
            p++;
        }
        struct node *temp1 = temp->next;
        temp->next = temp->next->next;
        temp1->next->prev = temp;
        free(temp1);
    }
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
void display_reverse()
{
    struct node* temp=head;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else if(temp->next==NULL)
    {
        printf("%d",temp->data);
    }
    else
    {
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=head)
    {
        printf(" %d ",temp->data);
        temp=temp->prev;
    }
    printf(" %d ",temp->data);
    }
}
int main()
{
    int ele;
    int n;
    int pos;
    int n1;
    int n2;
    printf("\t 1.insertatend  \t 2.display  \t 3.insert before element \t 4.delete mid value \t5.display in reverse \t 6.exit\n");
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
            display();
            break;
        case 3:
            printf("enter element value which is to be inserted\n");
            scanf("%d", &n1);
            printf("enter element before which value  is to be inserted\n");
            scanf("%d", &n2);
            insertbefvalue(n2, n1);
            break;
        case 4:
            deletemid();
            break;
        case 5:
            display_reverse();
            break;
        }
    } while (n != 6);
    return 0;
}