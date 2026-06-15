# Backtracking & Branch and Bound — Practice Problems

## Backtracking

### Done
- N-Queens
- Subset Sum
- All Subsets

### Todo

**Permutations**
Generate all permutations of an array `[1, 2, 3]`.
Hint: swap elements in place, recurse, swap back.

**Rat in a Maze**
Given an N×N binary grid (1=open, 0=blocked), find all paths from `(0,0)` to `(N-1,N-1)`.
Moves: up, down, left, right.
Hint: mark visited cells, unmark on backtrack.

**Graph Coloring**
Given a graph and `m` colors, assign colors to nodes so no two adjacent nodes share a color.
Hint: try each color at each node, check neighbors before placing.

**Word Search**
Given a 2D grid of characters and a word, check if the word exists as a connected path in the grid.
Hint: DFS from each cell, mark visited, unmark on backtrack.

**Palindrome Partitioning**
Given a string, find all ways to split it so every part is a palindrome.
Example: `"aab"` → `[["a","a","b"], ["aa","b"]]`

**Sudoku Solver**
Fill a 9×9 grid with digits 1–9 such that every row, column, and 3×3 box contains each digit once.
Hint: find next empty cell, try 1–9, check validity, recurse.

**Knight's Tour**
Move a chess knight on an N×N board such that it visits every square exactly once.
Hint: try all 8 moves from current position, backtrack if stuck.
(Hard — try N=5 first.)

---

## Branch and Bound

The key difference from backtracking: at each node compute an **optimistic upper/lower bound**.
If the bound cannot beat the current best solution, prune the branch entirely.

**0/1 Knapsack** ← start here
Given items with weights and values, maximize value without exceeding weight capacity.
Bound: fractional knapsack value of remaining items (always >= actual best possible).
If `current_value + bound <= best_so_far`, prune.

**Job Assignment**
Assign N jobs to N workers (each has a cost matrix) to minimize total cost.
Bound: for each unassigned job, take the minimum cost across remaining workers.

**Travelling Salesman Problem (TSP)**
Find the shortest route that visits every city exactly once and returns to start.
Bound: sum of minimum outgoing edges from unvisited cities.
(Start with N=4 or N=5 — grows fast.)

**8-Puzzle / 15-Puzzle**
Sliding tile puzzle. Find minimum moves to reach the goal state.
Use BFS + bound (Manhattan distance heuristic) — this is essentially A*.

**Shortest Path (with explicit bounding)**
Find shortest path in a weighted graph.
Bound: 0 (no negative edges assumed). This reduces to Dijkstra — implement it as
branch and bound to feel the connection.

---

## Dynamic Programming

The key idea: overlapping subproblems + optimal substructure. Store results of subproblems
to avoid recomputing. Two approaches — top-down (memoization) or bottom-up (tabulation).

### 1D DP

**Fibonacci** ← warmup
Compute nth Fibonacci without recomputing. Just memoize the naive recursion.
Then redo it bottom-up with an array.

**Climbing Stairs**
You can climb 1 or 2 steps at a time. How many ways to reach step N?
Hint: `ways[i] = ways[i-1] + ways[i-2]`. Same recurrence as Fibonacci.

**House Robber**
Given an array of house values, maximize loot without robbing two adjacent houses.
Recurrence: `dp[i] = max(dp[i-1], dp[i-2] + a[i])`

**Longest Increasing Subsequence (LIS)**
Find the length of the longest strictly increasing subsequence in an array.
Example: `[10, 9, 2, 5, 3, 7, 101, 18]` → `4` (`[2, 3, 7, 101]`)
Hint: `dp[i]` = LIS ending at index `i`.

**Coin Change**
Given coin denominations and a target amount, find the minimum number of coins needed.
Recurrence: `dp[i] = min(dp[i - coin] + 1)` for each coin.

### 2D DP

**0/1 Knapsack** ← do this after branch and bound version, compare the two
`dp[i][w]` = max value using first `i` items with capacity `w`.
Recurrence: either skip item `i` or take it if it fits.

**Longest Common Subsequence (LCS)**
Given two strings, find the length of their longest common subsequence.
Example: `"ABCBDAB"` and `"BDCAB"` → `4` (`"BCAB"`)
Recurrence: if chars match, `dp[i][j] = dp[i-1][j-1] + 1`, else `max(dp[i-1][j], dp[i][j-1])`.

**Edit Distance (Levenshtein)**
Minimum insertions, deletions, substitutions to convert string A to string B.
Classic interview problem. Build the 2D table carefully.

**Matrix Chain Multiplication**
Given dimensions of matrices, find the optimal order to multiply them minimizing operations.
Hint: `dp[i][j]` = min cost to multiply matrices `i` through `j`.
(Harder — do LCS first.)

**Longest Palindromic Subsequence**
Find the longest subsequence of a string that is a palindrome.
Hint: LCS of the string with its reverse.

### On grids

**Unique Paths**
Count paths from top-left to bottom-right of an M×N grid, only moving right or down.
`dp[i][j] = dp[i-1][j] + dp[i][j-1]`

**Min Path Sum**
Same grid, but each cell has a cost. Find path with minimum total cost.
Same recurrence, take min instead of sum.
