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

[Backtracking GFG](https://www.geeksforgeeks.org/introduction-to-backtracking-2/ "Backtracking GFG") <br> <hr>


[397. Integer Replacement](https://leetcode.com/problems/integer-replacement/description/ "397. Integer Replacement") <br>
Standard backtracking, we just try each possible operation each time and minimize the answer. Just put in mind that if the number became even, you should always divide by two and if it was odd, we try both scenarios on each time, increase by one or decrease by one.
<br>

[77. Combinations](https://leetcode.com/problems/combinations/description/ "77. Combinations") <br>
We push a number to the array and keep pushing the next numbers until we reach the required size, once this happen, we remove the last number added and complete after it, for example if we have n = 5 and we need combinations of size 3, we will have `1 2 3` -> `remove 3` -> `1 2 4` -> `remove 4` -> `1 2 5` -> `remove 5` -> `remove 2` -> `1 3 4` and so on. Remember that we start the loop from the element that's just after the last element as order does not matter in combinations, `1 2 3` is the same as `3 2 1`.
<br>

[46. Permutations](https://leetcode.com/problems/permutations/description/ "46. Permutations") <br>
If you did not solve the combination question above, solve it first or look at the code. We did just the same like in combinations, but we always start the loop from the first element in the array as order matters in permutations unlike combinations. `1 2 3` is not the same as `3 2 1`.
<br>