#include <bits/stdc++.h>

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // 1 3 1    1 4 5
        // 1 5 1 -> 2 7 6
        // 4 2 1    6 8 7

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // ignore the first item
                if (i == 0 && j == 0) continue;

                // we can reach the current item either from top or left 
                int top = INT32_MAX;
                int left = INT32_MAX;

                // handle top-edge and left-edge items
                if (i > 0) top = grid[i - 1][j];
                if (j > 0) left = grid[i][j - 1];

                // minimze the value to reach the current item
                grid[i][j] = grid[i][j] + min(top, left);
            }
        }

        return grid[n - 1][m - 1];
    }
};