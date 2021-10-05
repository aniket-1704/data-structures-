#include <iostream>
using namespace std;
int main()
{
    //if array not sorted then sort it
    int a[] = {2,4,11,14,16,20,21};
    int k=31;
    int n = sizeof(a) / sizeof(a[0]);
    int low=0;
    int high=n-1;
    while(high!=low)
    {
        if(a[low]+a[high]>k)
        {
            high--;
        }
        else if(a[low]+a[high]<k)
        {
            low++;
        }
        else
        {
            break;
        }  
    }
    cout<<"elements : "<<low+1<<" and "<<high+1;
    return 0;
}