class Solution {
public:

    void backtrack(int n, int k, int idx, vector<int> comb, vector<vector<int>>& ans) {
        if (comb.size() == k) {
            // if we reached the required size, add current combination to the answer and return
            ans.push_back(comb);
        } else {
            for (int i = idx; i <= n; ++i) {
                // start from the current index to avoid generating combinations that are generated before
                comb.push_back(i);
                backtrack(n, k, i + 1, comb, ans);
                comb.pop_back();
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        backtrack(n, k, 1, comb, ans);
        return ans;
    }
};