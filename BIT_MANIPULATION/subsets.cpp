#include <iostream>
using namespace std;
int getbit(int n,int pos)
{
    return ((n & (1<<pos))!=0);
}
int main()
{
    char c[]={'a','b','c'};
    int n=sizeof(c)/sizeof(c[0]);
    //subsets are 0 to 2^n-1 000 001 ... 111
    //1<<n is 2^n
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            if(getbit(i,j))
            {
                cout<<c[j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}