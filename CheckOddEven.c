)#include <stdio.h>

int main()
{
    int i,N,num,sumEven,sumOdd;
    int CheckOddEven(int);
    printf("Enter number of numbers: \n");
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&num);
        if(CheckOddEven(num)==1)
        {
            sumEven=sumEven+num;
        }
        else
        {
            sumOdd=sumOdd+num;
        }
    }
    printf("Even sum is %d\n",sumEven);
    printf("Odd sum is %d\n",sumOdd);
    return 0;
}

int CheckOddEven(int x)
{
    int flag=0;
    if(x%2==0)
    {
        flag=1;
        return flag;
    }
    else
        return flag;
    
}
