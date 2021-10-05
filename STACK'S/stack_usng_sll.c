#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;

}; //stack implementation using LL
//u have to insert at beggening and delete also at beg
struct node *head;
int max = 5;
void insertatbeg()
{
  int n;
  printf("enter the element u want to insert\n");
  scanf("%d", &n);
  struct node *p;
  p = (struct node *)(malloc(sizeof(struct node)));
  p->data = n;
  if (head == NULL)
  {
    head = p;
  }
  else if (countnodes() >= max)
  {
    printf("stack overflow\n");
  }
  else
  {
    p->next = head;
    head = p;
  }
}

int countnodes()
{
  struct node *temp = head;
  int n = 1;
  while (temp->next != NULL)
  {
    n++;
    temp = temp->next;
  }
  return n;
}

void display()
{
  if (head == NULL)
  {
    printf("stack underflow\n");
  }
  else
  {
    struct node *temp = head;
    while (temp != NULL)
    {
      printf("%d\n", temp->data);
      temp = temp->next;
    }
  }
}

void deleteatbeg()
{
  if (head == NULL)
  {
    printf("stack underflow\n");
  }
  else if (head->next == NULL)
  {
    head = NULL;
  }
  else
  {
    struct node *t = head;
    head = head->next;
    free(t);
    display(head);
  }
}

int main()
{

  int op;
  head = NULL;
  printf("1.push\t2.pop\t3.peek\t4.display\t0.exit\n");
  do
  {
    printf("choose the option\n");
    scanf("%d", &op);
    switch (op)
    {
    case 0:
      break;
    case 1:
      insertatbeg();
      printf("stack after inserting\n");
      display();
      break;
    case 2:
      printf("stack after deleting\n");
      deleteatbeg();
      break;
    case 3:
      printf("peek element is\n");
      if (head == NULL)
      {
        printf("stack underflow\n");
      }
      else
      {
        printf("%d\n", head->data);
      }
      break;
    case 4:

      display();
      break;
    }
  } while (op != 0);
}