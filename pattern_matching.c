#include<stdio.h>
#include<string.h>
int main()
{
    char text[50];
    char pattern[20];
    int i,j,m,n;
    printf("Enter the string\n");
    scanf("%s",text);
    printf("%s",text);
    printf("Enter the pattern \n");
    scanf("%s",pattern);
    printf("%s",pattern);
    n= strlen(text);
    printf("text length %d",n);
    
    m= strlen(pattern);
    printf("pattern length %d",m);

    for(i=0;i<=n-m;i++)
    {
        printf("iteration i = %d",i);
        j=0;
        while(j<m && text[i+j] == pattern[j])
        {
            j++;
        } 
        printf(" j value : %d",j);
        if(j==m){
            printf("found at pos : %d",i);
            //break;
        }
        /*else
        {
            printf("patter not found ");
        }*/
    }
    //printf("i value : %d",j);
    if(j!=m)
        printf("pattern not found");
    
    
}