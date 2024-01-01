/* #include <stdio.h>
#include <string.h>
int main()
{
    /* char str[15];
    gets(str); */
    /* char *ptr = str; */
    /*int num[5] = {1, 2, 3, 4, 5};
    int* ptr = num[2];
    while (*ptr != 5)
    {
        printf("%d", *ptr);
        ptr++;
    }

    return 0;
}
 */
#include <stdio.h>
int function() 
{
    static int number = 10; /* Static variable */
    number++;               /* Maintains the value of the previous execution */
    return number;
}
int main() 
{
    /* Prints the result of two invocations to function */
    printf("%d\n", function()); /* Prints 11 */
    printf("%d\n", function()); /* Prints 12! */
    return 0;
}