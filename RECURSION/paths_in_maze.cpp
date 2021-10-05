#include <iostream>
using namespace std;
//a n*n dimensional maze
//find no. of paths from 0,0 to n-1,n-1
int pathinmaze(int n,int i,int j)
{
    if(i==n-1 && j==n-1)
    {
        return 1;
    }
    if(i>=n || j>=n)
    {
        return 0;
    }
    return pathinmaze(n,i+1,j)+pathinmaze(n,i,j+1);
    //i+1 move 1 step to right OR
    //j+1 move 1 step downwards
}
int main()
{
    //dimensions of maze
    cout<<pathinmaze(3,0,0);
    return 0;
}