#include <iostream>
using namespace std;
//this code is same for the tiling problem
//no of ways a tile of 2*1 dimensions can fit a floor of 2*n dimensions
int fibbo(int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    return fibbo(n-1)+fibbo(n-2);
}
int main()
{
    int n;
    cout<<"enter term which u want"<<endl;
    cin>>n;
    cout<<fibbo(n-1);
    return 0;
}