#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int r=100;
const int c=100;
void fill(int img[r][c],int sr,int sc,int color,int newcolor)
{
    if(img[sr][sc]!=color || sr<0 || sc<0)
    {
        return;
    }
    img[sr][sc]=newcolor;
    fill(img,sr+1,sc,color,newcolor);
    fill(img,sr-1,sc,color,newcolor);
    fill(img,sr,sc+1,color,newcolor);
    fill(img,sr+1,sc-1,color,newcolor);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int sr;
    int sc;
    int newcolor;
    cin>>sr;
    cin>>sc;
    cin>>newcolor;
    int color=a[sr][sc];
    if(a[sr][sc]==newcolor)
    {
        for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    }
    else
    {
        fill(a,sr,sc,color,newcolor);
         for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    }
}