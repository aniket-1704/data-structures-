#include <iostream>
#include <climits>
using namespace std;
//another way to solve max sum subarray
int main()
{
    //in this algorithm
    //take cumulative sum of the array but
    //if number is negative put 0
    int a[] = {1,2,3,-2,5};
    int max_sum=INT_MIN;
    //         1   0  3   0  3  8
    int n = sizeof(a) / sizeof(a[0]);
    std::cout<<"all subarrays of aray"<<endl;
    //O(n^3)
    int currsum=0;
    for(int i=0;i<n;i++)
    {
        currsum+=a[i];
        if(a[i]<0)
        {
            currsum=0;
        } 
        max_sum=max(currsum,max_sum); 
    }
    std::cout<<"max sum :"<<max_sum;
    return 0;
}