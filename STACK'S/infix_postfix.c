#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> /* for isdigit(char ) */
#include <string.h>
#define SIZE 100
char stack[100];
int top=-1;
void push(char n)
{       
       if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = n;
	}   
}
char pop()
{
       char item ;

	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
		getchar();
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}
int is_operator(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void infixtopostfix(char infix[], char postfix[])
{
    int i = 0;
    int j = 0;
    push('(');                               /* push '(' onto stack */
	strcat(infix,")");
    char item = infix[0];
    while (item != '\0')
    {
        if (item == '(')
        {
            push(item);
        }
        else if (isdigit(item) || isalpha(item))
        {
            postfix[j] = item;
            j++;
        }
        else if (item == ')')
        {
            char x = pop();
            while (x != '(')
            {
                postfix[j] = x;
                x = pop();
                j++;
            }
        }
        else if(is_operator(item)==1)
        {

            char y = pop();
            while (is_operator(y) == 1 && precedence(y) >= precedence(item))
            {
                postfix[j] = y; /* so pop all higher precendence operator and */
                j++;
                y = pop(); /* add them to postfix expresion */
            }
            push(y);

            push(item);
        }
        else
        {
            	printf("\nInvalid infix Expression.\n");
        }
        
        i=i+1;
        item = infix[i];
    }
    postfix[j] = '\0';
}
int main()
{
    
    char infix[100];
    char postfix[100];
    printf("enter the infix expression\n");
    gets(infix);
    infixtopostfix(infix, postfix);
    printf("postfix expression\n");
    puts(postfix);
}