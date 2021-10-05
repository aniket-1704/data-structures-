#include <iostream>
using namespace std;
//suppose n:8(1000)
//n-1 is 7:0111
// n & n-1 is 0000
int power_of_2(int n)
{
    return (n & ~(n & n - 1));
}
int main()
{
    int n;
    cout << "enter a number " << endl;
    cin >> n;
    if (power_of_2(n) == n)
    {
        cout << " it is power of 2";
    }
    else
    {
        cout << "not a power of 2";
    }
    return 0;
}