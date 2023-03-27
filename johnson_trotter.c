#include<stdio.h>
#define RtoL 0
#define LtoR 1

void printPermutation(int n);
void getPermutation(int perm[],int dir[],int n);
int getLME(int perm[],int dir[],int n);
int getLMEPos(int perm[],int n,int mobile);

int main()
{
    int n;
    scanf("%d",&n);

    printPermutation(n);
}

int factorial(int n)
{
	int res=1;
	
	for(int i=1;i<=n;i++)
		res*=i;
	
	return res;
}
