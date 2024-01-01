#include <bits/stdc++.h>
using namespace std;

bool mycmp(pair<string, int> p1, pair<string, int> p2)
{
    if(p1.second == p2.second)
    {
        return p1.first < p2.first;
    }

    return p1.second > p2.second;
}
    void mysort(vector<pair<string, int>> &v , int n, int x)
{
    sort(v.begin(), v.end(), mycmp);

    for(int i = 0 ; i < n ; i++)
    {
        if(v[i].second >= x)
        {
            cout << v[i].first << " "<<v[i].second<<endl;
        }
    }
}

int main()
{
    int x;
    cin >> x;

    int n;
    cin >> n;

    vector<pair<string, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    mysort(v, n, x);

    return 0;
}