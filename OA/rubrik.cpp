#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kadane(const vector<int>& arr) {
    int max_ending_here = 0, max_so_far = 0;
    for (int num : arr) {
        max_ending_here = max(0, max_ending_here + num);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int enhanceLuminescence(vector<int>& arr, int x) {
    int n = arr.size();
    int base_beauty = kadane(arr);
    int max_beauty = base_beauty;

    vector<int> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + arr[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int original_sum = prefix_sum[j + 1] - prefix_sum[i];
            int amplified_sum = original_sum * x;
            int beauty_with_amplification = prefix_sum[i] + amplified_sum + (prefix_sum[n] - prefix_sum[j + 1]);
            max_beauty = max(max_beauty, beauty_with_amplification);
        }
    }

    return max_beauty;
}

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    int result = enhanceLuminescence(arr, x);
    cout << result << endl;

    return 0;
}