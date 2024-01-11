#include <stdio.h>
#include <string.h>

int main()
{
    int i,j;
    char arr[5][16];
    
    for(i=0;i<5;i++)
        scanf("%s",arr[i]);
    
    for(j=0;j<15;j++)
    {
        for(i=0;i<5;i++)
        {
            if(j>=strlen(arr[i]))
                continue;
            printf("%c",arr[i][j]);
        }
    }
}