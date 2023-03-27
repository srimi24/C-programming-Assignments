#include<stdio.h>
#define MAX 20
void dfs(int sv,int adj[MAX][MAX],int *visited,int n, int *stack, int *index);
void graphRead(int adj[MAX][MAX],int n);

//this code doesnt work acc to me


//void graphRead(int adj[10][10],int n);

int main()
{
    int adj[MAX][MAX];
    int visited[MAX] = {0};
    int stack[MAX],a[MAX] = {0};
    int n, i, k = 0;
    int index =0;

    printf("Enter number of vertices : ");
    scanf("%d",&n);

    graphRead(adj,n);

    dfs(i,adj,visited,n,stack,&index);

    for(i=0;i<index;i++)
    {
        printf("stack %d" ,stack[index-1-i]);
        a[k++] = stack[index-1-i];
    }
    printf("topological sort \n");
    for (i=index-1;i>=0;i--)
    {
        printf("%d",a[i]);
    }
}

void graphRead(int adj[MAX][MAX],int n)
{
    printf("Enter the adjoint matrix: ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&adj[i][j]);
    }
}

void dfs(int sv,int adj[MAX][MAX],int *visited,int n, int *stack, int *index)
{
    printf("%d ",sv);
    visited[sv] = 1;

    stack[*index] = sv;
    (*index)++;

    for(int i=0;i<n;i++)
    {
        if(adj[sv][i] && visited[i]==0)
        {
            dfs(i,adj,visited,n,stack,index);
        }
    }

}