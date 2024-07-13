class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose the matrix
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                swap(matrix[i][j], matrix[j][i]);

        // swap the first column with the last column and second with the one before the last and so on
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n / 2; ++j)
                swap(matrix[i][j], matrix[i][n - j - 1]);
    }
};