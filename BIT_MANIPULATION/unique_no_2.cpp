#include <iostream>
using namespace std;
//find a unique number except which all numbrs repeat once
int getbit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}
//xor with the same number gives 0
int main()
{
    int a[] = {1, 2, 3, 7, 5, 1, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ a[i];
    }
    //we have 7^5 in xorsum which is 111^101=010
    //let us find the rightmost first setbit of xorsum
    int pos = 0;
    while (getbit(xorsum, pos) != 1)
    {
        pos++;
    }
    //we have pos=1
    int tempxor=xorsum;
    xorsum = 0;
    //find xorsum of all with bit of pos 1 as 1 thus we will get 7
    for (int i = 0; i < n; i++)
    {
        if (getbit(a[i], pos))
        {
            xorsum = xorsum ^ a[i];
        }
    }
    int newxor=0;
    newxor=xorsum^tempxor;
    cout << "unique numbers : " << xorsum<<" "<<newxor;
    return 0;
}