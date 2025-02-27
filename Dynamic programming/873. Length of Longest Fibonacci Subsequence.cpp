#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), ans = INT32_MIN;
        vector<vector<int>> dp(n, vector<int>(n));
        map<int, int> indices;

        for (int i = 0; i < n; ++i) if (!indices[arr[i]]) indices[arr[i]] = i;

        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
                dp[i][j] = 2;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int prev = arr[i] - arr[j];
                if (indices.find(prev) != indices.end() && prev < arr[j]) {
                    int idx = indices[prev];
                    dp[j][i] = dp[idx][j] + 1;
                }

                ans = max(ans, dp[j][i]);
            }
        }

        ans = (ans > 2) ? ans : 0;
        return ans;
    }
};
