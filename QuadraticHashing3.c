#include <stdio.h>
#include <stdlib.h>

void display(int bucket[],int m) {
    for (int i = 0; i < m; i++) {
        printf("%d\t",i);
    }
    printf("\n");

    for (int i = 0; i < m; i++) {
        printf("%d\t",bucket[i]);
    }
    printf("\n");
}

//searching less time wala
void search(int bucket[],int m,int val) {
    int flag=0;
    
    int hv= val %m;
    
    if(bucket[hv]==val) {
        flag=1;
    }
    else {
        //loop tsize
        for (int j = 0; j < m; j++) {
            int hv2 = (hv + j*j)%m;

            if(bucket[hv2]==val) {
                flag=1;
                break;
            }
        }
    }     
    
    if(flag) {
        printf("Element found \n");
    }
    else {
        printf("Element not found\n");
    }
}

void insert(int bucket[],int m,int val) {
    int hv= val %m;
    int check=0;
    if(bucket[hv]==-1) {
        bucket[hv]=val;
        return;
    }
    else {
        //loop tsize
        for (int j = 0; j < m; j++) {
            int hv2 = (hv + j*j)%m;

            if(bucket[hv2]==-1) {
                bucket[hv2]= val;
                check=1;
                break;
            }
        }
    }
    if(check==0){
        printf("Cannot insert \n");
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


    int choice,val;
    do {
        printf("Options are: \n 1.Insert \n 2.display \n 3.search\n 4.Exit \n");
        printf("Enter choice:");
        scanf("%d",&choice);

        switch(choice) {
        case 1:
            printf("enter number to insert:");
            scanf("%d",&val);
            insert(bucket,m,val);
            break;

        case 2:
            display(bucket,m);
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
    } while(choice!=4);

    return 0;
}
    
