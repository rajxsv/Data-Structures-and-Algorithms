#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b)
{
    return b > a;
}
int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int key;
    cin >> key;

    int start = 0;
    int end = n - 1;
    int index;

    while (start < end){
        int mid = start + (end - start) / 2;

        if (v[mid] <= v[mid + 1] && v[mid] < v[mid - 1]){
            index = mid;
            break;
        }
        else if (v[start] > v[mid]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    int ans = -1;

    if (binary_search(v.begin(), v.begin() + index - 1, key)){
        auto it = lower_bound(v.begin(), v.begin() + index - 1, key);
        ans = it - v.begin();
    }
    else if (binary_search(v.begin() + index, v.end(), key)){
        auto it = lower_bound(v.begin() + index, v.end(), key);
        ans = it - v.begin();
    }

    cout << ans<<endl;
    cout << lower_bound(v.begin(),v.end(),3) - v.begin()<<endl;
    cout<< upper_bound(v.begin(),v.end(),5)-v.begin()<<endl; 
    return 0;
}
