class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        int curr_idx = 0, step = 1;
        vector<vector<char>> grid(numRows);

        for (auto ch : s) {
            grid[curr_idx].push_back(ch);

            // if we reached the bottom or the top, reverse the direction
            if (curr_idx == 0) step = 1;
            else if (curr_idx == numRows - 1) step = -1;

            curr_idx += step;
        }

        string ans = "";
        for (auto arr : grid) 
            for (auto ch : arr) 
                ans += ch;

        return ans;
    }
};