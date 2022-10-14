#include<stdio.h>

struct expenditure
{
    char areaOfExpend[50];
    float costOfExpend;
};

int main()
{
    //monthly expenses
    struct expenditure Expen[20];
    int i,numOfExpen;
    float stip,total=0,balance;
    printf("Enter monthly stipend= ");
    scanf("%f",&stip);
    printf("\n Enter number of areas of expenditure= ");
    scanf("%d",&numOfExpen);
    for(i=0;i<numOfExpen;i++)
    {
        printf("\nEnter area of expenditure: ");
        scanf("%s",&Expen[i].areaOfExpend);
        printf("\nEnter cost of expenditure: ");
        scanf("%f",&Expen[i].costOfExpend);
    }
    //calculating total expenses
    
    for(i=0;i<numOfExpen;i++)
    {
        total= total+Expen[i].costOfExpend;
    }
    //calculating balance
    
    balance=stip-total;
    
    printf("\n Total expenditure is = %f",total);
     
    if(balance>0)
    {
        printf("\n Balance is = %f",balance);
    }
    
    else if(balance=0)
    {
        printf("\n zero balance");
    }
    
    else
    {
        printf("\n Excess Expenditure by = %f",balance);
    }
    
    return 0;
}


