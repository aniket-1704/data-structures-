#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> /* for isdigit(char ) */
#include <string.h>
#define SIZE 100
char stack[100];
int top = -1;
void push(char n)
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
char peek()
{
    if (top < 0)
    {
        printf("stack under flow: invalid infix expression");
        getchar();
        exit(1);
    }
    else
    {
        return stack[top];
    }
}
char pop()
{
    char item;

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
    char st[100];
    printf("enter the expression\n");
    gets(st);
    int i = 0;
    while (st[i] != '\0')
    {
        if (st[i] == '(' || st[i] == '{' || st[i] == '[')
        {
            push(st[i]);
        }
        else if ((peek() == '(' && st[i] == ')') || (peek() == '{' && st[i] == '}') || (peek() == '[' && st[i] == ']'))
        {
            pop();
        }
        else
        {
        }
        i++;
    }
    if (isEmpty()==1)
    {
        printf("balanced parantesis");
    }
    else
    {
        printf("unbalanced parenthesis");
    }
}