#include <stdio.h>

// “Bubble” the largest value to the right end
// using pair-wise comparisons and swapping
// worst case O(n^2) and best case O(n)...for exchange O(n^2) and best case O(1)
int main()
{

    int a[] = {11, 8, 4, 6, 2, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int check = 1, temp, pass = 0;

    for (int i = 0; i < n - 1; i++)
    { // no of passes
        check = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                check = 1;
            }
        }
        //pass++; // no of time outer loop run
        if (check == 0)
        {
            break;
        }
    }
    //printf("loop time is %d\n", pass); // n-1 worst case
    printf("The sorted order is:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d \t", a[i]);
    }
    return 0;
}