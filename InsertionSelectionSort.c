#include <stdio.h>
#include<stdlib.h>

//Display function
void display(int b[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",b[i]);
    }
    printf("\n");
}

void insertionsort(int a[],int n){
    int val;
    for(int i=1;i<n;i++){
        val=a[i];
        int j=i-1;
        while(j>=0 && val < a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=val;

        printf("STEP %d :\n",i);
        display(a,n);
    }

    printf("The sorted order of insertion sort is:\n");
    display(a,n);
}

void selectionsort(int a[],int n){
    int temp,min;

    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;

        printf("STEP %d :\n",i+1);
        display(a,n);
    }
    printf("The sorted order of selection sort is: \n");
    display(a,n);
}

int main(){
      int choice;

    do{

    printf("Options are :\n");
    printf("1. INSERTION SORT \n 2.SELECTION SORT \n 3.EXIT \n");
    printf("Enter the choice:");
    scanf("%d",&choice);
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    switch(choice){
    case 1:
    printf("INSERTION SORT SELECTED \n");
    insertionsort(a,n);
    break;

    case 2:
        printf("SELECTION SORT SELECTED \n");
        selectionsort(a,n);
        break;

    case 3:
        exit(0);
    }
    }while(choice!=3);

    return 0;
}
