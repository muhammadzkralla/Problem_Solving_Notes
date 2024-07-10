[64. Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/description/ "64. Minimum Path Sum") <br>
Iterate over the matrix, update each number `grid[i][j]` to `grid[i][j] + min(grid[i - 1][j], grid[i][j - 1])`. This indicates the value of the minimum cost that we can go to this cell with, either from the top or the left.
<br>