//u have a weight array
//u have a value array
//they represent items that a thief needs to rob
//fill the bag such tht weight of items doesnt exceed weight of bag annd the value is maximum
#include <iostream>
using namespace std;
int knapsack(int value[],int weight[],int n,int W)
{
    if(n==0 || W==0)
    {
        return 0;
    }
    if(weight[n-1]>W)
    {
        return knapsack(value,weight,n-1,W);//not including item;     
    }
    //either include item or not
    return max((knapsack(value,weight,n-1,W-weight[n-1])+value[n-1]),knapsack(value,weight,n-1,W));
    
}
int main()
{
    int wt[]={10,20,30};
    int value[]={100,50,150};
    int W=50;
    cout<<knapsack(value,wt,3,W);
    return 0;
}
