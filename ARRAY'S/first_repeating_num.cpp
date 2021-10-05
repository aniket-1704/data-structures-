#include <iostream>
using namespace std;
int main()
{
    int a[]={1,2,3,4,5,4,6,9,6,8};
    int temp[1000]={0};
    int n=sizeof(a)/sizeof(a[0]);
    int index=n-1;
    //in temp array put value 1 if index never encountered else 
    //take minimum of index
    for(int i=n-1;i>=0;i--)
    {
        if(temp[a[i]]==1)
        {
            index=min(index,i);
        }
        else
        {
            temp[a[i]]=1;
        } 
    }
    cout<<"index of first repeating integer : "<<index;
    return 0;
}
