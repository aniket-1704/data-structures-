#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int a[] = {1, 2, 3, 7, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum=INT_MIN;
    cout<<"all subarrays of aray"<<endl;
    //O(n^3)
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum=0;
            for(int k=i;k<=j;k++)
            {
                //all subarrays generated
                sum+=a[k];
            }
            max_sum=max(max_sum,sum);
        }
    }
    cout<<"max sum :"<<max_sum;
    return 0;
}