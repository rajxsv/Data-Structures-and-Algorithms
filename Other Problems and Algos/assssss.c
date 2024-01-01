
#include <stdio.h>
int i=0;
int students_count; 

struct fun {
       
        char name[100];
        int percentage[100];
        int student_age[100];
        int ph_no[100];
        int student_marks[100];
        
    } students[100] ;
    
void std_per(){
    int y ;
        printf("Select option\n1.Edit information\n2.View information");
        scanf("%d",&y);
        switch(y){
            case 1 :
            printf("Enter percentage\n");
            scanf("%d",(&students[i].percentage[i]));
            break;
            case 2 :
            printf("Percentage of Student: %d",students[i].percentage[i]);
            break;

        }
        printf("\n\n");
}
void s_age(){
    int y ;
    printf("Select option\n1.Edit information\n2.View information");
        scanf("%d",&y);
        switch(y){
            case 1 :
            printf("Enter age\n");
            scanf("%d",&students[i].student_age[i]);
            break;
            case 2 :
            printf("age of Student: %d",students[i].student_age[i]);
            break;
        }
        printf("\n\n");
}
void p(){
    int y ;
    printf("Select option\n1.Edit information\n2.View information");
        scanf("%d",&y);
        switch(y){
            case 1 :
            printf("Enter phone number\n");
            scanf("%d",&students[i].ph_no[i]);
            break;
            case 2 :
            printf("Ph no. of Student: %d",students[i].ph_no[i]);
            break;
        }
        printf("\n\n");
}
void m(){
    int y ;
    printf("Select option\n1.Edit information\n2.View information");
        scanf("%d",&y);
        switch(y){
            case 1 :
            printf("Enter marks\n");
            scanf("%d",&students[i].student_marks[i]);
            break;
            case 2 :
            printf("marks of Student: %d",students[i].student_marks[i]);
            break;
        }
        printf("\n\n");
}
void n(){
      int y ;
    printf("Select option\n1.Edit information\n2.View information");
        scanf("%d",&y);
        switch(y){
            case 1 :
            printf("Enter name\n");
            scanf("%d",&students[i].name[i]);
            break;
            case 2 :
            printf("name of Student: %d",students[i].name[i]);
            break;
        }
        printf("\n\n");

}
int main(){
    
    int x;
    repeat:
    printf("\n\n<---------------Welcome Student management system------------------->\n\n\n");
    printf("Enter the roll no. of student you want to view/edit \n");;
    scanf("%d",&x);
    i = x - 1;
    students_count++;
    
    printf("ENTER THE SERIAL NO. OF INFORMATION YOU WANT TO VIEW/EDIT \n");
    
    printf("1.Student percentage\n2.Student age\n3.Student Ph. No.\nStudent Marks\n5.Student Name\n\n");
    
    scanf("%d",&i);

    
    
    switch(i){
        case 1:
        std_per();
        break;
        case 2:
        s_age();
        break;
        case 3:
        p();
        break;
        case 4:
        m();
        break;
        case 5:
        n();
        break;

        
    }
    goto repeat;
    
}