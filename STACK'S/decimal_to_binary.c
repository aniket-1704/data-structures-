#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> /* for isdigit(char ) */
#include <string.h>
#define SIZE 100
char stack[100];
int top = -1;
void push(int n)
{
    if (top >= SIZE - 1)
    {
        printf("\nStack Overflow.");
    }
    else
    {
        top = top + 1;
        stack[top] = n;
    }
}
int pop()
{
    int item;

    if (top < 0)
    {
        printf("stack under flow: invalid infix expression");
        getchar();
        exit(1);
    }
    else
    {
        item = stack[top];
        top = top - 1;
        return (item);
    }
}
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int decimal;
    printf("enter the decimal number\n");
    scanf("%d", &decimal);
    printf("the binary form is \n");
    int n = decimal;
    while (n > 0)
    {
        push(n % 2);
        n = n / 2;
    }
    while (isEmpty() == 0)
    {
        printf("%d", pop());
    }
}