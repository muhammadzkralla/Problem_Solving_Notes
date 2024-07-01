#include <bits/stdc++.h>

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long n = nums.size();
        long long ans = LLONG_MAX;

        vector<long long> pref(n + 1, 0);
        for (long long i = 1; i <= n; ++i) 
            pref[i] = pref[i - 1] + nums[i - 1];

        long long l = 1, r = n;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            bool flag = false;

            for (long long i = mid; i <= n; ++i) {
                long long sum = pref[i] - pref[i - mid];
                if (sum >= target) {
                    flag = true;
                    break;
                }
            }

            if (flag) {
                ans = min(ans, mid);
                r = mid - 1;
            } else l = mid + 1;
            
        }

        return (ans != LLONG_MAX) ? ans : 0;
    }
};