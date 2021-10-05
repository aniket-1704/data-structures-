#include <iostream>
using namespace std;
int main()
{
    int a[]={1,2,3,4,5};
    int count=0;
    for(int i=0;i<5;i++)
    {
        for(int j=i;j<5;j++)
        {
           count++;   
        }
    }
    cout<<count;
    //subarrays:nC2 + n
    return 0;
}