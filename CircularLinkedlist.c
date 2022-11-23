#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct ll_node
{
    int data;
    struct ll_node *next;
};

struct ll_node *head = NULL;


void insert()
{
    struct ll_node *newnode, *helper, *temp;
    newnode = (struct ll_node *)malloc(sizeof(struct ll_node));

    int number;
    printf("Enter the number to be inserted : ");
    scanf("%d", &number);

    if (head == NULL)
    {
        head = newnode;
        newnode->data = number;
        newnode->next = head;
        return;
    }

    //1st jagha pe insert
    if (head->data >= number)
    {
        //2 dummy head
        helper = head;
        temp = head;

        head = newnode;
        newnode->data = number;
        newnode->next = helper;
        //traverse to find last node
        while (helper->next != temp)
        {
            helper = helper->next;
        }
        helper->next = head;
        return;
    }

    helper = head;
    while ((helper->next != head) && helper->next->data <= number)
    {
        helper = helper->next;
    }
    //same for middle or end
    newnode->next = helper->next;
    helper->next = newnode;
    newnode->data = number;
}

void deletenode()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    struct ll_node *helper, *temp;
    int number;
    printf("Enter the Number to be Deleted:");
    scanf("%d", &number);

    if (number == head->data)
    {
        helper = head;
        //one forward and save in real
        head = head->next;
        temp = head;
        //traverse till last to attach with 2nd
        while (temp->next != helper)
        {
            temp = temp->next;
        }
        temp->next = head;

        //only 1 node ll head delete
        if (helper == temp)
        {
            head = NULL;
        }
        free(helper);
        return;
    }

    helper = head;
    while (helper->next != head && helper->next->data != number)
    {
        helper = helper->next;
    }

    if (helper->next == head)
    {
        printf("Element not found\n");
        return;
    }

    //same condition for mid ,end
    temp = helper->next;
    helper->next = temp->next;
    free(temp);
}

void display()
{
    if (head == NULL)
    {
        printf("Linked list is EMPTY\n");
        return;
    }

    struct ll_node *helper;
    helper = head;
    printf("Elements in the linked list are :\n");
    do
    {
        printf("%d\t", helper->data);
        helper = helper->next;
    } while (helper != head);
    printf("\n");
}

int main()
{
    int choice;
    do
    {
        printf("1.Insert Node\n2.Delete Node\n3.Display\n4.Exit\nEnter the choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            deletenode();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("INVALID INPUT\n");
        }
    } while (choice!=4);
    return 0;
}
