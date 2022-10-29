#include <stdio.h>
#include <stdlib.h>

void display(int bucket[],int m,int arr[],int n){
    for (int i = 0; i < m; i++) {
        printf("%d\t",i);
    }
    printf("\n");
    
    for (int i = 0; i < m; i++) {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void search(int bucket[],int m,int val){
    int flag=0;
    for (int i = 0; i < m; i++) {
        if(bucket[i]==val){
            flag=1;
            break;
        }
    }
    if(flag){
      printf("Element found \n");  
    }
    else{
        printf("element not found");
    }
}

void insert(int bucket[],int m,int arr[],int n){
    
    //loop arrsize
    for (int i = 0; i < n; i++) {
        int hv= arr[i] %m;
        
        if(bucket[hv]==-1){
            bucket[hv]=arr[i];
        }
        else{
            //loop tsize
            for (int j = 0; j < m; j++) {
                int hv2 = (hv + j*j)%m;
                
                if(bucket[hv2]==-1){
                    bucket[hv2]= arr[i];
                    break;
                }
            }
        }
    }
}


int main()
{
    int m;
    printf("Size of bucket is:");
    scanf("%d",&m);
    int bucket[m];
    
    for (int i = 0; i < m; i++) {
        bucket[i]=-1;
    }
    
    int n;
    printf("Size of array is:");
    scanf("%d",&n);
    int arr[n];
    
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }

    int choice,val;
    do{
        printf("Options are: \n 1.Insert \n 2.display \n 3.search\n 4.Exit \n");
        printf("Enter choice:");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
            insert(bucket,m,arr,n);
            break;
            
            case 2:
            display(bucket,m,arr,n);
            break;
            
            case 3:
            printf("enter number to search:");
            scanf("%d",&val);
            search(bucket,m,val);
            break;
            
            case 4:
            exit(0);
            break;
            
            default:
            printf("Invalid choice");
        }
    }while(choice!=4);
    
    return 0;
}
