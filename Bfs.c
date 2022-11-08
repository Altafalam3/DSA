#include <stdio.h>
// node +1 size hona chahiye since we r starting from 1
#define size 10

// matrix of 1 and 0 s to see which node is connected to which
int adj_mat[size][size];
// visited node or not
int vis[size];

struct queue1
{
    int a[size];
    int front, rear;
} q1;

// no need to check for full bcz size defined
void enqueue(int x)
{
    //1st position insert
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
    //source vertex insert and visited
    enqueue(s);
    vis[s] = 1;
    //sv removed and print
    p = dequeue();
    if (p != 0)
    {
        printf("\t%d", p);
    }

    while (p != 0)
    {
        for (int i = 1; i <= size; i++)
        {
            //insert all connected which is not visited
            if (adj_mat[p][i] == 1 && vis[i] == 0)
            {
                enqueue(i);
                vis[i] = 1;
            }
        }

        p = dequeue();
        if (p != 0)
        {
            printf("\t%d", p);
        }
    }
}

int main()
{
    int node, edges, sp, ep, sv;
    q1.front = -1;
    q1.rear = -1;

    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            adj_mat[i][j] = 0;
        }
    }

    for (int i = 1; i < size; i++)
    {
        vis[i] = 0;
    }

    printf("\nEnter number of nodes? : ");
    scanf("%d", &node);
    printf("\nEnter number of edges? : ");
    scanf("%d", &edges);

    for (int i = 1; i <= edges; i++)
    {
        printf("\nEnter the start point: ");
        scanf("%d", &sp);

        printf("\nEnter the end point: ");
        scanf("%d", &ep);
        //marking visited for connected
        adj_mat[sp][ep] = 1;
        adj_mat[ep][sp] = 1;
    }

    printf("\nAdjacency Matrix");

    for (int i = 1; i <= size; i++)
    {
        printf("\n");
        for (int j = 1; j <= size; j++)
        {
            printf("\t%d", adj_mat[i][j]);
        }
    }

    printf("\nEnter the source vertex:");
    scanf("%d", &sv);
    bfs(sv);

    return 0;
}
