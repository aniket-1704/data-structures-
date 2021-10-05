#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> /* for isdigit(char ) */
#include <string.h>
#define SIZE 100
char stack[100];
int top = -1;
void push(char ch)
{
    if (top >= SIZE - 1)
    {
        printf("\nStack Overflow.");
    }
    else
    {
        top = top + 1;
        stack[top] = ch;
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
int isPalindrome(char str[])
{
    int length = strlen(str);
    // Finding the mid
    int i, mid = length / 2;

    for (i = 0; i < mid; i++)
    {
        push(str[i]);
    }
    // Checking if the length of the string
    // is odd, if odd then neglect the
    // middle character
    if (length % 2 != 0)
    {
        i++;
    }
    // While not the end of the string
    while (str[i] != '\0')
    {
        char ele = pop();

        // If the characters differ then the
        // given string is not a palindrome
        if (ele != str[i])
            return 0;
        i++;
    }

    return 1;
}
int main()
{
    char st[100];
    printf("enter the word \n");
    gets(st);
    if(isPalindrome(st))
    {
        printf("it is a palindrome");
    }
    else
    {
        printf("not a palindrome");
    }   
}