## Dynamic Programming (DP)

Dynamic Programming is a powerful algorithmic technique used to solve problems by breaking them down into simpler overlapping subproblems and storing the results of these subproblems to avoid redundant computation. It is especially useful for optimization problems where recursive solutions would otherwise be inefficient due to repeated work.

### Core Principles
- **Optimal Substructure:** The optimal solution to a problem can be constructed from optimal solutions to its subproblems.
- **Overlapping Subproblems:** The problem can be broken down into subproblems which are reused multiple times.

### How Dynamic Programming Works
1. Define the subproblems and the recurrence relation.
2. Store the results of subproblems (using memoization or tabulation).
3. Build up the solution to the original problem using these stored results.

**Two main approaches:**
- **Top-down (Memoization):** Solve the problem recursively and cache results.
- **Bottom-up (Tabulation):** Solve smaller subproblems first and use their results to build up solutions to larger subproblems.

### Pros and Cons
**Pros:**
- Guarantees an optimal solution for problems with optimal substructure and overlapping subproblems
- Efficient for many classic problems (often O(n^2) or better)

**Cons:**
- Can use significant memory for large problems
- Requires careful problem analysis to identify subproblems and recurrence

### Classic Examples
- **Fibonacci Sequence:** Store previously computed values to avoid redundant calculations.
- **Coin Change:** Find the minimum number of coins for a given amount.
- **Longest Common Subsequence / Substring:** Find the longest sequence present in both strings.
- **Knapsack Problem:** Maximize value with weight constraints.
- **Edit Distance:** Minimum operations to convert one string to another.

### When to Use
Use dynamic programming when a problem can be divided into overlapping subproblems with optimal substructure, and when brute-force or naive recursion is too slow due to repeated work.
