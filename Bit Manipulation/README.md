[1979B XOR Sequences](https://codeforces.com/contest/1979/problem/B "1979B XOR Sequences") <br>
Convert each of x, and y to their binary representation and you will observe that the answer is always 2 to the power of the length of matching bits from x and y starting from the LSB until the first difference occures. <br>

[67. Add Binary](https://leetcode.com/problems/add-binary/description/ "67. Add Binary") <br>
The same logic like the n-bit adder if you are familiar with logic design. For each index `i`, add the two bits `a[i]` and `b[i]`, and the carry, if the sum is 0, add 0 and carry 0, if the sum is 1, add 1 and carry 0, if the sum is 2, add 0 and carry 1, if the sum is 3, add 1 and carry 1. <br>

[136. Single Number](https://leetcode.com/problems/single-number/description/ "136. Single Number") <br>
For any number x, `x XOR x = 0` and `x XOR 0 = x` <br>