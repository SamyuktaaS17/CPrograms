#include <stdio.h>

int main()
{
    int choice,side,l,b,h,r;
    int areaOfSquare(int);
    int areaOfRectangle(int,int);
    int areaOfTriangle(int,int);
    int areaOfCircle(int);
    int areaOfParallel(int,int);
    printf("enter choice number for area of polygon:\n1.Square\n2.Rectangle\n3.Triangle\n4.Circle\n5.Parallelogram\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            printf("Enter side length:\n");
            scanf("%d",&side);
            printf(("Area is %d "),areaOfSquare(side));
            break;
        }
        case 2:
        {
            printf("Enter length:\n");
            scanf("%d",&l);
            printf("Enter breadth:\n");
            scanf("%d",&b);
            printf(("Area is %d "),areaOfRectangle(l,b));
            break;
        }
        case 3:
        {
            printf("Enter base length:\n");
            scanf("%d",&l);
            printf("Enter height:\n");
            scanf("%d",&h);
            printf(("Area is %d "),areaOfTriangle(l,h));
            break;
        }
        case 4:
        {
            printf("Enter radius:\n");
            scanf("%d",&r);
            printf(("Area is %d "),areaOfCircle(r));
            break;
        }
        case 5:
        {
            printf("Enter base length:\n");
            scanf("%d",&l);
            printf("Enter height:\n");
            scanf("%d",&h);
            printf(("Area is %d "),areaOfParallel(l,h));
            break;
        }
        default:
            printf("Invalid menu choice");
            break;
    }
    return 0;
}
/*square area*/
int areaOfSquare(int x)
{
    int area;
    area=x*x;
    return(area);
}
/*rectangle area*/
int areaOfRectangle(int x,int y)
{
    int area;
    area=x*y;
    return(area);
}
/*triangle area*/
int areaOfTriangle(int x,int y)
{
    int area;
    area=0.5*x*y;
    return(area);
}
/*circle area*/
int areaOfCircle(int x)
{
    int area;
    area=3.14*x*x;
    return(area);
}
/*Parallelogram area*/
int areaOfParallel(int x,int y)
{
    int area;
    area=x*y;
    return(area);
}

