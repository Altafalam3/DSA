#include <stdio.h>
#include <stdlib.h>
//SORTED LINKEDLIST

struct node
{
    int data;
    struct node *next;
};

struct node* insert(struct node *head,int num)
{
    struct node *temp;
    temp=head;
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=num;
    new->next=NULL;
    //insert at first conditions
    if(temp==NULL||head->data>=num)
    {
        new->next=head;
        head=new;
        //return head;
    }
    //other positions insert
    else
    {
        while(temp->next!=NULL&&temp->next->data<num)
        {
            temp=temp->next;
        }
        new->next=temp->next;
        temp->next=new;
        //return head;
    }
    return head;
}

struct node* del(struct node *head,int num)
{
    struct node *temp,*node2del;
    temp=head;
    if(temp==NULL){
        printf("EMPTY LL\n");
        //return head;
    }
    else
    {
        //delete at first
        if(temp->data==num)
        {
            head=temp->next;
            free(temp);
            //return head;
        }
        else
        {
            //To check whether element is found or not
            int check=0;
            while(temp->next!=NULL)
            {
                if(temp->next->data==num)
                {
                    node2del=temp->next;
                    temp->next=temp->next->next;
                    free(node2del);
                    check=1;
                    return head;
                }
                temp=temp->next;
            }
            if(check==0){
                printf("Element not found\n");
                //return head;
            }
        }
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp;
    temp=head;
    if(temp==NULL){
        printf("EMPTY LL\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    int num,choice=0;
    struct node *head;
    head=NULL;

    do
    {
        printf("1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\nENTER YOUR CHOICE: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter data for the node: ");
            scanf("%d",&num);
            head=insert(head,num);
            break;
        case 2:
            printf("enter the data to be deleted: ");
            scanf("%d",&num);
            head=del(head,num);
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(0);
            break;
        default :
            printf("ENTER VALID CHOICE (1 TO 4)");
        }
    }while(choice!=4);
    return 0;
}
