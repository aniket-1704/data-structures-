#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;

int minjumps(int a[],int n)
{
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=INT_MAX;
    }
    arr[0]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]!=INT_MAX && (a[j] + j>=i))
            {
                if(arr[j] + i<arr[i])
                {
                    arr[i]=arr[j]+1;
                }
            }
        }
    }
    if(arr[n-1]!=INT_MAX)
    {
        return arr[n-1];
    }
    else
    {
        return -1;
    }
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int n;
    cin>>n;
     int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<minjumps(a,n);
    return 0;
}