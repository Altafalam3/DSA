#include <stdio.h>
#define size 10
// stack
int adj_mat[size][size];
// visited
int vis[size];

struct stack1
{
   int a[size];
   int top;
} s1;

void push(int x)
{
   s1.top++;
   s1.a[s1.top] = x;
   return;
}

// no need to check for full
int pop()
{
   int t;
   t = s1.a[s1.top];
   s1.top--;
   return t;
}

void dfs(int s)
{
   int p;
   push(s);
   vis[s] = 1;
   p = pop();
   if (p != 0)
   {
      printf("\t%d", p);
   }

   while (p != 0)
   {
      for (int i = 1; i <= size; i++)
      {
         if (adj_mat[p][i] == 1 && vis[i] == 0)
         {
            push(i);
            vis[i] = 1;
         }
      }
      p = pop();
      if (p != 0)
      {
         printf("\t%d", p);
      }
   }
}

int main()
{
   int node, edges, sp, ep, sv;

   s1.top = -1;
   for (int i = 1; i <= size; i++)
   {
      for (int j = 1; j <=size; j++)
      {
         adj_mat[i][j] = 0;
      }
   }

   for (int i = 1; i <= size; i++)
   {
      vis[i] = 0;
   }

   printf("How many nodes:");
   scanf("%d", &node);
   printf("How many edges:");
   scanf("%d", &edges);

   for (int i = 1; i <= edges; i++)
   {
      printf("Enter the start point \n");
      scanf("%d", &sp);

      printf("Enter the end point \n");
      scanf("%d", &ep);

      adj_mat[sp][ep] = 1;
      adj_mat[ep][sp] = 1;
   }

   printf("Adjacency Matrix");
   for (int i = 1; i <= size; i++)
   {
      for (int j = 1; j <= size; j++)
      {
         printf("%d\t", adj_mat[i][j]);
      }
      printf("\n");
   }

   printf("Enter the source vertex\n");
   scanf("%d", &sv);
   dfs(sv);

   return 0;
}
