#include<stdio.h>
#include<stdlib.h>
#define ARRAY_SIZE 20

int* ComparisonCountingSort(int arr[ARRAY_SIZE],int n);

int main()
{
    int n;
    int arr[ARRAY_SIZE];
    printf("Enter number of elements : \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int *get_sorted_array = ComparisonCountingSort(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",get_sorted_array[i]);
    }
}

int* ComparisonCountingSort(int arr[ARRAY_SIZE],int n)
{
    int count[ARRAY_SIZE];
    int *sorted_array = malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        count[i] = 0;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if (arr[i] < arr[j])
                count[j] = count[j] + 1;
            else
                count[i] = count[i] + 1;
        }
    }

    for(int i=0;i<n;i++)
    {
        sorted_array[count[i]] = arr[i];
    }
    return sorted_array;
}