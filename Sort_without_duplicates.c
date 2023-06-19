#include<stdio.h>
int main()
{
int nums1[20],nums2[20],concnt[40];
int m,n,i,j,temp=0,k;
//first array
printf("Enter number of elements in 1st array: \n");
scanf("%d",&m);
printf("Enter elements of num1: \n");
for(i=0;i<m;i++)
{
    scanf("%d",&nums1[i]);
}
//second array
printf("Enter number of elements in 2nd array: \n");
scanf("%d",&n);
printf("Enter elements of num2: \n");
for(i=0;i<n;i++)
{
    scanf("%d",&nums2[i]);
}
//combining the arrays
int combined_size=m+n;
for(i=0;i<m;i++)
{
    concnt[i]=nums1[i];
}
for(i=0,j=m; i<n && j<combined_size;i++,j++)
{
    concnt[j]=nums2[i];
}

printf("The concateneted array is : \n");
for(i=0;i<combined_size;i++)
{
    printf("%d",concnt[i]);
}

//sorting

for(i=0;i<combined_size;i++)
{
    for(j=i+1;j<combined_size;j++)
    {
        if(concnt[i]>concnt[j])
        {
            temp=concnt[i];
            concnt[i]=concnt[j];
            concnt[j]=temp;
        }
    }
}
//duplicates

for(i=0;i<combined_size;i++)
{
    for(j=i+1;j<combined_size;j++)
    {
        if(concnt[i]==concnt[j])
        {
            for ( k = j; k < combined_size - 1; k++)  
            {  
                concnt[k] = concnt[k + 1];  
            }
            combined_size--;
            j--;
        }
        
    }
}
printf("\nThe sorted array is : \n");
for(i=0;i<combined_size;i++)
{
    printf("%d",concnt[i]);
}
return 0;
}