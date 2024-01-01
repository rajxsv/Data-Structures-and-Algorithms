#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n],i=0;

    while(arr!=(arr+(n-1))){
        cin >> *(arr + i);
        i++;
    }
    i = 0;
    while(arr!=(arr+(n-1))){
        cout << *(arr + i)<<endl;
        i++;
    }
    return 0;
}