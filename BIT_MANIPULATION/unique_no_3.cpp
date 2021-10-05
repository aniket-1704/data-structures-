#include <iostream>
using namespace std;
int getbit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}
int setbit(int n, int pos)
{
    return (n | (1 << pos));
}
int main()
{
    int a[] = {1, 2, 3, 7, 1, 2, 3, 1, 2, 3}; //7
    int n = sizeof(a) / sizeof(a[0]);
    int result = 0;
    for (int i = 0; i < 64; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (getbit(a[j], i) == 1)
            {
                count++;
            }
            if (count % 3 != 0)
            {
                result = setbit(result, i);
            }
        }
    }
    cout << "unique number : " << result;
    return 0;
}