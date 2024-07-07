`Dijkstra.cpp` is the solution to the Trading for a piano problem on chapter 7 in Grokking Algorithms book. <br>

[20C Dijkstra_](https://codeforces.com/problemset/problem/20/C "20C Dijkstra_") <br>
Standard Dijkstra implementation but take care that maybe there won't be a valid path from start to target. <br>

[938D Buy a Ticket](https://codeforces.com/contest/938/problem/D "938D Buy a Ticket") <br>
Standard Dijkstra implementation but take care that there's an initial cost for each node so, we add them initially and since we know the current cost of each node, we will add all the nodes to the processing set to calculate the smallest cost for its neighbours.<br>

[1433G Reducing Delivery Cost](https://codeforces.com/problemset/problem/1433/G "1433G Reducing Delivery Cost") <br>
We will brute force and see the effect of removing each path, however, if you did so, you will get TLE. So we will do some precalculations first, run standard Dijkstra algorithm to find the cheapest path from each state to the other before removing the cost of any roads and store these values in the dis array. Now we can brute force and try to remove the cost of each road and calculate the total costs of the couriers trips to minimize the answer.<br>

[144D Missile Silos](https://codeforces.com/contest/144/problem/D "144D Missile Silos") <br>
We want to count all the spots such that the shortest path from the capital to this spot is exactly equal to some value `L`. These spots can be a city or some point that lies on an edge between two cities. The first case ( a city ) can be calculated by standard dijkstra algorithm to count the shortest path from the capital to any other city and count how many values will be exactly `L`. The second case ( a point that lies on an edge between two cities ) can be calculated by brute force and trying every possible edge between two cities and see if there's a valid spot somewhere on this edge that is 'L' meters from the capital. You will face an edge case where a point can coincide with the other point on the same edge. Remember that each edge can have 0, 1, 2 spots lying on it, 2 when there's one spot starting from each city, 1 when these two spots coincide, and 0 if there's no valid spot on the edge from neither cities.<br>

[449B Jzzhu and Cities](https://codeforces.com/contest/449/problem/B "449B Jzzhu and Cities") <br>
Initially, we would use all the trains as the initial cost of each node is infinity and these trains can get us to the node `b` in a cost of `w` which is definetly less than infinity, and we would add the train to some set `trains` to mark it as used. As we modified the costs of some nodes, we would initiate the priority queue with all the nodes to make sure we process all of them optimally. Now check if we can reach v in a cheaper way and if it exists and we are using a train for this, remove it.<br>