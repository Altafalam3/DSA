#include <stdio.h>

//1st ko khada kro ,usse chote ko uske left mai dalo
//usse bade ko uske right mai arrange kro

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    //first element pivot(1st khada kro vala)
    int pivot = A[low];

    //ek aage se i start krte the pivot se
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        //last walaa bada toh next dekho --
        while (A[j] > pivot)
        {
            j--;
        }

        //swap a[i] a[j]
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j; //return high
}

//class teacher main miss
void quickSort(int A[], int low, int high)
{
    int partitionIndex;

    //run recursively until it has greater than 1 element
    if (low < high)
    {
        //find Index of pivot after partition
        partitionIndex = partition(A, low, high);

        quickSort(A, low, partitionIndex - 1);  // sort left subarray 
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    //int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int A[] = {9, 4, 4, 8, 7, 5, 6};
    // 3, 5, 2, 13, 12, 3, 2, 13, 45
    // 3, 2, 2, 13i, 12, 3j, 5, 13, 45
    // 3, 2, 2, 3j, 12i, 13, 5, 13, 45 --> first call to partition returns 3
    int n = 9;
    n =7;
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}
