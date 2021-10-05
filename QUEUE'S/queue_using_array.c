#include <stdio.h>
int front = -1;
int rear = -1;
int a[10];
int max;
//empty= front>rear or front==-1
//full= rear=max-1
void enqueue(int n)
{
    if (rear == max - 1)
    {
        printf("the queue is full\n");
    }
    else
    {
         if(front==-1)
    {
        front=0;
    }
        a[++rear] = n;

    }
    
}
void dequeue()
{
    if (front>rear || (front==-1))
    {
        printf("the queue is empty\n");
         front=rear=-1;
    }
    else
    {
        printf("the element deleted is %d\n", a[front]);
        front++;
    }
}
void display()
{
    if(front>rear || (front==-1))
    {
        printf("the queue is empty\n");
        front=rear=-1;
    }
    for (int i = front; i <= rear; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n ");
}
int main()
{
    printf("enter the max size of the queue\n");
    scanf("%d", &max);
    int ele;
    int n;
        printf("\t 1.insert \t 2.delete \t 3.display \t 4.exit\n");
    do
    {
        printf("choose from the above options\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("enter the element u want to insert\n");
            scanf("%d", &ele);
            enqueue(ele);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        }
    } while (n != 4);
    return 0;
}