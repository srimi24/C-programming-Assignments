#include<stdio.h>

float list_sum(float a[],int n);

int main(){
    
    float a[100];
    int n,num;


    printf("Enter n");
   // fflush(stdin);
    scanf("%d",&n);
   // n = num;
   //printf("%d",n);
    printf("Enter the values\n");
    for(int i = 0;i<n;i++)
    {
       
        scanf("%f",&a[i]);
    }

  
    float sum1 = list_sum(a,n);
    printf("The sum of the list elements is : %f",sum1);
}


float list_sum(float a[],int n)
{
    printf("%d",n);
    if(n)
        return list_sum(a,n-1) + a[n-1];
    else    
        return 0;
}