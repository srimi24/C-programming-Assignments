#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

struct timeval{
    long tv_sec;
    long tv_usec;
};

int getrand(int a[],int n)
{
    int i;
    for(i = 0;i<n;i++)
    {
        a[i] = rand()%10000 ;//range from 0 to 9999
    }
}

int search(int arr[],int n,int key,int *count)
{
    int i;
    for(i=0;i<n;i++)
    {
        count = count+1;
        if(arr[i] == key)
        {
            return i;
        }
        return -1;
    }
}

int main()
{
    int a[10000];
    int i,res,count;
    double elapse,start,end;
    struct timeval tv;
    FILE *fp1,*fp2;
    fp1 = fopen("seqtime.txt","w");
    fp2 = fopen("seqcount.txt","w");
    int key;
    for(i=500;i<=10000;i+=500) //size of the array to be created
    {
        
        getrand(a,i);
        key = a[i-1];
        count = 0;
        gettimeofday(&tv,NULL);
        start = tv.tv_sec+ tv.tv_usec/100000; //start time
        res = search(a,i,key,&count);
        gettimeofday(&tv,NULL);
        end = tv.tv_sec + tv.tv_usec/100000; //end time
        elapse = (end - start)*1000;
        fprintf(fp1,"%d\t%lf\n",i,elapse);
        fprintf(fp2,"%d\t%d\n",i,count);
    }
    fclose(fp1);
    return 0;
}