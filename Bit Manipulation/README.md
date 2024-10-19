[1979B XOR Sequences](https://codeforces.com/contest/1979/problem/B "1979B XOR Sequences") <br>
Convert each of x, and y to their binary representation and you will observe that the answer is always 2 to the power of the length of matching bits from x and y starting from the LSB until the first difference occures. <br>

[67. Add Binary](https://leetcode.com/problems/add-binary/description/ "67. Add Binary") <br>
The same logic like the n-bit adder if you are familiar with logic design. For each index `i`, add the two bits `a[i]` and `b[i]`, and the carry, if the sum is 0, add 0 and carry 0, if the sum is 1, add 1 and carry 0, if the sum is 2, add 0 and carry 1, if the sum is 3, add 1 and carry 1. <br>

[136. Single Number](https://leetcode.com/problems/single-number/description/ "136. Single Number") <br>
For any number x, `x XOR x = 0` and `x XOR 0 = x` <br>

[1988C Increasing Sequence with Fixed OR](https://codeforces.com/contest/1988/problem/C "1988C Increasing Sequence with Fixed OR") <br>
We will construct the list simply by converting the number `n` to its binary form and keep iterating from the LSB to the MSB, unsetting bits, adding them to the list, and then setting them back to add the next number, for example, consider `n` to be 23, that's `10111` in binary, the next number is going to be `10110` which is 22, and the next one will be `10101` which is 21, and the next one will be `10011` which is 19, and so on until we reach the MSB, why so? Because 'orring' needs at least one bit to be set to output one, so we keep removing the setted bits from the original number `n` and we gaurantee that the 'orring' the resulting number with the one before it will give `n` as `0 | 1 = 1`. There will be only one edge case for numbers with only one setted bit, for example `2` is `10` so, the next valid number will be `00` which is zero, which is not a positive integer so, the if statement makes sure if the input is a one bit setted number, there's no next integer, just `n` in the list.   <br>

[1994B Fun Game](https://codeforces.com/contest/1994/problem/B "1994B Fun Game") <br>
We know that `x ^ x = 0` and `x ^ 0 = x` so, in order to turn a zero into a one, we need a one (0 ^ 1 = 1) and in order to turn a one into a zero, we also need a one (1 ^ 1 = 0) so, in both cases we need a one. From this observation, we will find the first appearence of a one in the array s, let it be calles `idx`, any bit after `idx` can be flipped easily, however, any bit before `idx` can not be flipped so we iterate over the s string and see if there's any bit to be flipped before the `idx`. <br>

[1926D Vlad and Division](https://codeforces.com/contest/1926/problem/D "1926D Vlad and Division") <br> It can be easily observed from the test cases that the minimum number we can reach is exactyl `(n / 2)`. We can proof this by the following, if there's a certain number `n`, it can not be inserted in the same group of any other number except for the number which is the number `n` after converting all its bits (if a bit n[i] is 0, make it 1 and vice versa). So, we will iterate over the array and for each numebr `n` we flip all its bits and see if it occurs in our array or not, if yes, we can put them in one group. We will construct a frequency array saving the number of occurence for each number to decide if a number occurs or not and if yes we will minus the total number of groups by `min(freq[i], freq[comp])` where `i` is the number and `comp` is its flipped version.
 <br>

[1669H Maximal AND](https://codeforces.com/problemset/problem/1669/H "1669H Maximal AND") <br> 
As we try to maximize the resulting AND of the array, we would try to set the bits that are more close to the `MSB` for each number in the array so, we would search all the bits starting from the `MSB` to the `LSB` and set each unset bit as long as we still have operations left.
 <br>

[550B Preparing Olympiad](https://codeforces.com/problemset/problem/550/B "550B Preparing Olympiad") <br> 
Since `n` is too small, we can test all possible cases, which are `2 power n` cases. Treat the existence of a number or not in the current permutation as a bit in the number between `0 to 2 power n`. See the code for more clarity.
 <br>

[1722G Even-Odd XOR](https://codeforces.com/problemset/problem/1722/G "1722G Even-Odd XOR") <br> 
if `n` is even, then the set of even numbers are going to be `[1, 2, 3, ...]`, and the set of odd numbers are going to be also `[1, 2, 3, ...]`. If `n` is odd, then the set of even numbers are going to be `[1, 2, 3, ...]`, and the set of odd numbers are going to be `[0, 1, 2, 3, ...]`. This satisfies the third condition, now we need to satisfy the second condition. Since even number of ones (or any other number) would cancel each other by XORing them, we would just set the last number of bits in each number in the odd set. If the size of the odd set is even, we would just set all the 30th bits in all its items, if it was odd, we would set the 30th bits in the all the items except for the last one, and set the 29th bits in all the items except for the first one.
 <br>

[1553C Penalty](https://codeforces.com/contest/1553/problem/C "1553C Penalty") <br> 
Each `?` has two options, either 1 or 0, since the maximum number of `?` in the input is `10`, then all the possible options are `2^cnt` where `cnt` is the count of `?` in the input, which is at most `1024` so, we can easily brute force all the possible options for each `?` using the truth table from `0` up to `2^cnt`.<br>

[2030C A TRUE Battle](https://codeforces.com/contest/2030/problem/C "2030C A TRUE Battle") <br> 
Since, Alice and Bob should alternate between usign the `and` & `or` operators, if there's a set bit on either edges of the string, Alice can put `or` before, or after it and win anyways. He can also win if there's two set bits next to each other in any place in the string. <br>
