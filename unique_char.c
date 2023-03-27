#include <stdio.h>
#include <string.h>
#include<stdbool.h>
#define MAX_LEN 100

char find_first_unique_char(char str[]) {
//Your code here
    
   // int i,j;
    bool found;
    //int count;
    for(int i=0;i<strlen(str);i++)
    {
        found = false;
        for(int j=i+1;j<strlen(str);j++)
        {
            //printf("%d",j);
            if(str[i] == str[j])
            {
                found = true;
                str[j] = '\0';
                //count++;
                //printf("%c , %c",str[i],str[j]);
                //break;
            }
        }
        if(found == false)
        {
            //printf("%c",str[i]);
            return str[i];
        }
    }
    return '\0';
}

int main() {
    char str[MAX_LEN];

    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = '\0'; // remove newline character if present

    char first_unique = find_first_unique_char(str);

    if (first_unique != '\0') {
        printf("The first unique character is %c\n", first_unique);
    } else {
        printf("There is no unique character in the string.\n");
    }

    return 0;
}