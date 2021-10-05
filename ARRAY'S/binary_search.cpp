#include <iostream>
using namespace std;
//binary search is fr sorted array
int binary_search(int a[], int l, int r, int find)
{
    int mid = (l + r) / 2;
    if (l < r)
    {

        if (find > a[mid])
        {
            binary_search(a, mid + 1, r, find);
        }
        else if (find < a[mid])
        {
            binary_search(a, l, mid, find);
        }
        else
        {
            return mid + 1;
        }
    }
    else
    {
        return -1;
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 7, 8, 10};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "array is :";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    int ele;
    cout << endl
         << "enter element u want to find" << endl;
    cin >> ele;
    cout << "element found at position :" << binary_search(a, 0, n - 1, ele);

    return 0;
}