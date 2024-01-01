#include<stdio.h>
#include<string.h>
struct point{
    char name[50];
    int class[50];
    int age[50];

} x ;

int main(){//4 marks 2 3
             //2 marks 1 ya 2
             //difference wale line naal
              //use points

    struct ppoint *ptr = &x;
    struct point x;             
    strcpy((*ptr).name,"raj");
    printf("%s",(*ptr).name);   
    return 0;
}