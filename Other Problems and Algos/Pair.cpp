#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    sort(arr, arr + n);

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if(sum==target)
        {
            cout << arr[left] <<" and "<<arr[right]<<endl;
            left++;
        }   
        else if(sum > target)
        {
            right--;
        }
        else
        {
            left++;
        }

    }   

    return 0;
}