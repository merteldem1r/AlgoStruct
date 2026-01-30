## Sliding Window Technique

The sliding window technique is a powerful method for solving problems involving arrays or strings, especially when you need to examine contiguous subarrays or substrings. Instead of repeatedly iterating over the same elements, a window of fixed or variable size moves through the data, updating results incrementally and efficiently.

### Core Principles
- Maintain a window (range) over a subset of the data.
- Move the window step-by-step, updating the result as you go.
- Avoid redundant computation by reusing information from the previous window.

### How Sliding Window Works
1. Define the window size or the condition for expanding/shrinking the window.
2. Initialize pointers (usually left and right) to represent the window boundaries.
3. Move the window through the data, updating the result as elements enter or leave the window.
4. Continue until the end of the data is reached.

**Types:**
- **Fixed-size window:** Window size remains constant (e.g., max sum of k elements).
- **Variable-size window:** Window size changes based on problem constraints (e.g., longest substring with unique characters).

### Pros and Cons
**Pros:**
- Highly efficient for many subarray/substring problems (often O(n))
- Simple to implement
- Reduces unnecessary computation

**Cons:**
- Not suitable for problems without a clear window structure
- Requires careful management of window boundaries and state

### Classic Examples
- **Maximum sum subarray of size k**
- **Longest substring without repeating characters**
- **Minimum window substring**
- **Number of subarrays with a given sum**

### When to Use
Use the sliding window technique when the problem involves contiguous segments of data and you need to optimize for time and space by avoiding repeated work.
