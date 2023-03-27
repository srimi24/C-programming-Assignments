#include<stdio.h>
#include<time.h>
#include<string.h>

int* selection_sort(int *a,int n);
void print_sorted_list(int *a,int n);

int main()
{
	int n;
	int a[100];
	//int i,j;
	printf("Enter n");
	fflush(stdin);
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		printf("Enter the values\n");
		fflush(stdin);
		scanf("%d",&a[i]);
	}

	int *b = selection_sort(a,n);
	print_sorted_list(b,n);

}

int* selection_sort(int *a,int n)
{
	int t;
	for(int i=0;i<n-1;i++)
	{
		int minpos = i;
		for(int j = i+1 ; j<n ; j++)
		{
			if(a[j]<a[minpos])
			{
				minpos = j;
				
			}
			
			
		}
		if(i!= minpos)
			{
				t = a[minpos];
				a[minpos] = a[i];
				a[i] = t;				
				
			}
	}
	return a;
}

void print_sorted_list(int *a,int n)
{
	//printf("%d",sizeof(a));
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
