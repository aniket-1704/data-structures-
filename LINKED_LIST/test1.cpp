#include <iostream>
using namespace std;
int funct(int m=10,int n)
{
    int c=m+n;
    return c;
}
int main()
{
    cout<<funct(5);
}
//compile time error
