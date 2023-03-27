#include<stdio.h>

int russianPeasant(int n,int m)
{
    int res = 0;

    while(n>0)
    {
        if(n&1)
            res = res+m;
        
        n = n>>1;
        m = m<<1;
    }
    return res;
}

int main()
{
	int n,m;
	printf("Enter two numbers: ");
    scanf("%d %d", &n, &m);
	printf("%d*%d=%d\n",n,m,russianPeasant(n,m));
}