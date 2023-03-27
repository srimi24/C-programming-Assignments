#include<stdio.h>
#define MAX 10

void readGraph(int adj[MAX][MAX],int n);
void TopoSortDFS(int adj[MAX][MAX],int n,int src,int *visited,int *stack,int *index);

int main()
{
    int adj[MAX][MAX];
    int visited[MAX]={0};
    int stack[MAX]={0};
    int index = 0; //for stack
    int n;
    
    printf("Enter no. of graph vertices: ");
    scanf("%d",&n);

    readGraph(adj,n);

    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            TopoSortDFS(adj,n,i,visited,stack,&index);
            stack[index] = i;
            index++; 

        }
    }

    printf("Topological sorted array is :");

    for(int i=n-1;i>=0;i--)
        printf("%d ",stack[i]);
    
    
}

void readGraph(int adj[MAX][MAX],int n)
{
    printf("enter adjacency matrix : ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
}

void TopoSortDFS(int adj[MAX][MAX],int n,int src,int *visited,int *stack,int *index)
{
    visited[src] = 1;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0 && adj[src][i])
        {
            TopoSortDFS(adj,n,i,visited,stack,index);
            stack[*index] = i;
            (*index)++;
        }
    }
}



