#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// Function to return maximum XOR subset in set[]

class Solution
{
    public:
    void all_subarrays(vector<int> v,int &res,int index,vector<int> subarray)
    {
        if(index==v.size())
        {
            int n=subarray.size();
            int curr_xor=0;
            if(n!=0)
            {
            for(int i=0;i<n;i++)
            {
                curr_xor^=subarray[i];
            }
            res=max(res,curr_xor);
            }
            return;
        }
        
        all_subarrays(v,res,index+1,subarray);
        subarray.push_back(v[index]);
        all_subarrays(v,res,index+1,subarray);
    }
    int maxSubarrayXOR(int a[], int n)
    {
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(a[i]);
        }
        int res=0;vector<int> s;
        all_subarrays(v,res,0,s);
        return res;
    }
};

// { Driver Code Starts.
int main()
{

    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
       scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        Solution obj;
        printf("%d\n",obj.maxSubarrayXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;
    }
}  // } Driver Code Ends