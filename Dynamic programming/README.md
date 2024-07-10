[64. Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/description/ "64. Minimum Path Sum") <br>
Iterate over the matrix, update each number `grid[i][j]` to `grid[i][j] + min(grid[i - 1][j], grid[i][j - 1])`. This indicates the value of the minimum cost that we can go to this cell with, either from the top or the left.
<br>

[5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/description/ "5. Longest Palindromic Substring") <br>
We will create a 2d matrix of booleans `dp`, this matrix represents the following, for each row `dp[i]`, if the value of `dp[i][j]` is true, then the substring from `i -> j` is a palindrome. To calculate this matrix, we will set the values of `dp[i][i]` to true for all `0 < i < n` as each single char is a palindrome, and then we iterate over all the distances between two pointers `l` and `r` and see if `s[l] == s[r]` and `dp[l + 1][r - 1]` is a valid palindrome, then the substring from `l -> r` is also a valid palindrome, or if they are just after each other, then it's also a valid palindrome. 
<br>