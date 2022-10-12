#include <stdio.h>

int main()
{
    int num[10],i,target,numOfInput,j;
    printf("Enter number of inputs=");
    scanf("%d",&numOfInput);
    printf("nums=");
    
    for(i=0;i<numOfInput;i++)
    {
        scanf("%d",&num[i]);
    }
    printf("target=");
    scanf("%d",&target);
    
    for(i=0;i<numOfInput;i++)
    {
      for(j=1;j<=numOfInput;j++)
      if(num[i]+num[j]==target)
      {
        printf("%d %d",i,j);
        break;
      }
    }
    
    return 0;
}
