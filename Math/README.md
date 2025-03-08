[2582. Pass the Pillow](https://leetcode.com/problems/pass-the-pillow/description/ "2582. Pass the Pillow") <br>
The time required for each round to be done is n - 1 so, we can calculate the total number of rounds, that will be equal to `number of rounds = time / (n - 1)`, this gives us the number of completed rounds either from 1 -> n or from n -> 1, however, we might complete moving after a round is done, either from left to the right or vice versa so, we calculate the remaining moves after all the rounds are done which will be equal to `remaining moves = time % (n - 1)`. If the number of rounds is even, then we moved from 1 -> n and then moved from n -> 1 and stopped, meaning that the remaining moves will be from 1 towards n. If the number of rounds is odd, then we moved from 1 -> n and stopped, meaning that the remaining moves will be from n towards 1.<br>

[7. Reverse Integer](https://leetcode.com/problems/reverse-integer/description/ "7. Reverse Integer") <br>
Initialize a variable `ans` with 0, keep shifting it one unit to the left each time, add the right-most digit in `x`, divide `x` by 10 to remove the right-most digit.<br>

[1996D Fun](https://codeforces.com/contest/1996/problem/D "1996D Fun") <br>
We can brute force on a as long as it keeps the conditions satisfied, and then brute force again on b, however, we can not do a regular brute force on b as it will get TLE so, we will only try the numbers that makes the term `ab` less than or equal n AND the term `a + b` less than or equal n so, we will try all the numbers from `1 -> n / a`. Now we have a and b, we need to calculate c, well to do so we will take c as a common factor from both conditions to see that for a known value of a and b, c can be less than or equal `(n - (a * b)) / (a + b)` or less than or equal `x - a - b`, we check if the two conditions are valid with each value and if so, add all the numbers of c from 1 unitl this chosen c. <br>

[1995B2 Bouquet (Hard Version)](https://codeforces.com/contest/1995/problem/B2 "1995B2 Bouquet (Hard Version)") <br>
For each number flower type `num`, we will try to take as much as we can afford from `num`, that is either all the occurences of `num` or the value `m / num`, let this number be called `mul1`. Now we have petals of value `mul1 * num`, Now, if there's a type equals to `num + 1`, we can take flowers from this type in the same boquet so, we will try to take as much as we can afford from `num + 1`, that is either all the occurences of `num + 1` or the value `( m - mul1 * num ) / (num + 1)`, which is the how many `(num + 1)` we still can afford with the remaining coins. Now we want to replace as much types of `num` with `(num + 1)`, that is the minimum number remaining from both of them after the above operations, however, we can not replace any two pairs unless we still have remaining coins in our wallet.<br>

[2005D Satyam and Counting](https://codeforces.com/contest/2009/problem/D "2005D Satyam and Counting") <br>
Any two vertical points can make `n - 2` distinct triangles, and any point `i` that has `y = 1` can make a new distinct triangle with two points `j` and `k` if each of them has `y = 0` and there `x` coordinates are one step before `i` and one step after `i` each. <br>

[2025B Binomial Coefficients, Kind Of](https://codeforces.com/contest/2025/problem/B "2025B Binomial Coefficients, Kind Of") <br>
When you draw the input-output table, you will observe that the answer is always 2^k. <br>

[1497C1 k-LCM (easy version)](https://codeforces.com/contest/1497/problem/C1 "1497C1 k-LCM (easy version)") <br>
All the possible formulas to the answer are either (1, `n / 2`, `n / 2`) or (`n / 2`, `n / 2`, `n / 4`) or (`n / 2 - 1`, `n / 2 - 1`, 2). <br>


[2030B Minimise Oneness](https://codeforces.com/contest/2030/problem/B "2030B Minimise Oneness") <br>
For any set of conditions zeroes, the `f(t)` is going to be equal to `2^k - 1`, where `k` is the numebr of zeroes, and if we put only one `1` before this group of zeroes, `g(t)` will be equal to `f(t) + 1` so, the absolute value of their differnces will be equal one. <br>

[2026A Perpendicular Segments](https://codeforces.com/contest/2030/problem/B "2026A Perpendicular Segments") <br>
If you started from the point `(0, 0)` and went to some point `(a, a)`, there's a perpendicular line from the point `(0, a)` and the point `(a, 0)`. So, we can figure out that `a` is the minimum of `X` and `Y`. <br>

[1780. Check if Number is a Sum of Powers of Three](https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/ "1780. Check if Number is a Sum of Powers of Three") <br>
Since `n <= 10^7`, then the maximum power of three we can use is `3^15`. Using this information, we can construct an array of powers of three from 0 up to 15 and start forming the given number `n` using this array by subtracting each item from `n` until it reaches zero, indicating success, or a negative number, indicating failure, and returning the result.

[2579. Count Total Number of Colored Cells](https://leetcode.com/problems/count-total-number-of-colored-cells/description/ "2579. Count Total Number of Colored Cells") <br>
There's a sequence of increasing the multiples of 4 on each iteration, so the answer will always be: `1, 5, 13, 25, ...`. This can be done using the summation formula `n * (n - 1) / 2`. So the answer will be `1 + 4 * n * (n - 1) / 2`.

[2965. Find Missing and Repeated Values](https://leetcode.com/problems/find-missing-and-repeated-values/description/ "2965. Find Missing and Repeated Values") <br>
Assume that `x` is the repeated number and `y` is the missing number. Using this equation: `sum = perfectSum + x - y`. Let `sumDiff = sum - perfectSum = x - y` (eq1), `sqrDiff = x^2 - y^2 = (x + y) * (x - y)`, then `sqrDiff = (x + y) * sumDiff`, which means that `x + y = sqrDiff / sumDiff` (eq2).
Solving eq1 and eq2, we can get `x` and `y`.

