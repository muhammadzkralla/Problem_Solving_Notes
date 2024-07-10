#!/usr/bin/python3
"""
Greedy solution to minOperations
Question : 
In a text file, there is a single character H. Your text editor can execute only two operations in this file:
Copy All and Paste. Given a number n,
write a method that calculates the fewest number of operations needed to result in exactly n H characters in the file.

Prototype: def minOperations(n)
Returns an integer
If n is impossible to achieve, return 0
Example:

n = 9

H => Copy All => Paste => HH => Paste =>HHH => Copy All => Paste => HHHHHH => Paste => HHHHHHHHH

Number of operations: 6
"""


def minOperations(n):
    """ Count the minimum number of operations to reach n. """
    count, operations, clipboard = 1, 0, 0

    while count < n:
        # if n is a multiple of count, copy all and paste, otherwise, just copy all.
        if n % count == 0:
            operations = operations + 2
            clipboard = count
            count = count + clipboard
        else:
            operations = operations + 1
            count = count + clipboard

    return operations

n = 4
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 12
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))