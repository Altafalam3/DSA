#include<stdio.h>
#define size 10

int adj_mat[size][size];
int vis[size];

struct queue1
{
    int a[size];
    int front,rear;
}q1;

void enqueue(int x)
{
  if(q1.front==-1)
  {
    
      q1.front++;
      q1.rear++;
      q1.a[q1.front]=x;
      return;
  }
  q1.rear++;
  q1.a[q1.rear]=x;
  return;
}

int dequeue()
{
    int t;
    t=q1.a[q1.front];
    q1.front++;
    return t;
}

void bfs(int s)
{
   //printf("hello");
    int p;
    enqueue(s);
    vis[s]=1;
    p=dequeue();

    if(p!=0)
    {
        printf("\t%d",p);
    }

    while(p!=0)
    {
        for(int i=1;i<=size;i++)
        {
            if(adj_mat[p][i]==1 && vis[i]==0)
            {
            enqueue(i);
            vis[i]=1;
            }
        }

        p=dequeue();
        if(p!=0)
       {
        printf("\t%d",p);
       }

    }
}

int main()
{
    int  node,edges,sp,ep,sv;
    q1.front=-1;
    q1.rear=-1;
    
    printf("Hello BFS Queue");

    for(int i=1;i<=size;i++)
    {
        for(int j=1;j<=size;j++)
        {
            adj_mat[i][j]=0;
        }
    }
    
    for(int i=1;i<size;i++)
    {
        vis[i]=0;
    }

    printf("\nEnter number of nodes? : ");
    scanf("%d",&node);
    printf("\nEnter number of edges? : ");
    scanf("%d",&edges);

    for(int i=1;i<=edges;i++)
    {
        printf("\nEnter the start point: ");
        scanf("%d",&sp);

        printf("\nEnter the end point: ");
        scanf("%d",&ep);

        adj_mat[sp][ep] = 1;
        adj_mat[ep][sp] = 1;
    }

    printf("\nAdjacency Matrix");
    
    for(int i=1;i<=size;i++)
    {
        printf("\n");
        for(int j=1;j<=size;j++)
        {
            printf("\t%d",adj_mat[i][j]);
        }
    }

    printf("\nEnter the source vertex:");
    scanf("%d",&sv);

    bfs(sv);

    return 0;
}