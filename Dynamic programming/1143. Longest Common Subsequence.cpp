class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i) { // Iterate over each character of the first string
            for (int j = 1; j <= m; ++j) { // Iterate over each character of the second string
                if (text1[i - 1] == text2[j - 1]) { // If the characters match
                    dp[i][j] = dp[i - 1][j - 1] + 1; // Take the value from the diagonal and add 1
                } else {
                    // Take the maximum value from the cell above or to the left
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};