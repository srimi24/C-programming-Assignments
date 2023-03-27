#include<stdio.h>
#include<stdlib.h>

int gcd(int a,int b);

int main()
{
    int a,b;
    printf("Enter num1");
    scanf("%d",&a);
    printf("Enter num2");
    scanf("%d",&b);
    printf("The gcd is %d",gcd(a,b));

}

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,b%a);
}