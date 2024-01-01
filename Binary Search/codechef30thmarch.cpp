#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, x, y , countx = 0 , county = 0; 
    cin >> t;
    if(t<=1 && t >= 100)return 0;
    while (t--)
    {
        cin >> n >> x >> y;
        if (x && y && (n >= 2) && (n <= 1000) && (x <= 100) && (y <= 100))
        {
            //10
            int ans = 0,b0;
            int b;
            cin >> b;
            int m2 = 0;
            int temp1=b;
            b = 0;
            while(temp1>0)
            {
                b = b + (temp1%10)*(pow(2,m2));
                m2++;
                temp1 = temp1/10;
            }
            //10
            b0 = b;
            while(b>=1)
            {
                if((b&1)==0)
                {
                    int temp = b;
                    temp = temp >> 1;
                    if(temp&1==1)
                    {
                        ans = ans + y;
                       
                    }
                }
                b = b >> 1;
            }
            //01
            while(b0>0)
            {
                if((b0>0)==1)
                {
                    int temp = b0;
                    temp = temp >> 1;
                    if(temp&1==0)
                    {
                        ans = ans + x;
                    }
                }
                b0 = b0 >> 1;
            }
            cout << ans << endl;
        }
    }
    return 0;
}