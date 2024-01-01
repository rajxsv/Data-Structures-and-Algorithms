#include<stdio.h>
int main(){
float principle,rate,time;
float simpleInterest;
scanf("%f %f %f",&principle,&rate,&time);
simpleInterest=(principle*rate*time)/100;
printf("The Simple Interest is %f",simpleInterest);

   return 0;
}