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
    t->next = NULL;
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
void insert_sort(int x)
{
    struct node *t;
    t = (struct node *)(malloc(sizeof(struct node)));
    t->data = x;
    t->next = NULL;
    if (head == NULL)
    {
        head = t;
    }
    else
    {
        struct node *current = head;
        struct node *prev = head;
        while (current != NULL && current->data < t->data)
        {
            prev = current;
            current = current->next;
        }
        if (current == NULL)
        {
            prev->next = t;
        }
        else if (current == head)
        {
            head = t;
            t->next = current;
        }
        else
        {
            prev->next = t;
            t->next = current;
        }
    }
}
void concatenate(struct node *head1, struct node *head2)
{
    struct node *temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;
    head = head1;
}
void merge_ll(struct node *head1, struct node *head2)
{
    struct node *temp1 = head1;
    struct node *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            insertatend(temp1->data);
            temp1 = temp1->next;
        }
        else
        {
            insertatend(temp2->data);
            temp2 = temp2->next;
        }
    }
    if (temp1 != NULL)
    {
        while (temp1 != NULL)
        {
            insertatend(temp1->data);
            temp1 = temp1->next;
        }
    }
    if (temp2 != NULL)
    {
        while (temp2 != NULL)
        {
            insertatend(temp2->data);
            temp2 = temp2->next;
        }
    }
}
void remove_duplicates() //in sorted list
{
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL && temp->data == temp->next->data)
        {
            int val = temp->data;
            struct node *temp1 = temp;
            while (temp != NULL && temp->data == val)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                temp1->next = NULL;
                break;
            }
            else
            {
                temp1->next = temp;
            }
        }
        else
        {
            temp = temp->next;
        }
    }
}
struct node *reverse()
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
int main()
{
    int ele;
    int ele1;
    int n;
    int pos;
    printf("\t 1.insert in sorted manner\t2.merge 2 ll in sorted way\t 3.concatnate 2 ll\t4. delete duplicate values\t5.reverse list\t6.display\t 7.exit\n");
    do
    {
        printf("choose from the above options\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("enter the element u want to insert\n");
            scanf("%d", &ele);
            insert_sort(ele);
            break;
        case 2:
            printf("LINKED LIST 1\n");
            head = NULL;
            insert_sort(7);
            insert_sort(4);
            insert_sort(3);
            insert_sort(1);
            struct node *head1 = head;
            display();
            printf("LINKED LIST 2\n");
            head = NULL;
            insert_sort(6);
            insert_sort(5);
            insert_sort(2);
            struct node *head2 = head;
            display();
            head = NULL;
            printf("LINKD LIST after merging \n");
            merge_ll(head1, head2);
            display();
            break;
        case 3:
            printf("LINKED LIST 1\n");
            head = NULL;
            insert_sort(7);
            insert_sort(4);
            insert_sort(3);
            insert_sort(1);
            struct node *head11 = head;
            display();
            printf("LINKED LIST 2\n");
            head = NULL;
            insert_sort(6);
            insert_sort(5);
            insert_sort(2);
            struct node *head22 = head;
            display();
            head = NULL;
            printf("LINKD LIST after merging \n");
            concatenate(head11, head22);
            display();
            break;
        case 4:
            remove_duplicates();
            break;
        case 5:
            head=reverse();
            break;
        case 6:
            display(head);
            break;
        }
    } while (n != 7);
    return 0;
}