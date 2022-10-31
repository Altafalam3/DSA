#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];//B[high+1]
    i = low;
    j = mid + 1;
    k = low;
    
   //next array reach k pehle tak
    while (i <= mid && j <= high)
    {   
        //dono array ka element compare kaunsa chota h
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++; //i ka chota toh i++ varna vice versa
            k++;
        }
        
        //idhar j ka chota h
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    
    //agar 1 array khtm dusra nahi
    //toh remaining elements print krvane function
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    
    //same upar ka comment
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    
    //B ke saare element A mai copy kr lo sort mil jaye taki
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void mergeSort(int A[], int low, int high){
    int mid; 
    if(low<high){
        //middle
        mid = (low + high) /2;
        
        //aadha aadha sort kro fhir merge kro
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    mergeSort(A, 0, 6);
    printArray(A, n);
    return 0;
}
