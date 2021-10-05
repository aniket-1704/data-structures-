#include <iostream>
using namespace std;
//to get bit at a position of a number
//<< is left shift operator shifts the bits to the left
//<< number gives a 1 bit at the number position
int getbit(int n,int pos)
{
    return ((n & (1<<pos))!=0);
    //for eg:
    //bit of 6 at pos 2
    //6 is 110 and 1<<2 is 100
    //now 110 & 100 will give 100
    //bit is1
}
int setbit(int n,int pos)
{
    return (n | (1<<pos));
}
int clearbit(int n,int pos)
{
    int mask=~(1<<pos);
    return (n & mask);
}
int main()
{
    int num;
    cout<<"enter a number "<<endl;
    cin>>num;//8
    cout<<getbit(num,3);


    return 0;
}