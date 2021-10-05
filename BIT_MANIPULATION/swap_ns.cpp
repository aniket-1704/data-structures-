#include <iostream>
using namespace std;
int main()
{
    int a=5;
    int b=10;
    //a=a+b  15
    //b=a-b  5
    //a=a-b  10
    
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<a <<" "<<b;
    return 0;
}