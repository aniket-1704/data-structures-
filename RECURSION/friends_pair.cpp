//pair friends such that a friend can remain single or be paired up
#include <iostream>
using namespace std;
int friends_pair(int n)
{
    if(n==0 || n==1 || n==2)
    {
        return n;
    }
    return friends_pair(n-1) +friends_pair(n-2)*(n-1);
    //2 options
    //1
    //leave alone so n-1 left
    //2
    //pair up have n-1 choices and n-2 left
}
int main()
{
    cout<<friends_pair(4);
    return 0;
}