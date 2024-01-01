#include <bits/stdc++.h>
using namespace std;


// we  approach by thinking t=either it can be in contigeous array (max of subarray sum )
// or it can be in the circular array - (modified kadane (total sum - minsum))
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        
        int n;
        cin >> n;

        vector<int> v(n);

        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        int curr_minsum = v[0], curr_maxsum = v[0];
        int maxsum = INT_MIN;
        int minsum = INT_MAX;
        int sum = v[0];

        for (int i = 1; i < n; i++){
            sum =sum + v[i];
            // max till now
            curr_maxsum = max(curr_maxsum + v[i], v[i]);

            // min till now
            curr_minsum = min(curr_minsum + v[i], v[i]);

            // max of all
            maxsum = max(curr_maxsum, maxsum);
            // min of all
            minsum = min(curr_minsum, minsum);
        }

        // for -ve elements
        if (minsum == sum){
            cout << maxsum<<endl;
        }
        // if no negative elements then we return the max of either the kadane (simple)
        // or the circular kadane (total sum - minsum) which gives the max circular sum
        else{
            cout << max(maxsum,sum-minsum)<<endl;
        }
    }
    return 0;
}