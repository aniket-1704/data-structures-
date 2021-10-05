#include <iostream>
#include <climits>
using namespace std;
//another way to solve max sum subarray
int kadanes_algo(int a[], int n)
{
    int max_sum = INT_MIN;
    int currsum = 0;
    for (int i = 0; i < n; i++)
    {
        currsum += a[i];
        if (a[i] < 0)
        {
            currsum = 0;
        }
        max_sum = max(currsum, max_sum);
    }
    return max_sum;
}
int main()
{
    //in this algorithm
    //take cumulative sum of the array but
    //if number is negative put 0
    int a[] = {4,-4,6,-6,10,-11,12};
    //here wrapping is needed
    //subarray with max sum is strating from 12 and ending at 10
    //METHOD
    //change sign of elements then apply kadenes algo
    //the max sum now obtained subtract that element in the sum of original array
    int n = sizeof(a) / sizeof(a[0]);
    int nonwarp=kadanes_algo(a,n);
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        arr[i]=-a[i];
    }
    int non_rq_elements_sum=kadanes_algo(arr,n);
    int wrap=sum+non_rq_elements_sum;
    int maxsum=max(wrap,nonwarp);
    cout<<"maximum sum:"<<maxsum;//22
    return 0;
}