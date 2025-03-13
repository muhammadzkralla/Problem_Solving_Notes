#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool can(vector<int> nums, vector<vector<int>> queries, int k) {
        int n = nums.size();
        vector<int> diff(n + 1), pref(n + 1);

        for (int i = 0; i < k; i++) {
            diff[queries[i][0   ]] += queries[i][2];
            diff[queries[i][1] + 1] -= queries[i][2];
        }

        pref[0] = diff[0];
        for (int i = 1; i < n + 1; ++i)
            pref[i] = diff[i] + pref[i - 1];

        for (int i = 0; i < n; ++i)
            if (pref[i] < nums[i])
                return false;

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = INT32_MAX;

        int l = 0, r = queries.size();
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (can(nums, queries, mid)) {
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return (ans == INT32_MAX) ? -1 : ans;
    }
};
