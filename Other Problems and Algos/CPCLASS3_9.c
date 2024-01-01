#include <stdio.h>
int main()
{
    FILE *fp;
    char c;
    fp = fopen("cpclass9_3.doc", "w");
    if(fp==NULL){
        printf("if_block");
    }
    scanf("%c",&c);
    do
    {
        putc(c, fp);
        scanf("%c",&c);
    }while (c != '\n');
    fclose(fp);
     fp = fopen("cpclass9_3.doc", "r");
    
    do
    {
        printf("%c", c);
        scanf("%c",&c);
    }while (c  != '\n');
    fclose(fp);
 
    return 0;
}