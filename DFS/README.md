`0-lockboxes.py` is the solution to the second interview question in ALX SWE. We will just run a standard DFS algorithm and if we visited all the nodes, we can unlock all, otherwise we can not. <br>

[1997D Maximize the Root](https://codeforces.com/contest/1997/problem/D "1997D Maximize the Root") <br>
We will binary search on the answer and maxmize it, for each mid in the binary search, we perform a DFS and check if it's doable or not by seeing if we are at the root and the current mid is already less than or equal the value of root, it's a valid answer. If we are at the root and the current mid is more than the value of root then, we need to add the value (ans - root) to the root to achieve such answer. We perform DFS to see if we can do such answer or not and watch out for the overflow.<br>

[abc373d Hidden Weights](https://atcoder.jp/contests/abc373/tasks/abc373_d "abc373d Hidden Weights") <br>
This problem can be seen as a set of equations that need to be solved together, so we will make some `x` equal to zero and start iterating over the other nodes of the graph and make sure the constraints are done.<br>
