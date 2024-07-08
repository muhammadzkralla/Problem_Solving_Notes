class Solution {
public:

    void backtrack(int n, vector<int> nums, vector<int> perm, vector<bool> visited, vector<vector<int>>& ans) {
        if (perm.size() == n) {
            // if we reached the required size, add current combination to the answer and return
            ans.push_back(perm);
        } else {
            // we iterate over all the array
            for (int i = 0; i < n; i++) {
                if (!visited[i]) { // check if the element is not already in the current permutation
                    visited[i] = true;
                    perm.push_back(nums[i]);

                    // Recursively call backtrack to generate the next element in the permutation
                    backtrack(n, nums, perm, visited, ans);
                    
                    perm.pop_back();
                    visited[i] = false;
                }
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<bool> visited(n + 1, false);
        vector<int> perm;
        backtrack(n, nums, perm, visited, ans);

        return ans;
    }
};