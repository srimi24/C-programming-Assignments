#include<stdio.h>
#include<stdlib.h>
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    numsSize = 2*n;
    int j=0;
    returnSize = (int *)malloc(numsSize*sizeof(int));
    //for(int i=0,j=n;i<n,j<numsSize;i++,j++)
    for(int i=0;i<n;i++)
    {
            returnSize[j] = nums[i];
            returnSize[j+1] = nums[i+n];
            j+=2;
            //returnSize = (int *)malloc(sizeof(int));
            //returnSize[k++] = nums[i];
            //returnSize[k++] = nums[j];
        
    }
    return returnSize;

}
int main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d",&n);
    int n1=n/2;
    int a[n];
    int* b;
    printf("Enter elements of array\n");
    for(int i=0;i<n;i++)
    {
        a[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array entered is \n");
    b=shuffle(a,n,n1,b);
    for(int i=0;i<n;i++)
    {
        printf("%d\t",b[i]);
    }

    return 0;
}