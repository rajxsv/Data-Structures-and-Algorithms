#include <iostream>
using namespace std;
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int i = 0;
        int start = 0;
        int new_start = 0;
        int ans = 1;

        while (i < n-1)
        {
            // A bitonic array consists of increasing and decreasing array

            // the increasing array counter
            while (i < n - 1 && arr[i + 1] >= arr[i])
            {
                i++;
            }

            // now we find where its decreasing
            while (i < n - 1 && arr[i + 1] <= arr[i])
            {
                if(arr[i] > arr[i+1])
                {
                    new_start = i + 1;
                }
                i++;
            }
            
            int cur_len = i - (start - 1);
            ans = max(cur_len, ans);

            start = new_start;
        }
        

        cout << ans << endl;
    }

    return 0;
}