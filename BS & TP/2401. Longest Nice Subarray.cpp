#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool can(int mid, vector<int> nums) {
        int n = nums.size();
        for (int i = 0; i <= n - mid; ++i) {
            int curr = 0;
            bool flag = true;
            for (int j = i; j < i + mid; j++) {
                if ((curr & nums[j]) != 0) {
                    flag = false;
                    break;
                }

                curr |= nums[j];
            }

            if (flag) return flag;
        }

        return false;
    }

    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n, ans = 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (can(mid, nums)) {
                ans = max(ans, mid);
                l = mid + 1;
            } else r = mid - 1;
        }

        return ans;
    }
};
