#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 2 loops , storing comulative sums
    int n, current_sum, max_sum = INT_MIN;
    cin >> n;
    int arr[n];
    int cum_sum[n];

    cin >> arr[0];
    cum_sum[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        cin >> arr[i];
        cum_sum[i] = cum_sum[i - 1] + arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            current_sum = cum_sum[j] - cum_sum[i - 1];

            if (current_sum > max_sum)
            {
                max_sum = current_sum;
            }
        }
    }

    cout << max_sum;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    return 0;
}




































                            

                                       
                                 Nothing / / /

















                            