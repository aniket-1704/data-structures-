#include <iostream>
using namespace std;
int main()
{
    //elements 0 to 5 are present
    //find first missing positive number
    int a[]={0,-9,1,3,-4,5};//2 and 4 missing so thse positions in arr will become false
    //       T  T F T  F  T
    int n = sizeof(a) / sizeof(a[0]);
    bool arr[n]={false};
    for(int i=0;i<n;i++)
    {
        if(a[i]>=0)
        {
          arr[a[i]]=true;
        }      
    }
    for(int i=1;i<n;i++)
    {
        if(arr[i]==false)
        {
            cout<<i;//2
            break;
        }
    }

    return 0;
}