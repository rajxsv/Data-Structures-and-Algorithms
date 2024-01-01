#include <stdio.h>
int main()
{
    int k = 35;
    printf("\n%d %d %d", k == 35, k = 50, k > 40); //111      //35 50 50    // 35 1 1 

    return 0;
}