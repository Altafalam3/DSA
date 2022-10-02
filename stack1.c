#include <stdio.h>
#include<stdlib.h>

//STACK USING ARRAYS BY GLOBAL PTR APPROACH
#define SIZE 5

struct stack{
    int items[SIZE];
    int top;
};

struct stack s;

void push(){
    if(s.top==SIZE-1){
        printf("STACK FULL\n");
        return;
    }
    s.top++;
    int x;
    printf("Enter the element to push:\n");
    scanf("%d",&x);
    s.items[s.top]=x;
    return;
}

void pop(){
    if(s.top==-1){
        printf("STACK EMPTY\n");
        return;
    }
    int r=s.items[s.top];
    printf("Element removed is :%d\n",r);
    s.top--;
}

void display(){
    if(s.top==-1){
        printf("STACK EMPTY\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = s.top; i >= 0; i--){
        printf("element at position %d is %d\n",i,s.items[i]);
    }

}

void peak(){
    if(s.top==-1){
        printf("STACK EMPTY\n");
        return;
    }
    int r=s.items[s.top];
    printf("Element at top is :%d\n",r);

}

int main(){
    s.top=-1;
    int choice;

    do{
    printf("Options are 1.push 2.pop 3.display 4.peak 5.exit \n Enter the choice \n");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
        printf("Push operation is selected\n");
        push();
        break;

        case 2:
        printf("Pop operation is selected\n");
        pop();
        break;

        case 3:
        printf("display operation is selected\n");
        display();
        break;

        case 4:
        printf("peak operation is selected\n");
        peak();
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