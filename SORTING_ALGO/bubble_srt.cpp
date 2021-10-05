#include <iostream>
using namespace std;
int main()
{
    int a[] = {68,23,10,69,12,66,03,16};
    int n = sizeof(a) / sizeof(a[0]);
    //in selections sort
    //repeatedly swap 2 elements if they are in the wrong order
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n - i-1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
           
        }
         for(int i=0;i<n;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
    }
    cout << "sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
