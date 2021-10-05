#include <stdio.h>
void towerOfHanoi(int n, char from, char to, char mid) 
{ 
    if (n == 1) 
    { 
        printf("\n Move disk 1 from rod %c to rod %c", from, to); 
        return; 
    } 
    towerOfHanoi(n-1, from, mid, to); 
    printf("\n Move disk %d from rod %c to rod %c", n, from, to); 
    towerOfHanoi(n-1, mid, to, from); 
} 
  
int main() 
{
    int n;
    printf("enter the number of discs\n");
    scanf("%d",&n); // Number of disks 
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods 
}