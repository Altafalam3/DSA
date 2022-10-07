#include <stdio.h>
#include <stdlib.h>
// SORTED DOUBLY LINKEDLIST

struct node
{
   int data;
   struct node *next;
   struct node *prev;
};

struct node *insert(struct node *head, int num)
{
   struct node *temp;
   temp = head;
   struct node *new = (struct node *)malloc(sizeof(struct node));
   new->data = num;
   new->next = NULL;
   new->prev = NULL;
   // empty
   if (head == NULL)
   {
      head = new;
      return head;
   }

   // insert at first conditions
   if (head->data >= num)
   {
      new->next = head;
      head->prev = new;
      head = new;
      return head;
   }
   // other positions insert
   while (temp->next != NULL && temp->next->data < num)
   {
      temp = temp->next;
   }
   new->next = temp->next;
   if (temp->next != NULL)
   {
      temp->next->prev = new;
   }
   new->prev = temp;
   temp->next = new;
   return head;
}

struct node *del(struct node *head, int num)
{
   struct node *temp, *node2del;
   temp = head;
   if (head == NULL)
   {
      printf("EMPTY LL\n");
      return head;
   }
   // delete at first
   if (temp->data == num)
   {
      head = head->next;
      head->prev = NULL;
      free(temp);
      return head;
   }

   while (temp->next != NULL && temp->next->data != num)
   {
      temp = temp->next;
   }
   if (temp->next == NULL)
   {
      printf("Element not found \n");
      return head;
   }
   node2del = temp->next;
   temp->next = node2del->next;
   if (node2del->next != NULL)
   {
      node2del->next->prev = temp;
   }
   free(node2del);

   return head;
}

void display(struct node *head)
{
   struct node *temp;
   temp = head;
   if (temp == NULL)
   {
      printf("EMPTY LL\n");
      return;
   }
   while (temp != NULL)
   {
      printf("%d\t", temp->data);
      temp = temp->next;
   }
   printf("\n");
}
int main()
{
   int num, choice = 0;
   struct node *head;
   head = NULL;

   do
   {
      printf("1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\nENTER YOUR CHOICE: ");
      scanf("%d", &choice);
      switch (choice)
      {
      case 1:
         printf("enter data for the node: ");
         scanf("%d", &num);
         head = insert(head, num);
         break;
      case 2:
         printf("enter the data to be deleted: ");
         scanf("%d", &num);
         head = del(head, num);
         break;
      case 3:
         display(head);
         break;
      case 4:
         exit(0);
         break;
      default:
         printf("ENTER VALID CHOICE (1 TO 4)");
      }
   } while (choice != 4);
   return 0;
}