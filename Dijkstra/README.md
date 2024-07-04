`Dijkstra.cpp` is the solution to the Trading for a piano problem on chapter 7 in Grokking Algorithms book. <br>

[20C Dijkstra_](https://codeforces.com/problemset/problem/20/C "20C Dijkstra_") <br>
Standard Dijkstra implementation but take care that maybe there won't be a valid path from start to target. <br>

[938D Buy a Ticket](https://codeforces.com/contest/938/problem/D "938D Buy a Ticket") <br>
Standard Dijkstra implementation but take care that there's an initial cost for each node so, we add them initially and since we know the current cost of each node, we will add all the nodes to the processing set to calculate the smallest cost for its neighabours.<br>

[1433G Reducing Delivery Cost](https://codeforces.com/problemset/problem/1433/G "1433G Reducing Delivery Cost") <br>
We will brute force and see the effect of removing each path, however, if you did so, you will get TLE. So we will do some precalculations first, run standard Dijkstra algorithm to find the cheapest path from each state to the other before removing the cost of any roads and store these values in the dis array. Now we can brute force and try to remove the cost of each road and calculate the total costs of the couriers trips to minimize the answer.<br>