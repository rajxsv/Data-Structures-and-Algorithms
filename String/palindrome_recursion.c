#include <stdio.h>
#include <string.h>

int check(int i, int j, char d[])                                                           
{                                                                                                                                                                                                                                 
    if ((j - 1) >= i)                                                                                                                                          
    {                                                                                                                 
        if (d[i] == d[j - 1])                                                                                                       
        {                                                                                                              
            check(i + 1, j - 1, d);                                                                                     
        }                                                                                                                                            
        else                                                                                                
        {                                                                                                          
            return 0;                                                                                                 
        }                                                                                                     
    }
                                                                                                                                                                              

    return 1;                                                                                                                                                                                                          
}                                                                                                                                                                                                                                   

int main()                                                                                                                                                                                                        
{                                                                                                                           

    char c[100], d[100];                                                                        
    gets(c);                    
    int i, spacecount = 0;                                                                  
    int k;                                                                                  
    for (i = 0, k = 0; c[i] != '\0'; i++)                                                           
    {                                                                               
        if (c[i] == ' ')                                        
        {
                                                       
        }                                           
        else                                                                                       
        {                                       
            d[k] = c[i];                                        
            k++;                                                
        }                                               
    }                                       

    if (check(0, k, d))                                                                                                                                                                                                                                                                    
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Nope\n");
    }

    return 0;
}