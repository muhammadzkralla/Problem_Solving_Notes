[abc383C - Humidifier 3](https://atcoder.jp/contests/abc383/tasks/abc383_c "abc383C - Humidifier 3") <br>
We would start a BFS starting from the nodes with value `H`, which corresponds to a humidifier, and test each other nodes if they are with the value `.` and the distance between the two nodes does not exceed `d` and keep track of their count. <br>


[2685. Count the Number of Complete Components](https://leetcode.com/problems/count-the-number-of-complete-components/ "2685. Count the Number of Complete Components") <br>
We will do a simple BFS on each node in the graph and for each BFS call we track the nodes we visited on each iteration `nodes`, and after all the iterations are done, we iterate over all the visited nodes in the `nodes` array  to check if each one have number of edges equal to the total visited nodes in the current BFS search - 1, that's is `node.size() - 1`. <br>
