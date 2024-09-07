[706B Interesting Drink](https://codeforces.com/problemset/problem/706/B/ "706B Interesting Drink")<br>
Sort the array and make a binary search on the first number greater than m using upper_bound() <br>

[102961U Factory Machines](https://codeforces.com/problemset/gymProblem/102961/U "102961U Factory Machines") <br>
Binary Search the answer by testing whether all products can be done withtin this period or not <br>

[1085 Array Divisions](https://cses.fi/problemset/task/1085 "1085 Array Divisions") <br>
Binary Search the answer by tracking the sum and count, once the sum pass the answer, start again. <br>

[102961G Sum of Two Values](https://codeforces.com/problemset/gymProblem/102961/G "102961G Sum of Two Values") <br>
For each number, Binary Search the number that makes a pair with it. <br>

[102961ZA Subarray Sums I](https://codeforces.com/problemset/gymProblem/102961/ZA "102961ZA Subarray Sums I") <br>
Compute the prefix sum array, and Binary Search the number that if we subtracted it from the first one, we get x, this means that this subarray's sum is equal to x. <br>

[102961H Maximum Subarray Sum](https://codeforces.com/problemset/gymProblem/102961/H "102961H Maximum Subarray Sum") <br>
Keep Tracking the sum, once it goes below zero, start again. <br>

[287B Pipeline](https://codeforces.com/problemset/problem/287/B "287B Pipeline") <br>
First, calculate the maximum possible outputs, then we do Binary Search to find how splitters we can get rid of and achieving the same outputs. <br>

[1793C Dora and Search](https://codeforces.com/problemset/problem/1793/C "1793C Dora and Search") <br>
The minimum number in the permutaion will be always 1 and the maximum will be always n, then start iterating with two pointers and check if the ends are min or max. <br>

[279B Books](https://codeforces.com/problemset/problem/279/B "279B Books") <br>
We make two pointers pointing to the beginnig of the array and start going right, if the sum is greater than t, move the left pointer one step right, else move the left pointer one step right. <br>

[1792C Min Max Sort](https://codeforces.com/problemset/problem/1792/C "1792C Min Max Sort") <br>
Binary Search a number x that if removed the pair x, n - x + 1 from the array, it is sorted. This number is between n ans (n + 1) / 2, for example, if n = 6, the pairs will be : 1,6 2,5 3,4. <br>

[1980C Sofia and the Lost Operations](https://codeforces.com/contest/1980/problem/C "1980C Sofia and the Lost Operations") <br>
Generating the C array by calculating the modifications to make and iterate over the d array from the end to the beginning and start plotting the modifications. <br>

[1978B New Bakery](https://codeforces.com/contest/1978/problem/B "1978B New Bakery") <br>
Binary search to find the best k to maximize the answer. Notice that k is inversely proportional to the index (i), and the constraints are 1e9, so the loops are replaced with mathematical expressions. <br>

[209. Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/description/ "209. Minimum Size Subarray Sum") <br>
Minimum answer is the length 1, and the maximum answer is the length n (the whole array). Since we know the range of the answer, and it is a sorted range (1 -> n), we can do binary search to find the minumum answer that satisfies the condition (sum <= target). We used a prefix sum array to calculate the sum in O(1) inside the loop that acts like a sliding window.<br>

[1998C Perform Operations to Maximize Score](https://codeforces.com/contest/1998/problem/C "1998C Perform Operations to Maximize Score") <br>
We need to maximize `a + med`, we would take the input as a vector of pair of integers so that we keep track of which index we can increment after sorting. We would try to maximize `a` first so, we would iterate over each number in the array and increment it with all the `k`s we have and store the maximum value we got. To maximize the `med` we would simply binary search on the maximum `med` we could achieve, we would count the number of numbers which are greater than or eqaul to the current `mid` and store the values we need to make each number less than `mid` in an array `need`, then we will try to make as much numbers as we can to be equal to the current `mid` by incrementing them until they reach `mid` from our `k` until it gets to zero. Finally if we have at least `(n + 1) / 2` numbers which are ( greater than or ) equal to the current `mid`, then this `mid` is valid. <br>

[2009E Klee's SUPER DUPER LARGE Array!!!](https://codeforces.com/contest/2009/problem/E "2009E Klee's SUPER DUPER LARGE Array!!!") <br>
It's known that the sum of numbers between an integer `n` and another integer `m` can be calculated by the formula `((m - n + 1) * (n + m)) / 2` so, simply we would binary search on the answer and try to minimize it. <br>
