#include <bits/stdc++.h>

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0, size = 1, n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        
        // all characters are palindrome with thereselves
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        for (int diff = 1; diff < n; ++diff) {
            for (int l = 0; l < n - diff; ++l) {
                int r = l + diff;
                
                // if the left and the right chars are equal and the substring
                // between them is a palindrome, then the substring between l, r is a palindrome
                // and another case when the left and the right chars are equal and
                // they are right after each other, it is a p
                if (s[l] == s[r] && (diff == 1 || dp[l + 1][r - 1])) {
                    dp[l][r] = true;
                }
            }
        }

        // for each row dp[i], if dp[i][j] is true, then a palindrome can be formed
        // by the substring from i -> j
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j]) {
                    int curr_size = abs(i - j) + 1;
                    if (curr_size > size) {
                        start = min(i, j);
                        end = max(i, j);
                        size = curr_size;
                    }
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};