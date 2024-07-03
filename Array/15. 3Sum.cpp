#include <bits/stdc++.h>

class Solution {
public:

    bool bs(int l, int r, int x, vector<int>& nums) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == x) return true;

            if (nums[mid] > x) r = mid - 1;
            else l = mid + 1;
        }

        return false;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i) {
            // to avoid duplicates
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < n - 1; ++j) {
                // to avoid duplicates
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int x = - (nums[i] + nums[j]);
                if (bs(j + 1, n - 1, x, nums))
                    ans.push_back({nums[i], nums[j], x});
            }
        }
        
        return ans;
    }
};