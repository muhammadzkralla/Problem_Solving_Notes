• Backtracking algorithm is simply brute forcing each and every choice. <br>

• Backtracking is like trying different paths, and when you hit a dead end, you backtrack to the last choice and try a different route. <br>

• It is commonly used in problems like searching for a path in a maze, solving puzzles like Sudoku, or getting all the possible combinations and permutations of an array. <br>

• Backtracking can be defined as a general algorithmic technique that considers searching every possible combination in order to solve a computational problem. <br>

• Pseudocode for Backtracking : <br>
```text
void FIND_SOLUTIONS( parameters):

if (valid solution):

store the solution

Return

for (all choice):

if (valid choice):

APPLY (choice)

FIND_SOLUTIONS (parameters)

BACKTRACK (remove choice)

Return
```

<br>

[Backtracking GFG](https://www.geeksforgeeks.org/introduction-to-backtracking-2/ "Backtracking GFG) <br>


[397. Integer Replacement](https://leetcode.com/problems/integer-replacement/description/ "397. Integer Replacement") <br>
Standard backtracking, we just try each possible operation each time and minimize the answer. Just put in mind that if the number became even, you should always divide by two and if it was odd, we try both scenarios on each time, increase by one or decrease by one.
<br>