`01. Knapsack` is the solution to the knapsack problem on chapter 9 in Grokking Algorithms book. <br>

[64. Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/description/ "64. Minimum Path Sum") <br>
Iterate over the matrix, update each number `grid[i][j]` to `grid[i][j] + min(grid[i - 1][j], grid[i][j - 1])`. This indicates the value of the minimum cost that we can go to this cell with, either from the top or the left.
<br>

[5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/description/ "5. Longest Palindromic Substring") <br>
We will create a 2d matrix of booleans `dp`, this matrix represents the following, for each row `dp[i]`, if the value of `dp[i][j]` is true, then the substring from `i -> j` is a palindrome. To calculate this matrix, we will set the values of `dp[i][i]` to true for all `0 < i < n` as each single char is a palindrome, and then we iterate over all the distances between two pointers `l` and `r` and see if `s[l] == s[r]` and `dp[l + 1][r - 1]` is a valid palindrome, then the substring from `l -> r` is also a valid palindrome, or if they are just after each other, then it's also a valid palindrome. 
<br>

[1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/description/description/ "1143. Longest Common Subsequence") <br>
We iterate over each character of `text1` using the outer loop and each character of `text2` using the inner loop. If the characters at the current positions `i - 1` and `j - 1` in `text1` and `text2` match, it means we can extend the length of the common subsequence found so far by 1, hence `dp[i-1][j-1] + 1`. If the characters do not match, we take the maximum value of the subsequences found so far by either excluding the current character of `text1` or `text2`, hence `max(dp[i-1][j], dp[i][j-1])`.
<br>

[1994C Hungry Games](https://codeforces.com/contest/1994/problem/C "1994C Hungry Games") <br>
For each index `i`, we will store the number of valid subsegments that starts with `i` in the array `dp[i]`. To find such value for each index, we need to find the minimum index `j` such that the sum on the subsegment `i -> j` is greater than `x`, in such index, the value of `g` will become zero so, when we find such index, then the valid subsegments that starts with `i` are all the subsegments from `i -> j` which is equal to `j - i - 1` plus the number of valid subsegments starting with `j` which is equal to `dp[j]`. Why we add `dp[j]`? Because the value `g` is set to zero at `j` as its value got greater than `x` so, the valid subsegments starting with the index `j` will be also valid if we started from the index `i`.
<br>