#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

int u,v;
int initial=1;
int waiting=2;
int visited=3;
int adj[10][10];
int n;
int state[10];

void CreateGraph()
{
    int i,j;
    printf("Enter the no. of vertex:\t");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:-\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i!=j && i<j)
            {
                printf("Enter the weight of edge between vertex %d and vertex %d :\t",i,j);
                scanf("%d",&adj[i][j]);
                adj[j][i]=adj[i][j];
            }
        }
    }
    return;
}
int pre[6];
int post[6];
int p=0;
int po=0;
void DFS(int u)
{
    int j;
    printf("%d\n",u);

    state[u]=1;
    p++;
    pre[u-1]=p+po;


    for(j=0;j<=n;j++)
    {
        if(state[j]==0 && adj[u][j]==1)
        {
            DFS(j);
        }
    }

    po++;
    post[u-1]=p+po;

}

void dfs()
{
    int i;
    for(i=1;i<=n;i++)
        state[i]=0;
    printf("Enter start vertex:\t");
    scanf("%d",&u);
    printf("DFS Traversal\n");
    DFS(u);
    for(i=1;i<=n;i++)
    {
        if (state[i]==0)
            DFS(i);
    }
    for(i=0;i<n;i++)
    {
        printf("%d -> pre=%d post=%d\n",i+1,pre[i],post[i]);
    }
}

int main()
{

    CreateGraph();
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }
    dfs();

}
