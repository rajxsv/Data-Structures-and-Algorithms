#include<bits/stdc++.h>
using namespace std;
void bubblesort(vector <int> &v , int n)
{/// every time pushing greatest element to the last
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j <= n - i - 1 ; j++){
            if(v[j]>=v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;

    vector <int> v(n);

    for(auto &i : v)
    {
        cin >> i;
    }

    bubblesort(v,n);

    for(int i = 0 ; i < n ; i++)
    {
        cout << v[i] << endl;
    }

    return 0;
}