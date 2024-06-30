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