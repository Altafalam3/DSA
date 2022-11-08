#include <stdio.h>
#include <stdlib.h>
#define size 10

// visited
int vis[size];

// replacement of adj_matrix
struct ll_node
{
   int vertex;
   struct ll_node *next;
};
// array of pointers made
struct ll_node *adj[size];

struct queue1
{
   int a[size];
   int front, rear;
} q1;

void enqueue(int x)
{
   if (q1.front == -1)
   {
      q1.front++;
      q1.rear++;
      q1.a[q1.rear] = x;
      return;
   }
   q1.rear++;
   q1.a[q1.rear] = x;
   return;
}

// no need to check for full
int dequeue()
{
   int t;
   t = q1.a[q1.front];
   q1.front++;
   return t;
}

void bfs(int s)
{
   int p;
   enqueue(s);
   vis[s] = 1;
   p = dequeue();
   if (p != 0)
   {
      printf("\t%d", p);
   }

   while (p != 0)
   {  
      //changes in this while loop only for list wala
      //traversing array until it points to null and visited already
      while (adj[p] != NULL && vis[adj[p]->vertex] == 0)
      {
         enqueue(adj[p]->vertex);
         vis[adj[p]->vertex] = 1;

         adj[p] = adj[p]->next;
      }

      p = dequeue();
      if (p != 0)
      {
         printf("\t%d", p);
      }
   }
}

//adding connected nodes heree
struct ll_node *creategraph(struct ll_node *temp, int x)
{
   struct ll_node *new1;
   new1 = (struct ll_node *)malloc(sizeof(struct ll_node));

   new1->vertex = x;
   new1->next = temp;
   temp = new1;
   return temp;
}

int main()
{
   int node, edges, sp, ep, sv;

   struct ll_node *hp;
   q1.front = -1;
   q1.rear = -1;

   for (int i = 1; i <= size; i++)
   {
      vis[i] = 0;
   }

   for (int i = 1; i <= size; i++)
   {
      adj[i] = NULL;
   }

   printf("How many nodes");
   scanf("%d", &node);
   printf("How many edges");
   scanf("%d", &edges);

   for (int i = 1; i <= edges; i++)
   {
      printf("Enter the start point \n");
      scanf("%d", &sp);

      printf("Enter the end point \n");
      scanf("%d", &ep);
      //matrix ka alternative
      adj[sp] = creategraph(adj[sp], ep);
      adj[ep] = creategraph(adj[ep], sp);
   }

   printf("Adjacency List");
   for (int i = 1; i <= size; i++)
   {
      hp = adj[i];
      printf("\n");
      //traversing untill null
      while (hp != NULL)
      {
         printf("%d->", hp->vertex);
         hp = hp->next;
      }
   }

   printf("Enter the source vertex\n");
   scanf("%d", &sv);
   bfs(sv);

   return 0;
}