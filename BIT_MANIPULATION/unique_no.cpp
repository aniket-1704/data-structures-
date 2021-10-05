#include <iostream>
using namespace std;
//find a unique number except which all numbrs repeat once

//xor with the same number gives 0
int main()
{
    int a[]={1,2,3,4,1,2,3};
    int n=sizeof(a)/sizeof(a[0]);
    int xorsum=0;
    for(int i=0;i<n;i++)
    {
        xorsum=xorsum^a[i];
    }
    cout<<"unique number : "<<xorsum;   
    return 0;
}