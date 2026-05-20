## Greedy Algorithms

Greedy algorithms are a class of algorithms that solve problems by making a sequence of choices, each of which looks the best at the moment. At every step, a greedy algorithm picks the locally optimal solution, hoping that these choices will lead to a globally optimal solution.

### Core Principles

- **Greedy-choice property:** A global optimum can be arrived at by selecting a local optimum.
- **Optimal substructure:** An optimal solution to the problem contains optimal solutions to its subproblems.

### How Greedy Algorithms Work

1. Start with an empty solution.
2. At each step, make the choice that seems best right now.
3. Add this choice to the current solution.
4. Repeat until the problem is solved.
5. No backtracking or revisiting previous choices.

### Pros and Cons

**Pros:**

- Simple and intuitive
- Usually fast and efficient (often O(n log n) or better)
- Require less memory than dynamic programming

**Cons:**

- May not always produce the optimal solution for all problems
- Only works when the problem has the greedy-choice property and optimal substructure

### Classic Examples

- **Coin Change (minimize coins):** Always pick the largest coin value not exceeding the remaining amount.
- **Activity Selection:** Always pick the next activity that finishes earliest.
- **Huffman Coding:** Build an optimal prefix code by repeatedly combining the two least frequent symbols.
- **Kruskal's/Prim's Algorithm:** For finding minimum spanning trees in graphs.

### When to Use

Use greedy algorithms when you can prove that local choices lead to a global optimum, or when an approximate solution is acceptable and speed is important.
