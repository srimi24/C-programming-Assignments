#include<stdio.h>
#define MAX 50

int main()
{
    int a[MAX] ,n,i,j;
    int temp,sorted;
    printf("Enter the number of elements");
    scanf("%d",&n);
    printf("Enter the elements");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    sorted = 0;
    for(i=0;i<n-1 && !sorted;i++)
    {
        sorted = 1;
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                sorted = 0;
            }
        }
        
    }
    printf(" no. of iterations: %d\n",i);

    printf("sorted elements are\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}