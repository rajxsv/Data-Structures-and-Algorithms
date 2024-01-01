#include<stdio.h>
int main(){
    char str[15] ;
    gets(str);
    char* ptr = str;
    while(*ptr!='\0'){
    printf("%c",*ptr);
    ptr++;
    }

    return 0;
}