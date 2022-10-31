#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct queue
{
    int items[SIZE];
    int front,rear;
}s;

int isFull(){
    if (s.rear==SIZE-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(s.front==s.rear){
        return 1;
    }
    return 0;
}

void enqueue(){
    if(s.rear==SIZE-1){
        printf("queue is full\n");
        return;
    }

    s.rear++;
    int x;
    printf("enter the input to enque:\n");
    scanf("%d",&x);
    s.items[s.rear]=x;

}

void dequeue(){
    if(s.rear==s.front){
        printf("Queue empty\n");
        return;
    }
    int a=s.items[s.front+1];
    printf("Removed element is :%d\n",a);

    for(int i = s.front+1; i < s.rear ; i++) {
            s.items[i] = s.items[i+1];
        }

    s.rear--;
}

void display(){
    if(s.rear==s.front){
        printf("queue empty\n");
        return;
    }
    printf("Queue is :\n");
    for(int i=s.front+1;i<=s.rear;i++){
        printf("Elements no %d is :%d\n",i,s.items[i]);
    }
}

int main()
{
    s.front=-1;
    s.rear=-1;

    int choice;

    do{
    printf("\n\nOptions are 1.Enqueue 2.Dequeue 3.display 4.full 5.exit \n Enter the choice \n");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
        printf("Enqueue operation is selected\n");
        enqueue();
        break;

        case 2:
        printf("dequeue operation is selected\n");
        dequeue();
        break;

        case 3:
        printf("display operation is selected\n");
        display();
        break;

        case 4:
        printf("full operation is selected\n");
        int a=isFull();
        if(a){
            printf("full \n");
        }
        break;

        case 5:
        printf("exit operation is selected\n");
        exit(0);
        break;

        default:
        printf("invalid option\n");
        break;
    }
 }while(choice!=5);


    return 0;
}
