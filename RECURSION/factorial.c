#include <stdio.h>
int factorial(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n*factorial(n-1);
    } 
}
int main()
{
    int n;
    printf("enter a number\n");
    scanf("%d",&n);
    printf("factorial of the number is : %d",factorial(n));

}