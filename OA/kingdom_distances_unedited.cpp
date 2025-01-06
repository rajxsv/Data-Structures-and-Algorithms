#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

int solution(vector<int> trees, vector<int> distances, int k) {
    int n = trees.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));

    vector<int> prefixDistances(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        prefixDistances[i] = prefixDistances[i - 1] + distances[i - 1];
    }

    auto cost = [&](int l, int r) {
        int totalCost = 0;
        for (int i = l; i <= r; ++i) {
            totalCost += trees[i] * (prefixDistances[r] - prefixDistances[i]);
        }
        return totalCost;
    };

    for (int i = 0; i < n; ++i) {
        dp[i][0] = cost(0, i);
    }

    for (int sawmills = 1; sawmills <= k; ++sawmills) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i][sawmills] = min(dp[i][sawmills], dp[j][sawmills - 1] + cost(j + 1, i));
            }
        }
    }

    return dp[n - 1][k];
}

int main() {
    vector<int> trees = {1, 1, 2, 1};
    vector<int> distances = {20, 30, 10};
    int k = 1;
    
    cout << solution(trees, distances, k) << endl;
    return 0;
}