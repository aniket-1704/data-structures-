#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> /* for isdigit(char ) */
#include <string.h>
#define SIZE 100
char stack[100];
int top=-1;
void push(int n)
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
int pop()
{
       int item ;

	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
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
int postfix_eval(char postfix[])
{
    int i=0;
    char item=postfix[i];
    int postf=0;
    while(item!='\0')
    {
        if(is_operator(item)==1)
        {
            int a=pop();
            int b=pop();
            switch(item)
            {
                case '+':
                postf=b+a;
                break;
                case '-':
                postf=b-a;
                break;
                case '*':
                postf=b*a;
                break;
                case '/':
                postf=b/a;
                break;
                case '^':
                postf=b^a;
                break;

            }
            push(postf);
        }
        else
        {
           
           push(item-'0');
        }
        i=i+1;
        item=postfix[i];
        
    }
    return pop();

}
int main()
{
    char postfix[100];
    printf("enter the postfix expression\n");
    gets(postfix);
    printf("after evelauating we get\n");
    printf("%d",postfix_eval(postfix));

}