class Solution {
public:
    bool check(int r, int c, vector<vector<int>> grid, int n) {
        // Check vertical (up and down)
        for (int i = 1; i < n; ++i)
            if ((r - i >= 0 && grid[r - i][c] == 1) || (r + i < n && grid[r + i][c] == 1))
                return false;

        // Check horizontal (left and right)
        for (int i = 1; i < n; ++i)
            if ((c - i >= 0 && grid[r][c - i] == 1) || (c + i < n && grid[r][c + i] == 1))
                return false;

        // Check diagonals
        for (int i = 1; i < n; ++i) {
            if ((r - i >= 0 && c - i >= 0 && grid[r - i][c - i] == 1) ||
                (r - i >= 0 && c + i < n && grid[r - i][c + i] == 1) ||
                (r + i < n && c - i >= 0 && grid[r + i][c - i] == 1) ||
                (r + i < n && c + i < n && grid[r + i][c + i] == 1)) {
                return false;
            }
        }

        // If no conflicts, return true
        return true;
    }

    void add_ans(vector<vector<string>> &ans, vector<int> &columns, int n) {
        vector<string> curr;
        for (auto i : columns) {
            string row = "";
            for (int j = 0; j < n; ++j) {
                if (j != i) row += ".";
                else row += "Q";
            }
            curr.push_back(row);
        }

        ans.push_back(curr);
    }

    void backtrack(int r, int n, vector<vector<int>> &grid, vector<vector<string>> &ans, vector<int> &columns) {
        if (r == n) {
            add_ans(ans, columns, n);
            return;
        }

        // for each cell on the row, check if we can place a queen here
        for (int c = 0; c < n; ++c) {
            grid[r][c] = 1;
            if (check(r, c, grid, n)) {
                columns.push_back(c);
                backtrack(r + 1, n, grid, ans, columns);
                columns.pop_back();
            }
            grid[r][c] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> columns;
        vector<vector<int>> grid(n, vector<int>(n, 0));
        
        backtrack(0, n, grid, ans, columns);

        return ans;
    }
};