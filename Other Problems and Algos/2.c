#include<stdio.h>

int main()
{
    int test, n, s, a, temp;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d", &n);
        s = 0;
        temp = 100;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a);
            s += a;
            if(a) temp++;
        }
        if(s >= 100 && s < temp) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}