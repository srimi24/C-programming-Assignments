#include<stdio.h>
#include<stdlib.h>
#define ARRAY_SIZE 20

int maximum_element_array(int arr[ARRAY_SIZE],int n);
int minimum_element_array(int *arr,int n);
int* Distrubution_counting_sort(int *arr,int l,int u,int n);

int main()
{
    int n;
    printf("Enter number of elements: \n");
    scanf("%d",&n);

    int arr[ARRAY_SIZE];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int u = maximum_element_array(arr,n);
    int l = minimum_element_array(arr,n);

    printf("%d %d \n",l,u);

    int * get_sorted_array = Distrubution_counting_sort(arr,l,u,n);
    for(int i=0;i<n;i++)
    {
        printf("%d \n",get_sorted_array[i]);
    }
}

int maximum_element_array(int arr[ARRAY_SIZE],int n)
{
    int max = arr[0];
    for(int i=0;i<n;i++)
    {
       if(arr[i]>max)
       {
            max = arr[i];
       }
    }
    return max;
}

int minimum_element_array(int *arr,int n)
{
    int min = arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
        {
            min = arr[i];
        }
    }
    return min;
}

int* Distrubution_counting_sort(int *a,int l,int u,int n)
{
    int *distribution_values_array = malloc(sizeof(int)*(u-l+1));
    int *sorted_array = malloc(sizeof(int)*n);
    for(int j=0;j<u-l+1;j++)
    {
        distribution_values_array[j] = 0;
    }

    for(int i=0;i<n;i++)
    {
        distribution_values_array[a[i]-l] = distribution_values_array[(a[i]-l)]+1;
    }
    for(int j=1;j<u-l+1;j++)
    {
        distribution_values_array[j] = distribution_values_array[j-1] + distribution_values_array[j];
    }
    
    for(int i=n-1;i>=0;i--)
    {
        int j = a[i] - l;
        sorted_array[distribution_values_array[j]-1] = a[i];
        distribution_values_array[j] = distribution_values_array[j] -1;

    }   
    return sorted_array;
}