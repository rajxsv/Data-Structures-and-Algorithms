#include<stdio.h>
int main(){
    int x1,y1,x2,y2,x3,y3,x,y;
    printf("Enter 3 coordinates of triangle \n");
    scanf("(%d,%d) (%d,%d) (%d,%d)",&x1,&y1,&x2,&y2,&x3,&y3);
    float distance;
    int flag;
    float a=distance(x1,y1,x2,y2);
    float b=distance(x2,y2,x3,y3);
    float c=distance(x3,y3,x1,y1);
    printf("Distance between 1 and 2 point is %0.2f\n",distance(x1,y1,x2,y2));
    printf("Distance between 2 and 3 point is %0.2f\n",distance(x2,y2,x3,y3));
    printf("Distance between 3 and 1 point is %0.2f\n",distance(x3,y3,x1,y1));
    printf("area of the given triangle is %0.2f\n",area(a,b,c));
    printf("Enter a point that you want to cheak wheather it is inside the triangle or not\n");
    scanf("(%d,%d)",&x,&y);
    int flag= cheak(x,y,x1,y1,x2,y2,x3,y3);
    if(flag==1){
        printf("Point is inside the triangle\n");
    }
    else{
        printf("Point is outside the triangle\n");
    }

        return 0;
    }