/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int string[1000],i,target;
    printf("nums=");
    for(i=0;i<5;i++)
    {
        scanf("%d",&string[i]);
    }
    printf("target");
    scanf("%d",&target);
    
    for(i=0;i<5;i++)
    {
        if(string[i]+string[i+1]==target)
        printf("%d %d",i,i+1);
        else if(string[i]+string[i+2]==target)
        printf("%d %d",i,i+2);
        else if(string[i]+string[i+3]==target)
        printf("%d %d",i,i+3);
        else if(string[i]+string[i+4]==target)
        printf("%d %d",i,i+4);
        else if(string[i]+string[i+5]==target)
        printf("%d %d",i,i+5);
    }
    
    return 0;
}




