#include <stdio.h>
#define max(x,y) (x>=y)?x:y
#define min(x,y) (x<y)?x:y

int findMaxRec(int a[], int n)
{
    if (n == 1)
    {
        return a[0];
    }

    return max(a[n - 1], findMaxRec(a, n - 1));
}
int findMinRec(int a[], int n)
{
    if (n == 1)
    {
        return a[0];
    }

    return min(a[n - 1], findMinRec(a, n - 1));
}
int main()
{
    int n;
    printf("enter the size of the array\n");
    scanf("%d", &n);
    int a[n];
    printf("enter the elements in the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("the array is:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("the maximum element in the array is : ");
    printf("%d\n",findMaxRec(a,n));
    printf("the minimum element in the array is : ");
    printf("%d",findMinRec(a,n));
}