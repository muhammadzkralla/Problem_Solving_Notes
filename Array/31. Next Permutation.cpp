#include <bits/stdc++.h>

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx, diff;

        // search for the first number that breaks the increasing sequence from right to left
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                // search for the farest number that is just above the number that broke the sequence
                for (int j = i + 1; j < n; ++j) {
                    int curr_diff = nums[j] - nums[i];
                    if (nums[j] > nums[i] && curr_diff <= diff) {
                        idx = j;
                        diff = curr_diff;
                    }
                }

                // swap those numbers and reverse the rest of the array
                swap(nums[idx], nums[i]);
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }

        // if we did not find any number that broke the increasing sequence form right to left
        // this means that this is the largest lexicographical permutation so, we reverse the 
        // whole array to get the smallest lexicographical permutation
        reverse(nums.begin(), nums.end());
    }
};