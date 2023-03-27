#include<stdio.h>
#define MAX 50

int seq_search(int a[MAX],int n,int key);

int main()
{
    int a[MAX],i,n,key;
    printf("Enter the no. of elements:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to be searched :");
    scanf("%d",&key);

    int res = seq_search(a,n,key);
    if(res == -1)
        printf("Unsuccessful search");
    else
        printf("successful search found at: %d",res);
}

int seq_search(int a[],int n,int key)
{
    int i=0;
    a[n] = key;

    while(a[i]!=key)
    {
        i++;
    }
    if(i<n)
        return i;
    else
        return -1;
}