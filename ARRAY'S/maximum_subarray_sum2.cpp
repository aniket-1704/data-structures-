#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int a[] = {-1,4,7,2};
    //cumsum:   -1 3 10 12
    //sum of subarray [4 7 2] is 12 - (-1)=13
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum=INT_MIN;
    cout<<"all subarrays of aray"<<endl;
    //O(n^2)
    int cum_sum[n];
    cum_sum[0]=a[0];
    //cumulative sum array
    for(int i=1;i<n;i++)
    {
        cum_sum[i]=a[i]+cum_sum[i-1];
    }
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<=i;j++)
        {
            sum=cum_sum[i]-cum_sum[j];
            max_sum=max(max_sum,sum);
        }
    }
    cout<<"max sum :"<<max_sum;
    return 0;
}