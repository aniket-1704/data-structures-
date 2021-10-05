#include <stdio.h>
    int top=-1;
    int a[100];
    int n;
void push(int x)
{
    if(top==n-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        a[++top]=x;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("stack underflow\n");
    }
       return a[top--]; 
    
    
}
void display()
{
    if(top==-1)
    {
        printf("stack underflow\n");
    }
    for(int i=0;i<=top;i++)
    {
        printf(" %d ",a[i]);
    }
    printf("\n");
}
void peak()
{
    if(top==-1)
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("%d\n",a[top]);
    }
}
void peep(int pos)
{
    if(pos-1>top)
    {
        printf("not accessible");
    }
    else
    {
        printf("%d\n",a[pos-1]);
    }
}
int main()
{
    printf("enter the stack size\n");
    scanf("%d",&n);
    int a[n];
    int x;
    int pos;
    int choose;
        printf(" \t 1.peep\t 2.pop  \t 3.display \t 4.push \t 5.exit\n");
    do
    {
        printf("choose from the above options\n");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            printf("enter the position of the elemet\n");
            scanf("%d", &pos);
            peep(pos);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("enter the element u want to insert\n");
            scanf("%d", &x);
            push(x);
        }
    } while (n != 5);
    return 0;    
}

