#include<stdio.h>
#define MAX 20

int main()
{
    int a[MAX],n,i,j,element;
    printf("Enter number of elemnts:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    //inserion sort

    for(i=0;i<n;i++)
    {
        j=i-1;
        element = a[i];
        while(j>=0 && a[j] > element)
        {
            a[j+1] = a[j];
            j--;
        }
        a[++j] = element;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}