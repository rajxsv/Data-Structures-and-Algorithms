#include<stdio.h>
int main(){
    FILE *fileptr;

    char getdata[100];
    scanf("%s",&getdata);

    fileptr = fopen("1stpractice.doc","ab");

    if(fileptr == NULL){
        printf("the program failed to open ");
    }
    else{
        fputs(getdata,fileptr);
        fputs("\n",fileptr);
        printf("Done");

    }
    fclose(fileptr);
     
        
    return 0;
}