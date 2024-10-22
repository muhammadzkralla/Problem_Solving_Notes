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

[2001B Generate Permutation](https://codeforces.com/contest/2001/problem/B "2001B Generate Permutation") <br>
When you try small test cases, you will find that to make the number of carrige returns for both writers to be equal, we need our array to follow this format : 1, n, 2, (n - 1), 3, (n - 2).. and so on. For example, if n = 5, the array would be {1, 5, 2, 4, 3}, then both writers will return 2 times to their starting. So, we will construct the array and see if both will return to the carrige the same number of times or not by calculating the longest continous sequence from both ends, that is {1, 2, 3} from the start for n = 5, and {3, 4, 5} from the end for n = 5, this means that we will not return to the carrige while adding these numbers so, the number of carrige returns equal to n - length of the sequence, if both writes have the same value, this answer is valid.
<br>

[2024C Concatenation of Arrays](https://codeforces.com/contest/2024/problem/C "2024C Concatenation of Arrays") <br>
We can look at this problem from the perspective of sorting the pairs ascendingly, one way to achive this is to put 
the sum of two numbers and sort the array, and store each number in a separate array so that we can still get the value of 
each number after sorting.
<br>
