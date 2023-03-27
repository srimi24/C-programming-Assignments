#include<string.h>
// Online C compiler to run C program online
#include<stdio.h>


void invertVowels(char * s){
	// Your code here
	int k = 0;
	int length;
	char vowel_array[100];
	
    int j=0;
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'A' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
		{
				vowel_array[j++] = s[i];
		}
	}
    vowel_array[j] = '\0';
    

	j=0;
    int l = strlen(s);
    int m = 0;
	for(int j = l-1;j>=0;j--)
	{
        
		if(s[j] == 'a' || s[j] == 'e' || s[j] == 'A' || s[j] == 'E' || s[j] == 'i' || s[j] == 'I' || s[j] == 'o' || s[j] == 'O' || s[j] == 'u' || s[j] == 'U')
		{
			s[j] = vowel_array[m++];
		}
		
	}
   
    
}

int main() {
    char s[100000];
    scanf("%s",s);
    invertVowels(s);
    printf("%s",s);
    return 0;
}