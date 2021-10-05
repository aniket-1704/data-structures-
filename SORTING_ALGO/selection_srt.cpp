#include <iostream>
using namespace std;
int main()
{
    int a[] = {6, 8, 3, 4, 9, 10, 1, 2};
    int n = sizeof(a) / sizeof(a[0]);
    //in selections sort
    //find minimum element in the array and
    //swap it with the first element in the array
    int min = 0;
    int min_indx = 0;
    for (int i = 0; i < n - 1; i++)
    {
        min = a[i + 1];
        min_indx = i + 1;
        for (int j = i + 1; j < n; j++)
        {

            if (a[j] < min)
            {
                min = a[j];
                min_indx=j;
            }
        }
        if (a[i] > min)
        {
            int temp=a[i];
            a[min_indx]=temp;
            a[i]=min;
        }
    }
    cout << "sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}