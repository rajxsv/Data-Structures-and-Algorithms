#include<stdio.h>

void reverse(){

}
struct students{

    char name[50];
    int roll;
    int cg;
    char address[100];
} s[100];
int main(){
    
    FILE* ptr = fopen("abc.txt", "r");
    if (ptr == NULL) {
        printf("no such file.");
        return 0;
    }
    
     while(fread(&s[i], sizeof(struct Student), 1, ptr))
      printf ("roll_no = %d name = %s\n", s[i].roll_no, s[i].name);
    fclose (ptr);
}
    
    return 0;
}