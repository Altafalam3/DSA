#include <stdio.h>
#include <stdlib.h>
#define size 4
struct queue
{
   int f, r, a[size];
} q;
void enqueue(int val)
{
   if (q.f == -1)
      q.f = 0;
   if (q.r == size - 1)
   {
      printf("QUEUE IS FULL.\n");
   }
   else
   {
      q.r++;
      q.a[q.r] = val;
   }
}
int dequeue()
{
   int val;
   if (q.f == -1)
   {
      return -1;
   }
   val = q.a[q.f];
   q.f++;
   if (q.f > q.r)
   {
      q.f = q.r = -1;
   }
   return val;
}
void display()
{
   if (q.f == -1)
   {
      printf("Queue is empty.\n");
      return;
   }
   for (int i = q.f; i <= q.r; i++)
   {
      printf("%d\t", q.a[i]);
   }
}
int peek()
{
   int val;
   if (q.f == -1)
   {
      return -1;
   }
   val = q.a[q.f];
   return val;
}

void main()
{
   q.f = q.r = -1;
   int val, choice;
   do
   {
      printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.PEEP\n5.EXIT\nENTER YOUR CHOICE : ");
      scanf("%d", &choice);
      switch (choice)
      {
      case 1:
         printf("Enter the number to be enqueued : ");
         scanf("%d", &val);
         enqueue(val);
         break;
      case 2:
         val = dequeue();
         printf("Eelement dequeued = %d", val);
         break;
      case 3:
         printf("Elements in Queue are :\n");
         display();
         break;
      case 4:
         val = peek();
         if (val == -1)
            printf("Queue is empty\n");
         else
            printf("Element at front is: %d\n", val);
         break;
      case 5:
         exit(0);
      default:
         printf("Invalid choice\n");
      }
   } while (choice != 5);
}
