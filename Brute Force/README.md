`Selection Sort.cpp` is the implementation of the selection sort algorithm by the brute force approach using cpp. We traverse the array by two nested loops and a pointer to some element and the other loop to find the index of the minimum number in the rest of the array and then, swap it with the current number if smaller than. <br>

[U - Knight Fork](https://vjudge.net/contest/561486#problem/U "U - Knight Fork") <br>
Brute force all the possible points that form sqrt(5) distance from the first point and see if it makes sqrt(5) distance from the second point. <br>

[1541B Pleasant Pairs](https://codeforces.com/problemset/problem/1541/B "1541B Pleasant Pairs") <br>
A simple brute force but with a trick that we sort the array with keeping track of the indices, and if the value of `v[i] * v[j]` is greater than `2n`, we break the search for the current pair. This is because `i + j < 2n` always so, `v[i] * v[j]` must be always less than `2n` too. <br>


[1536B Prinzessin der Verurteilung](https://codeforces.com/problemset/problem/1541/B "1536B Prinzessin der Verurteilung") <br>
The longest possible length of the answer can not be more than 3 characters. Since the number of substrings with 3 or less characters in an input of length `n` is equal to `n + n - 1 + n - 3` which is `3n - 3`. There's total of `26^1 + 26^2 + 26^3` which is `18278` substrings of length 3 or shorter, so `3n - 3` < `18278` for `n <= 1000`. <br>
