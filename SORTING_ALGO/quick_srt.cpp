#include <iostream>
using namespace std;
//best case if pivot is median :O(nlogn)
//worst case O(n^2)
int pivot(int a[],int l,int r)
{
    int piv=a[r];
    //fix pivot element as the last eleement of the array
    int i=l-1;
    //now shift all smaller elements than piv to left and bigger to the right
    for(int j=l;j<r;j++)
    {
        if(a[j]<piv)
        {
            i++;
            swap(a[i],a[j]);

        }
    }
    //till i all smaller elements accumulated
    swap(a[i+1],a[r]);
    return i+1;

}
void quicksort(int a[],int l,int r)
{
    if(l<r)
    {
        int pi=pivot(a,l,r);
        //send call to pivot and put an element in the correct pos
        //now sort rest of the array
        quicksort(a,l,pi-1);
        quicksort(a,pi+1,r);
    }
}
int main()
{
    int a[] = {6, 8, 3, 4, 9, 10, 1, 2};
    int n = sizeof(a) / sizeof(a[0]);
    quicksort(a,0,n-1);
    cout << "sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}