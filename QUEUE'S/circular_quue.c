#include <stdio.h>
int front = -1;
int rear = -1;
int a[10];
int max;
//empty= front==-1
//full= (rear +1)%max=front
void enqueue(int n)
{
    if ((rear +1)%max==front)
    {
        printf("the queue is full\n");
    }
    else
    {
        if(front==-1)
    {
        front=0;
    }
    rear=(rear+1)%max;
        a[rear] = n;

    }
    
}
void dequeue()
{
    if ( (front==-1))
    {
        printf("the queue is empty\n");
         front=rear=-1;
    }
    else
    {
        if(front==rear)
        {
            printf("the element deleted is %d\n", a[front]);
            front=rear=-1;

        }
        else
        {         
        printf("the element deleted is %d\n", a[front]);
        front=(front+1)%max;
        }
    }
}
void display()
{
    if(front==-1)
    {
        printf("emty queue");
    }
    else if(front>rear)
    {
        for(int i=front;i<=max-1;i++)
        {
            printf("%d ",a[i]);
        }
        for(int i=0;i<=rear;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n ");

    }
    else
    {
        for (int i = front; i <= rear; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n ");
    }   
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