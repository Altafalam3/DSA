#include <stdio.h>
#include <stdlib.h>

//Queue using LL with double ptr
typedef struct node {
    int data;
    struct node * next; // self referencing structure
}node;

void enqueue(node **f,node **r,int val){
   //NEW NODE
   node *n=(node *)malloc(sizeof(node));
   //Not necessary condition to check ,memory allocate nhi hua
   if(n==NULL){
      printf("Queue overflow\n");
      return;
   }
   n->data=val;
   n->next=NULL;
   //Agar front NULL h toh rear bhi NULL hi hoga pakka
   if(*f==NULL){
      *f=*r=n;
   }
   else{
      (*r)->next=n;
      *r=n;
   }
}

void display(node *f)
{
    struct node *temp=f;
    if(f==NULL){
      printf("Queue Empty\n");
      return;
    }
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void dequeue(node **f){
   node *temp=(node *)malloc(sizeof(node));

   if(*f==NULL){
      printf("Queue empty\n");
      return;
   }
   int x;
   temp=*f;
   //shift front to next
   *f=(*f)->next;

   x=temp->data;
   printf("Deleted element is %d",x);
   free(temp);
}

int main(){
   node *f=NULL;
   node *r=NULL;

   int choice,val;

    do{
    printf("\n\nOptions are 1.Enqueue 2.Dequeue 3.display 4.exit \n Enter the choice:");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
        printf("Enqueue operation is selected\n");
      printf("Enter the element to insert:");
      scanf("%d",&val);
        enqueue(&f,&r,val);
        break;

        case 2:
        printf("dequeue operation is selected\n");
        dequeue(&f);
        break;

        case 3:
        printf("display operation is selected\n");
        display(f);
        break;

        case 4:
        printf("exit operation is selected\n");
        exit(0);
        break;

        default:
        printf("invalid option\n");
        break;
    }
 }while(choice!=4);



   return 0;
}