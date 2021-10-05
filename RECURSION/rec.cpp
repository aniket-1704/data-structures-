#include <iostream>
using namespace std;
//smallest element
int rec(int a[],int begin,int end)
{
    if(begin==end)
    {
        return a[begin];
    }
    int mid=(end+begin)/2;
    int x=rec(a,begin,mid);
    int y=rec(a,mid+1,end);
    if(x<y)
    {
        return x;
    }
    else
    {
        return y;
    }

}
int main()
{
    int arr[]={5,7,19,6,2,3,67,87};
    int x=rec(arr,0,4);
    cout<<x;

return 0;
}