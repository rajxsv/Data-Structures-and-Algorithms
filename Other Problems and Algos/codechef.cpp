#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    unsigned int t;
    cin >> t;
    while (t--)
    {
        unsigned int pg_to_write, pgs_left, money, no_nbs;
        cin >> pg_to_write >> pgs_left >> money >> no_nbs;
        unsigned int p[100000], c[100000];
        for (int i = 0; i < no_nbs; i++)
        {
            cin >> p[i] >> c[i];
        }
        sort(p, p + no_nbs);
        sort(c, c + no_nbs);
        for (int i = 0; i < no_nbs; i++)
        {
            if (p[i] >= (pg_to_write - pgs_left) && c[i] <= money)
            {
                cout << "LuckyChef" << endl;
                break;
            }
            else
            {
                cout << "UnluckyChef" << endl;
                break;
            }
        }
    }

    return 0;
}