#include <stdio.h>
int number = 10;
void function() 
{
    int number; /* Colission with global variable*/
    number = 20;
    printf("%d \n",number);
}
int main(int argc, char *argv[]) 
{
    function();
    /* Print the value of number */
    printf("%d\n", number); /* Which value is printed? */
    return 0;
}
