[1986D Mathematical Problem](https://codeforces.com/contest/1986/problem/D "1986D Mathematical Problem") <br>
n - 2 operations means that there will be only one pair of digits treated as one number, so we brute force and try each pair of numbers as the constraints are low and minimize the answer. If there's a zero digit, then the answer is zero as we can multiply it by the rest of the digits. All ones are ignored as the best solution for them is to multiply by them, otherwize the best decision is to add the digit. <br>

[397. Integer Replacement](https://leetcode.com/problems/integer-replacement/description/ "397. Integer Replacement") <br>
Let's agree that if the number is even, the optimal process to do is to divide it by two as this would make it go down to 1 faster. Ok what if the number is odd? You should decide whether to decrement or increment the number by one, when to do what? Either choices will make the number even, however, if incrementing the number results in a multiple of 4, it is guaranteed that this number can be divided by two more than once, which results in less number of operations except for the number 3 which is an edge case. Otherwise, decrement the number.<br>

[334. Increasing Triplet Subsequence](https://leetcode.com/problems/increasing-triplet-subsequence/description/ "334. Increasing Triplet Subsequence") <br>
We will create two variables to store the minimum number we passed by and the other to see if we passed by a number that is greater than the first minimum number but less than the current number. If the current number we are at, is greater than both of the two variables before, we have the triplet. More formally, `mn` will hold the minimum number we have found yet, `mx` will hold the number that's greater than `mn` but less than current `mx`, if the current number we are processing is greater than both `mn` and `mx`, it's the third number in the triplet.<br>

`0-minoperations.py` is the solution to the third interview question in ALX SWE. We have three variables, `count` the number of current 'H's in the string, `operations` the number of applied operations, `clipboard` the number of current 'H's we can paste right now. While `count` is less than the required number `n`, each time we need to choose the optimal move, which is: If the `n` is a multiple of `count` paste, otherwise, we copy and paste until `n` becomes a multiple of `count` <br>

[1992D Test of Love](https://codeforces.com/contest/1992/problem/D "1992D Test of Love") <br>
We always try to reach the nearest possible log. We keep moving forward and if the current cell is a log, then we can move more `m - 1` cells forward. If it's a water cell and we can not move any cells forward, then we must step on it and count it as we cannot step on water for more than `k` times. If it's not a log or a water cell and w can not move any cells forward, then we can not reach the end without stepping on a crocodile.  <br>

[455. Assign Cookies](https://leetcode.com/problems/assign-cookies/description/ "455. Assign Cookies") <br>
By sorting both arrays, we can now iterate over the sizes array `s[i]` and calculate the optimal child that should take this cookie from the array `g[j]`. Therefore the minimum item in `s` can only take the minimum item in `g` that satisfies the condition `s[i] >= g[j]`. The answer is the number of the taken cookies (`j`) from the greed array `g`.
<br>

[1990B Array Craft](https://codeforces.com/contest/1990/problem/B "1990B Array Craft") <br>
The mutual range between the both the prefix and the suffix, must be all ones to maximize them so, we set all the numbers between `y` and `x` to one. Then we want to make the range before `y` and the range after `x` to have either a total sum of a negative number or zero to keep the condition satisfied and not incrementing the range after `x` or before `y` so, we will try to make these ranges have an average sum of zero by making a sequence of `1 -1 1 -1 1 -1` and so on so that when you add these ranges the total sum will be zero and not break the conditions.
<br>

[2001D Longest Max Min Subsequence](https://codeforces.com/contest/2001/problem/D "2001D Longest Max Min Subsequence") <br>
To achieve our goal, we need to first calculate the maximum length of our answer. It can be easily observed that it's the number of distinct items in the given array as we can not have duplicates. Another thing that can be observed is that we need to make the first item as high as possible and the second item as low as possible, the third high, the fourth low, and so on. That's because when the odd indices are going to be multiplied by -1, they become as low as possible to achieve the lowest lexicographical order possible, and the even indices are unchanged so we need them to be low. Now we need to construct the answer greedily. We will start by counting the unique items in the input array `a` and store their last occuring index, we will know why soon. Now we will construct the answer array `ans` by going through the input array `a` and do the following : <br>
consider that we are now at the position `i` in the input array `a` such that `0 < i < n`, we will search for the most suitable place in the answer array `ans` for the current item `a[i]` to be inserted at by checking if this place in the answer array `ans` must be maximized? If `a[i]` is greater, then remove it from answer to insert `a[i]`. If this place in answer must be minimized? If `a[i]` is lower, then remove it from the anser to insert `a[i]`. Keep searching for the best place to insert `a[i]` at in the answer array `ans` as long as the answer array is not empty. However, you can not remove any item from answer if their last occuring index is lower than `i` as if we removed it from the answer now, we can not add it again to the answer in the fututre and thus, the length of the answer is reduced and then it's not the lowest lexicographical order possible.
<br>

[2033C Sakurako's Field Trip](https://codeforces.com/contest/2033/problem/C "2033C Sakurako's Field Trip") <br>
We will iterate over each item in the array `a[i]` and also notice the `a[n - i - 1]` item, for each one, we will check if `a[i]` makes a problem with `a[i - 1]` and if `a[n - i - 1]` makes a problem with `a[n - i]`. If both of them create a problem, then we will ckeck if swapping can reduce half of the problem or the whole problem. If only one item creates a problem, then we will check if swapping can remove the problem or not. For each scenario of them, we would swap if it creates a better solution.
<br>

[abc382C - Kaiten Sushi](https://atcoder.jp/contests/abc382/tasks/abc382_c "abc382C - Kaiten Sushi") <br>
We will calculate the suitable index for each value of `b` anyways (it can be considered dp). <br>

[2818. Apply Operations to Maximize Score](https://leetcode.com/problems/apply-operations-to-maximize-score/description/ "2818. Apply Operations to Maximize Score") <br>
First, for each number in `nums`, count its distinct prime factors. Use the Sieve of Eratosthenes to precompute primes up to the maximum value in nums and then factor each number to get its prime score. The computed prime score tells you the importance of a number. Higher prime scores mean the number is more valuable for multiplication. Next, for each index `i` in `nums`, determine how many subarrays where `nums[i]` is the dominant element. Use a monotonic stack to compute:
- `left[i]`: nearest index to the left where the prime score is greater than or equal to `s[i]` (set to -1 if none).
- `right[i]`: nearest index to the right where the prime score is greater than `s[i]` (set to `n` if none).
For each index `i`, the number of subarrays where `nums[i]` is dominant is:
`(i - left[i]) * (right[i] - i)`
This gives you how many times you could potentially use `nums[i]` in your operations. Sort the elements of nums in descending order along with their indices. This lets you greedily pick the numbers that contribute most to the score. Loop through the sorted numbers. For each number, decide the number of operations to use:
`ops = min(remaining k, number of subarrays where this number is dominant)`
Then, reduce `k` by operations. Update your overall score by multiplying it by `nums[i]` raised to the power of `ops`. Since the numbers can be huge, perform the multiplication modulo `10⁹+7`. For fast power calculations, implement binary exponentiation.
