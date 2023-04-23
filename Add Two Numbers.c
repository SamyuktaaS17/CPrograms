#include<stdio.h>

int main()
{
    int num1[100],num2[100],i,numOfElements1,numOfElements2;
    int numRev1[100],numRev2[100],sum,j;
    //first list
    
    printf("Enter number of elements in 11 =");
    scanf("%d",&numOfElements1);
    printf("\tEnter 11= ");
    for(i=0;i<numOfElements1;i++);
    {
        scanf("%d",&num1[i]);
    }
    
    //second list
    
    printf("\nEnter number of elements in 12 =");
    scanf("%d",&numOfElements2);
    printf("\tEnter 12= ");
    for(i=0;i<numOfElements2;i++);
    {
        scanf("%d",&num2[i]);
    }
    
    //reversing first list elements
    
    for(i=0;i<numOfElements1;i++)
    {
        for(j=numOfElements1-1;j>=0;j--)
        {
            num1[i]==numRev1[j];
        }
    }
    
    //reversing second list elements
    
    for(i=0;i<numOfElements2;i++)
    {
        for(j=numOfElements2-1;j>=0;j--)
        {
            num2[i]==numRev2[j];
        }
    }
    
    printf("\nreversed elements are of 11=");
    for(j=0;j<numOfElements1;j++)
    {
        printf("%d",numRev1[j]);
    }
    
    return 0;
}