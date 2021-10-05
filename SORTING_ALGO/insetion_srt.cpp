#include <iostream>
using namespace std;
int main()
{
    int a[] = {6, 8, 3, 4, 9, 10, 1, 2};
    int n = sizeof(a) / sizeof(a[0]);
    //in selections sort
    //insert the current element in the correct position
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (a[j] < a[j - 1] && j >= 1)
        {
            int temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;
            j--;
        }
    }



    cout << "sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}