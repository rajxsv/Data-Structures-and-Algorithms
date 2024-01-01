#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n],i=0;

    while(arr+i<=(arr+(n-1))){
        cin >> *(arr + i);
        i++;
    }

    cout << endl;
    i = 0;
    
    while(arr+i<=(arr+(n-1))){
        cout << *(arr + i) << " ";
        i++;
    }
    
    return 0;
}