#include <stdio.h>
#include <stdlib.h>

void display(int arr[],int m){
    for(int i=0;i<m;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int largest(int a[]){
    int larger=a[0];

    for(int i=1;i<10;i++){
        if(a[i]>larger){
            larger=a[i];
        }
    }
    return larger;
}

void radix(int a[],int n){
    int bucket[10][10],bucket_count[10];
    int i,j,k,rem,NOP=0,divisor=1,larger,pass;
    
    //highest num
    larger=largest(a);
    //count of highest num
    while(larger>0){
        NOP++;
        larger/=10;
    }

    for(pass=0;pass<NOP;pass++){
        //initialising empty with 0
        for(i=0;i<10;i++){
            bucket_count[i]=0;
        }

        for(i=0;i<10;i++){
            rem=(a[i]/divisor)%10;
            bucket[rem][bucket_count[rem]] = a[i];
            bucket_count[rem] += 1;
        }
        i=0;
        for(k=0;k<10;k++){
            for(j=0;j<bucket_count[k];j++){
                a[i]=bucket[k][j];
                i++;
            }
        }
        divisor *=10;
    }
    printf("Display sort\n");
    display(a,n);
}

int main(){
    int n;
    printf("Enter size:");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements \n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Display before\n");
    display(a,n);

    radix(a,n);

    return 0;
}
