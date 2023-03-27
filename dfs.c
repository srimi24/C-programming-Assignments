#include<stdio.h>
#define MAX 10

void dfs(int src,int adj[MAX][MAX],int n,int *visited);
void readGraph(int adj[MAX][MAX],int n);



int main()
{
    int adj[MAX][MAX];
    int visited[MAX] = {0};
    int n;
    printf("Enter number of vertices : ");
    scanf("%d",&n);

    readGraph(adj,n);

    dfs(0,adj,n,visited);

}

void readGraph(int adj[MAX][MAX],int n)
{
    printf("Enter the adjacent matrix: ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
}

void dfs(int src,int adj[MAX][MAX],int n,int *visited)
{
    visited[src] = 1;
    printf("%d ",src);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0 && adj[src][i])
        {
            dfs(i,adj,n,visited);
        }
    }
    
}

