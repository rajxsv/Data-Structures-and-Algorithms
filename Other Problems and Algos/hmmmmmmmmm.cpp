#include <bits/stdc++.h>
using namespace std;
int countbits(int n)
{
    int ans = 0;

    while (n > 0)
    {
        n = n & (n - 1);
        ans++;
    }

    return ans;
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        cout << countbits(n) << endl;
    }
    return 0;
}