#include <iostream>
using namespace std;
int main()
{
    int a[] = {1, 2, 3, 7, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int i = 0;
    int j = 0;
    int sum = 0;
    int S = 12;
    //traverse j till sum >=s
    //then treverse i till sum=s if not again do same
    while (j < n && sum + a[j] <= S)
    {
        sum += a[j];
        j++;
    }
    if (sum == S)
    {
        cout << i + 1 << " " << j + 1;
        return 0;
    }
    int st;
    int en;
    while (j < n)
    {
        sum += a[j];
        while (sum>S)
        {
            sum -= a[i];
            i++;
        }
        if (sum == S)
        {
            st = i + 1;
            en = j + 1;
            break;
        }
        j++;
    }
    cout<<st<<" "<<en;//2 4
    return 0;
}