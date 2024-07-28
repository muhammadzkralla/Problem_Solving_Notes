[31. Next Permutation](https://leetcode.com/problems/next-permutation/description/ "31. Next Permutation") <br>
Search for the first number that breaks the increasing sequence from right to left. When you find this number, nums[i] for example, you will start moving back to the right to find the farest number that is just above the number that broke the sequence, nums[j] for example, swap nums[i] and nums[j], and reverse the rest of the array starting from i to the end of the array.
As nums[j] is the farest number that is just greater than nums[i] (the nearest number greater than it in natural numbers), when we swap them and reverse the rest of the array from i to the end, we assure this permutation is just bigger than nums array.<br>

[15. 3Sum](https://leetcode.com/problems/3sum/description/ "15. 3Sum") <br>
Consider that we are searching for numbers x, y, z such that x + y + z equal to zero. Since the constraints are small, we can brute force to find x, y and do binary search to find the remaining z such that z = - (x + y). One last thing you must notice is that duplicates are not allowed.<br>

[48. Rotate Image](https://leetcode.com/problems/rotate-image/description/ "48. Rotate Image") <br>
Transpose the matrix by swapping all the numbers on the top of the main diagonal with the corresponding ones under the main diagonal and then replace each column `j` with the column `n - j - 1` or in other words, the first column with the last one, the second column with the one before the last, an so on.<br>

[1996C Sort](https://codeforces.com/contest/1996/problem/C "1996C Sort") <br>
As we will sort both strings from l -> r in each query, we will need to change only the characted that does not happen in the other string, for example, if `a = abcde`, `b = edcba`, `l = 1`, and `r = 4`, then after sorting, `a = abcd`, b = `bcde`, then we only need to change the 'e' in `b` to 'a', however, as the input can go up to 1e5, we can not brute force or process each query one by one, instead we will construct a prefix sum array indicating the number of occurence of each character untill the current index `i`.
<br>