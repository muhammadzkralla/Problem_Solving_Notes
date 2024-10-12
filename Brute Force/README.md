`Selection Sort.cpp` is the implementation of the selection sort algorithm by the brute force approach using cpp. We traverse the array by two nested loops and a pointer to some element and the other loop to find the index of the minimum number in the rest of the array and then, swap it with the current number if smaller than. <br>

[U - Knight Fork](https://vjudge.net/contest/561486#problem/U "U - Knight Fork") <br>
Brute force all the possible points that form sqrt(5) distance from the first point and see if it makes sqrt(5) distance from the second point. <br>

[1541B Pleasant Pairs](https://codeforces.com/problemset/problem/1541/B "1541B Pleasant Pairs") <br>
A simple brute force but with a trick that we sort the array with keeping track of the indices, and if the value of `v[i] * v[j]` is greater than `2n`, we break the search for the current pair. This is because `i + j < 2n` always so, `v[i] * v[j]` must be always less than `2n` too. <br>

