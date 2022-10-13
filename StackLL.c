#include<stdio.h>
#include<stdlib.h>

//Stack using LL with double pointer.
struct stack {
    int data;
    struct stack *next;
};

int isempty(struct stack *top) {
    if(top==NULL) {
        return 1;
    }
    return 0;
}

void display(struct stack *top) {
    if(top==NULL) {
        printf("No elements present\n");
        return;
    }
    while(top!=NULL) {
        printf("%d ",(top)->data);
        top=(top)->next;
    }
    printf("\n");
}
//somewhat LL INSERT AT HEAD
//top is at start always so that deletion becomes O(1)
//if we insert at end then delete will take O(n)
void push(struct stack **top,int val) {
    //new node
    struct stack *n =(struct stack *)malloc(sizeof(struct stack));

    n->data =val;
    n->next =*top;
    *top =n;
}

//somewhat LL DELETE AT HEAD
void pop(struct stack **top) {
    //temp
    struct stack *temp;
    if(*top==NULL) {
        printf("Stack Underflow\n");
    }
    else {
        temp=*top;
        *top=(*top)->next;

        int x;
        x=temp->data;
        printf("Popped Element is :%d\n",x);
        //temp->next =NULL;temp=NUll;
        free(temp);

    }
}

int main() {
    struct stack *top =NULL;
    int choice,val;
    printf("1.Display\n2.Push\n3.Pop\n4.Exit\n");

    do {
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice) {
        case 1:
            display(top);
            break;
        case 2:
            printf("Enter push element :");
            scanf("%d",&val);
            push(&top,val);
            break;
        case 3:
            pop(&top);

            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Choice\n");
        }
    }   while(choice != 4);
    return 0;
}
