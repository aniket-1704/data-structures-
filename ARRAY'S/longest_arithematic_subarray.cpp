#include <iostream>
using namespace std;
int main()
{
    //longest sub array for which common diff among 2 consec elements
    int a[]={10,7,4,6,8,10,11};
    int prevdiff=a[1]-a[0];
    int arr[7];
    int c=0;
    int count=2;
    //storing length of all sub arrays and then finding maximum in that array
    for(int i=2;i<7;i++)
    {
        if(prevdiff!=(a[i]-a[i-1]))
        {
            prevdiff=a[i]-a[i-1];
            arr[c++]=count;
            count=2;     
        }
        else
        {
            count++;
        }
    }
    arr[c++]=count;
    int maxi=0;
    for(int i=0;i<c;i++)
    {
        cout<<arr[i]<<endl;
    }
    for(int i=1;i<c;i++)
    {
        maxi=max(arr[i],arr[i-1]);
    }
    cout<<maxi;
    //subarrays:nC2 + n
    //subsequence:2^n
    return 0;
}