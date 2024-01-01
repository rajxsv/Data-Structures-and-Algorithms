#include<stdio.h>
int main()
{
    int n,ly,sy,d,m;
  
   printf("Enter year");
   
   scanf("%d",&n);
   
    ly=n/4;     //ly is no. of leap years
   
    sy=n-ly;    //sy is no. of simple years
   
    d=(ly*366)+(sy*365);  

//d is sum total of days in all years
   
    m=d%7;
   
    switch(m)
    {
        case 0:
                printf("Monday");
        break;
        case 1:
                printf("Tuesday");
        break;
        case 2:
                printf("Wednesday");
        break;
        case 3:
                printf("Thursday");
        break;
        case 4:
                printf("Friday");
        break;
        case 5:
                printf("Saturday");
        break;
        case 6:
                printf("Sunday");
        break;
    }
       return 0;
}