#include <stdio.h>
#include<stdlib.h>

#define size 10

struct queue
{
   int f, r;
   int a[size];
} q;

void display()
{
   int i;
   if (q.f == -1)
   {
      printf("QUEUE IS EMPTY!!");
   }
   for (i = q.f; i <= q.r; (i++)%size)
   {
      printf("%d\n", q.a[i]);
   }
}

void enqueue(int val)
{
   if ((q.r + 1) % size == q.f)
   {
      printf("QUEUE IS FULL!!\n");
   }
   if (q.f == -1) // 1st element to be inserted in queue
   {
      q.f = q.r = 0;
      q.a[q.r] = val;
   }
   else
   {
      (q.r++) % size;
      q.a[q.r] = val;
   }
}

void dequeue()
{
   if (q.f == -1)
   {
      printf("QUEUE IS EMPTY!!\n");
      return;
   }

   int a = q.a[q.f];

   if (q.f == q.r)
   {

      q.f = -1; // queue is made empty
      q.r = -1;
   }
   else
   {
      (q.f++) % size;
   }
   printf("Deleted element is :%d", a);
}

int main()
{
   int cho, val;
   q.f = -1;
   q.r = -1;
   do
   {
      printf("choices are as follows:\n1)enqueue\n2)dequeue\n3)display\n4)EXIT\n");
      printf("enter your choice:\n");
      scanf("%d", &cho);
      switch (cho)
      {
      case 1:
         printf("enter value to be added:\n");
         scanf("%d", &val);
         enqueue(val);
         break;

      case 2:
         dequeue();
         break;

      case 3:
         display();
         break;

      case 4:
         exit(0);
      }
   } while (cho != 4);

   return 0;
}
