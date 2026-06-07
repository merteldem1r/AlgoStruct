# Asymptotic Notations: Complete DSA Walkthrough

> A professional, C++-oriented guide to analyzing algorithm efficiency with Big-O, Big-Theta, Big-Omega, little-o, little-omega, recurrence relations, amortized analysis, and data-structure examples.

**NOTE**: This markdown file created with help of the AI by carefully reviewing.

---

## Table of Contents

1. [Why Asymptotic Analysis Exists](#1-why-asymptotic-analysis-exists)
2. [The Core Idea: Growth Rate](#2-the-core-idea-growth-rate)
3. [Input Size: What Does `n` Mean?](#3-input-size-what-does-n-mean)
4. [Big-O, Big-Omega, and Big-Theta](#4-big-o-big-omega-and-big-theta)
5. [Little-o and Little-omega](#5-little-o-and-little-omega)
6. [Common Complexity Classes](#6-common-complexity-classes)
7. [Rules for Calculating Time Complexity](#7-rules-for-calculating-time-complexity)
8. [Analyzing C++ Code Examples](#8-analyzing-c-code-examples)
9. [Best, Average, and Worst Case](#9-best-average-and-worst-case)
10. [Space Complexity](#10-space-complexity)
11. [Mathematical Tools for Analysis](#11-mathematical-tools-for-analysis)
12. [Recurrence Relations](#12-recurrence-relations)
13. [Master Theorem](#13-master-theorem)
14. [Data Structure Complexity Examples](#14-data-structure-complexity-examples)
15. [Graph Algorithm Complexities](#15-graph-algorithm-complexities)
16. [Sorting Algorithm Complexities](#16-sorting-algorithm-complexities)
17. [Amortized Analysis](#17-amortized-analysis)
18. [Hash Tables and Probabilistic Complexity](#18-hash-tables-and-probabilistic-complexity)
19. [Advanced Examples and Edge Cases](#19-advanced-examples-and-edge-cases)
20. [Common Mistakes](#20-common-mistakes)
21. [Interview and Exam Strategy](#21-interview-and-exam-strategy)
22. [Cheat Sheet](#22-cheat-sheet)

---

## 1. Why Asymptotic Analysis Exists

When we analyze algorithms, we usually do **not** care about the exact runtime in seconds.

Why?

Because exact runtime depends on many machine-specific factors:

- CPU speed
- compiler optimizations
- programming language
- memory hierarchy
- operating system
- hardware cache behavior
- input distribution

Instead, computer scientists ask a more stable question:

> How does the algorithm behave as the input size grows?

This is called **asymptotic analysis**.

It focuses on the growth of running time or memory usage when the input size approaches infinity.

For example:

```cpp
for (int i = 0; i < n; i++) {
    cout << i << '\n';
}
```

This loop runs `n` times. If `n` doubles, the number of operations roughly doubles.

So we say its time complexity is:

```text
O(n)
```

But this does **not** mean the program always takes exactly `n` seconds or exactly `n` CPU instructions.

It means the runtime grows linearly with input size.

---

## 2. The Core Idea: Growth Rate

Asymptotic notation describes the **growth rate** of a function.

In algorithm analysis, the function usually represents running time:

```text
T(n) = number of basic operations for input size n
```

Example:

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cout << i << ' ' << j << '\n';
    }
}
```

The outer loop runs `n` times.
The inner loop runs `n` times for each outer iteration.

Total iterations:

```text
n * n = n²
```

So:

```text
T(n) = O(n²)
```

### Why Ignore Constants?

Suppose two algorithms have these exact operation counts:

```text
Algorithm A: T(n) = 3n + 10
Algorithm B: T(n) = 100n + 500
```

Both are linear.

In asymptotic analysis:

```text
3n + 10 = O(n)
100n + 500 = O(n)
```

The constants matter in real performance engineering, but asymptotic notation focuses on scalability.

### Why Keep the Dominant Term?

For:

```text
T(n) = n² + 100n + 5000
```

When `n` becomes very large, `n²` dominates the other terms.

So:

```text
T(n) = O(n²)
```

---

## 3. Input Size: What Does `n` Mean?

Before analyzing complexity, define the input size.

`n` may mean different things depending on the problem.

| Problem Type    | Possible Meaning of `n`              |
| --------------- | ------------------------------------ |
| Array problem   | Number of elements                   |
| String problem  | Length of the string                 |
| Matrix problem  | Number of rows/columns               |
| Graph problem   | Number of vertices `V` and edges `E` |
| Tree problem    | Number of nodes                      |
| Numeric problem | Number of bits or value magnitude    |

### Important: Numeric Value vs Input Length

Consider:

```cpp
bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
```

If `x` is the numeric value, this is:

```text
O(sqrt(x))
```

But if the input length is the number of bits `b`, then:

```text
x can be as large as 2^b
```

So:

```text
O(sqrt(x)) = O(2^(b/2))
```

That is exponential in the number of input bits.

This distinction matters in theoretical computer science, cryptography, and complexity theory.

---

## 4. Big-O, Big-Omega, and Big-Theta

The three main asymptotic notations are:

```text
Big-O      : upper bound
Big-Omega  : lower bound
Big-Theta  : tight bound
```

---

### 4.1 Big-O: Upper Bound

Big-O describes an asymptotic upper bound.

Informally:

> `f(n) = O(g(n))` means `f(n)` does not grow faster than `g(n)` up to constant factors.

Formal definition:

```text
f(n) = O(g(n)) if there exist constants c > 0 and n0 > 0
such that for all n >= n0:

0 <= f(n) <= c * g(n)
```

Example:

```text
f(n) = 3n + 10
```

We can prove:

```text
3n + 10 = O(n)
```

For `n >= 10`:

```text
3n + 10 <= 3n + n = 4n
```

So choose:

```text
c = 4
n0 = 10
```

Therefore:

```text
3n + 10 = O(n)
```

### Big-O Is Not Necessarily Tight

If:

```text
f(n) = n
```

Then all of these are technically true:

```text
f(n) = O(n)
f(n) = O(n²)
f(n) = O(n³)
f(n) = O(2^n)
```

But the most useful tight upper bound is:

```text
O(n)
```

In practical DSA, when people say Big-O, they usually expect the **smallest simple upper bound**.

---

### 4.2 Big-Omega: Lower Bound

Big-Omega describes an asymptotic lower bound.

Informally:

> `f(n) = Ω(g(n))` means `f(n)` grows at least as fast as `g(n)` up to constant factors.

Formal definition:

```text
f(n) = Ω(g(n)) if there exist constants c > 0 and n0 > 0
such that for all n >= n0:

0 <= c * g(n) <= f(n)
```

Example:

```text
3n + 10 = Ω(n)
```

For all `n >= 1`:

```text
3n + 10 >= 3n
```

Choose:

```text
c = 3
n0 = 1
```

So:

```text
3n + 10 = Ω(n)
```

---

### 4.3 Big-Theta: Tight Bound

Big-Theta describes a tight asymptotic bound.

Informally:

> `f(n) = Θ(g(n))` means `f(n)` grows at the same rate as `g(n)` up to constant factors.

Formal definition:

```text
f(n) = Θ(g(n)) if there exist constants c1 > 0, c2 > 0, and n0 > 0
such that for all n >= n0:

0 <= c1 * g(n) <= f(n) <= c2 * g(n)
```

Equivalent condition:

```text
f(n) = Θ(g(n)) if and only if:

f(n) = O(g(n)) and f(n) = Ω(g(n))
```

Example:

```text
3n + 10 = Θ(n)
```

Because:

```text
3n + 10 = O(n)
3n + 10 = Ω(n)
```

---

## 5. Little-o and Little-omega

Big-O and Big-Omega allow equality of growth rate.

Little-o and little-omega are stricter.

---

### 5.1 Little-o

`f(n) = o(g(n))` means `f(n)` grows strictly slower than `g(n)`.

Formal limit test:

```text
f(n) = o(g(n)) if:

lim(n -> ∞) f(n) / g(n) = 0
```

Examples:

```text
n = o(n²)
log n = o(n)
n² = o(n³)
```

But:

```text
n is not o(n)
```

Because:

```text
lim(n -> ∞) n / n = 1
```

---

### 5.2 Little-omega

`f(n) = ω(g(n))` means `f(n)` grows strictly faster than `g(n)`.

Formal limit test:

```text
f(n) = ω(g(n)) if:

lim(n -> ∞) f(n) / g(n) = ∞
```

Examples:

```text
n² = ω(n)
n = ω(log n)
2^n = ω(n³)
```

But:

```text
n is not ω(n)
```

Because the ratio is `1`, not infinity.

---

## 6. Common Complexity Classes

From fastest to slowest, common classes are:

```text
O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2^n) < O(n!)
```

### O(1): Constant Time

The runtime does not depend on input size.

```cpp
int getFirst(const vector<int>& arr) {
    return arr[0];
}
```

Complexity:

```text
O(1)
```

---

### O(log n): Logarithmic Time

Usually happens when the input size is divided by a constant factor each step.

```cpp
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}
```

Each step halves the search space.

Complexity:

```text
O(log n)
```

The base of the logarithm does not matter in Big-O:

```text
log₂ n = Θ(log₁₀ n) = Θ(ln n)
```

Because logarithms differ only by constant factors.

---

### O(n): Linear Time

Runtime grows proportionally to input size.

```cpp
int sum(const vector<int>& arr) {
    int total = 0;

    for (int x : arr) {
        total += x;
    }

    return total;
}
```

Complexity:

```text
O(n)
```

---

### O(n log n): Linearithmic Time

Common in efficient comparison sorting algorithms.

Examples:

- Merge sort
- Heap sort
- Average-case quicksort

```cpp
sort(arr.begin(), arr.end());
```

For `std::sort`, the standard requires worst-case `O(n log n)` comparisons in modern C++ implementations.

---

### O(n²): Quadratic Time

Usually caused by nested loops over the same input.

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        cout << i << ' ' << j << '\n';
    }
}
```

Complexity:

```text
O(n²)
```

---

### O(2^n): Exponential Time

Often appears in brute-force subset problems or naive recursion.

```cpp
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}
```

This has exponential time complexity:

```text
O(2^n)
```

More tightly:

```text
Θ(φ^n)
```

where `φ ≈ 1.618` is the golden ratio.

---

### O(n!): Factorial Time

Usually appears when generating all permutations.

```cpp
void generatePermutations(vector<int>& arr, int index) {
    if (index == arr.size()) {
        return;
    }

    for (int i = index; i < arr.size(); i++) {
        swap(arr[index], arr[i]);
        generatePermutations(arr, index + 1);
        swap(arr[index], arr[i]);
    }
}
```

Number of permutations:

```text
n!
```

Complexity:

```text
O(n!)
```

---

## 7. Rules for Calculating Time Complexity

### Rule 1: Drop Constant Factors

```text
T(n) = 5n
```

Becomes:

```text
O(n)
```

---

### Rule 2: Drop Lower-Order Terms

```text
T(n) = n² + n + 100
```

Becomes:

```text
O(n²)
```

---

### Rule 3: Sequential Blocks Add

```cpp
for (int i = 0; i < n; i++) {
    cout << i << '\n';
}

for (int j = 0; j < n; j++) {
    cout << j << '\n';
}
```

Total:

```text
O(n) + O(n) = O(2n) = O(n)
```

---

### Rule 4: Nested Loops Multiply

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        cout << i << ' ' << j << '\n';
    }
}
```

Total:

```text
O(n * m)
```

If `m = n`, then:

```text
O(n²)
```

---

### Rule 5: Independent Inputs Should Stay Separate

If an algorithm depends on two independent input sizes `n` and `m`, do not automatically replace both with `n`.

```cpp
void printBoth(const vector<int>& a, const vector<int>& b) {
    for (int x : a) cout << x << '\n';
    for (int y : b) cout << y << '\n';
}
```

Complexity:

```text
O(n + m)
```

Not necessarily:

```text
O(n)
```

because `m` may be much larger than `n`.

---

### Rule 6: Recursive Calls Need Recurrences

```cpp
void solve(int n) {
    if (n <= 1) return;

    solve(n / 2);
    solve(n / 2);
}
```

This is not simply `O(log n)`.

There are two recursive calls at each level.

Recurrence:

```text
T(n) = 2T(n/2) + O(1)
```

Solution:

```text
O(n)
```

---

## 8. Analyzing C++ Code Examples

### Example 1: Single Loop

```cpp
void example(int n) {
    for (int i = 0; i < n; i++) {
        cout << i << '\n';
    }
}
```

Loop iterations:

```text
n
```

Complexity:

```text
O(n)
```

---

### Example 2: Loop with Step 2

```cpp
void example(int n) {
    for (int i = 0; i < n; i += 2) {
        cout << i << '\n';
    }
}
```

Loop iterations:

```text
n / 2
```

Drop constant factor:

```text
O(n)
```

---

### Example 3: Multiplicative Loop

```cpp
void example(int n) {
    for (int i = 1; i < n; i *= 2) {
        cout << i << '\n';
    }
}
```

Values of `i`:

```text
1, 2, 4, 8, 16, ..., n
```

Number of iterations:

```text
log₂ n
```

Complexity:

```text
O(log n)
```

---

### Example 4: Nested Loop with Different Bounds

```cpp
void example(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << i << ' ' << j << '\n';
        }
    }
}
```

Inner loop runs:

```text
0 + 1 + 2 + ... + (n - 1)
```

This sum is:

```text
n(n - 1) / 2
```

So:

```text
O(n²)
```

Even though the inner loop does not always run `n` times, the total is still quadratic.

---

### Example 5: Logarithmic Nested Inside Linear

```cpp
void example(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j *= 2) {
            cout << i << ' ' << j << '\n';
        }
    }
}
```

Outer loop:

```text
n
```

Inner loop:

```text
log n
```

Total:

```text
O(n log n)
```

---

### Example 6: Two Separate Nested Loops

```cpp
void example(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << ' ' << j << '\n';
        }
    }

    for (int k = 0; k < n; k++) {
        cout << k << '\n';
    }
}
```

First block:

```text
O(n²)
```

Second block:

```text
O(n)
```

Total:

```text
O(n² + n) = O(n²)
```

---

### Example 7: Hidden Cost of C++ STL Operations

```cpp
void example(vector<int>& v, int x) {
    v.insert(v.begin(), x);
}
```

Inserting at the beginning of a `vector` requires shifting all existing elements.

Complexity:

```text
O(n)
```

Even though the code looks like one line.

---

### Example 8: Copying Containers

```cpp
void process(vector<int> v) {
    cout << v.size() << '\n';
}
```

The vector is passed by value.

That copies all elements.

Complexity of the function call:

```text
O(n)
```

Better:

```cpp
void process(const vector<int>& v) {
    cout << v.size() << '\n';
}
```

Passing by const reference avoids copying.

Complexity:

```text
O(1)
```

for the parameter passing itself.

---

## 9. Best, Average, and Worst Case

The same algorithm may behave differently depending on input.

---

### Linear Search

```cpp
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}
```

Best case:

```text
Target is at index 0.
O(1)
```

Worst case:

```text
Target is at the end or not present.
O(n)
```

Average case:

```text
Target is expected to be around the middle.
O(n)
```

Even though the average checks about `n / 2` elements, constants are ignored.

---

### Binary Search

Best case:

```text
Target is exactly at the middle.
O(1)
```

Worst case:

```text
Search space is repeatedly halved until empty.
O(log n)
```

Average case:

```text
O(log n)
```

---

## 10. Space Complexity

Space complexity measures memory usage as input grows.

It includes:

1. Input space
2. Auxiliary space

Usually, when people ask for space complexity, they mean **auxiliary space**.

---

### Example: Constant Auxiliary Space

```cpp
int sum(const vector<int>& arr) {
    int total = 0;

    for (int x : arr) {
        total += x;
    }

    return total;
}
```

Extra memory:

```text
total variable only
```

Auxiliary space:

```text
O(1)
```

---

### Example: Linear Auxiliary Space

```cpp
vector<int> copyArray(const vector<int>& arr) {
    vector<int> result;

    for (int x : arr) {
        result.push_back(x);
    }

    return result;
}
```

Extra memory grows with `n`.

Auxiliary space:

```text
O(n)
```

---

### Recursive Space Complexity

```cpp
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

There are `n` recursive stack frames.

Space complexity:

```text
O(n)
```

Even though no explicit array is created.

---

### Tail Recursion Does Not Guarantee O(1) Space in C++

Some languages optimize tail recursion.

C++ does not guarantee tail-call optimization.

So recursive depth should generally be counted unless you know the compiler definitely optimizes it.

---

## 11. Mathematical Tools for Analysis

### 11.1 Arithmetic Series

```text
1 + 2 + 3 + ... + n = n(n + 1) / 2 = Θ(n²)
```

Used in triangular nested loops.

Example:

```cpp
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
        // O(1)
    }
}
```

Total:

```text
1 + 2 + ... + n = Θ(n²)
```

---

### 11.2 Geometric Series

```text
1 + 2 + 4 + 8 + ... + n = 2n - 1 = Θ(n)
```

Used in divide-and-conquer recursion trees.

---

### 11.3 Logarithms

If a loop repeatedly divides by 2:

```cpp
while (n > 1) {
    n /= 2;
}
```

After `k` iterations:

```text
n / 2^k = 1
```

So:

```text
2^k = n
k = log₂ n
```

Complexity:

```text
O(log n)
```

---

### 11.4 Harmonic Series

```text
1 + 1/2 + 1/3 + ... + 1/n = Θ(log n)
```

This appears in some average-case analyses, number theory algorithms, and probabilistic algorithms.

---

## 12. Recurrence Relations

Recursive algorithms are often analyzed using recurrences.

A recurrence expresses runtime in terms of smaller input sizes.

---

### Example 1: Binary Search

```cpp
int binarySearch(vector<int>& arr, int left, int right, int target) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) return mid;
    if (arr[mid] < target) return binarySearch(arr, mid + 1, right, target);
    return binarySearch(arr, left, mid - 1, target);
}
```

Each call works on half the input and does constant work.

Recurrence:

```text
T(n) = T(n/2) + O(1)
```

Solution:

```text
T(n) = O(log n)
```

---

### Example 2: Merge Sort

```cpp
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}
```

Two recursive calls on half the input.
Merging costs linear time.

Recurrence:

```text
T(n) = 2T(n/2) + O(n)
```

Solution:

```text
T(n) = O(n log n)
```

---

### Example 3: Naive Fibonacci

```cpp
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}
```

Recurrence:

```text
T(n) = T(n - 1) + T(n - 2) + O(1)
```

Solution:

```text
T(n) = O(2^n)
```

More tightly:

```text
T(n) = Θ(φ^n)
```

---

### Example 4: Fibonacci with Memoization

```cpp
int fibMemo(int n, vector<int>& memo) {
    if (n <= 1) return n;

    if (memo[n] != -1) return memo[n];

    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
    return memo[n];
}
```

Each state `0..n` is computed once.

Time:

```text
O(n)
```

Space:

```text
O(n)
```

---

## 13. Master Theorem

The Master Theorem is used for recurrences of the form:

```text
T(n) = aT(n/b) + f(n)
```

Where:

- `a` = number of subproblems
- `n/b` = size of each subproblem
- `f(n)` = work done outside recursive calls

Compare `f(n)` with:

```text
n^(log_b a)
```

---

### Case 1

If:

```text
f(n) = O(n^(log_b a - ε))
```

for some `ε > 0`, then:

```text
T(n) = Θ(n^(log_b a))
```

Recursive work dominates.

Example:

```text
T(n) = 8T(n/2) + O(n²)
```

Here:

```text
a = 8, b = 2
n^(log_b a) = n^3
f(n) = n²
```

Since `n²` is smaller than `n³`:

```text
T(n) = Θ(n³)
```

---

### Case 2

If:

```text
f(n) = Θ(n^(log_b a) * log^k n)
```

then:

```text
T(n) = Θ(n^(log_b a) * log^(k+1) n)
```

Example:

```text
T(n) = 2T(n/2) + O(n)
```

Here:

```text
a = 2, b = 2
n^(log_b a) = n
f(n) = n
```

So:

```text
T(n) = Θ(n log n)
```

This is merge sort.

---

### Case 3

If:

```text
f(n) = Ω(n^(log_b a + ε))
```

and the regularity condition holds:

```text
a f(n/b) <= c f(n)
```

for some `c < 1`, then:

```text
T(n) = Θ(f(n))
```

Non-recursive work dominates.

Example:

```text
T(n) = 2T(n/2) + O(n²)
```

Here:

```text
a = 2, b = 2
n^(log_b a) = n
f(n) = n²
```

Since `n²` dominates:

```text
T(n) = Θ(n²)
```

---

## 14. Data Structure Complexity Examples

## 14.1 Array / Vector

### Access by Index

```cpp
int x = arr[i];
```

Complexity:

```text
O(1)
```

Arrays and vectors store elements contiguously, so address calculation is constant time.

---

### Search in Unsorted Vector

```cpp
bool contains(const vector<int>& arr, int target) {
    for (int x : arr) {
        if (x == target) return true;
    }
    return false;
}
```

Worst-case:

```text
O(n)
```

---

### Insert at End

```cpp
v.push_back(x);
```

Amortized:

```text
O(1)
```

Worst-case:

```text
O(n)
```

Why?

If capacity is full, vector allocates a larger array and copies/moves all elements.

---

### Insert at Beginning

```cpp
v.insert(v.begin(), x);
```

Complexity:

```text
O(n)
```

All elements must shift right.

---

## 14.2 Linked List

### Access by Index

```text
O(n)
```

A linked list does not support direct indexing.

To access the `i`-th element, you must traverse from the head.

---

### Insert at Head

```text
O(1)
```

Only pointer updates are needed.

---

### Search

```text
O(n)
```

You may need to scan the whole list.

---

### Insert After Known Node

```text
O(1)
```

If you already have a pointer/reference to the node.

But finding that node may cost:

```text
O(n)
```

---

## 14.3 Stack

Common operations:

| Operation | Complexity |
| --------- | ---------: |
| `push`    |       O(1) |
| `pop`     |       O(1) |
| `top`     |       O(1) |
| `empty`   |       O(1) |

Stacks are often implemented with dynamic arrays or linked lists.

---

## 14.4 Queue

Common operations:

| Operation        | Complexity |
| ---------------- | ---------: |
| `push` / enqueue |       O(1) |
| `pop` / dequeue  |       O(1) |
| `front`          |       O(1) |
| `empty`          |       O(1) |

A queue should not be implemented by repeatedly erasing from the beginning of a vector, because that would make dequeue `O(n)`.

---

## 14.5 Deque

C++ `std::deque` supports efficient insertion/removal from both ends.

| Operation        | Complexity |
| ---------------- | ---------: |
| Access by index  |       O(1) |
| Push front       |       O(1) |
| Push back        |       O(1) |
| Pop front        |       O(1) |
| Pop back         |       O(1) |
| Insert in middle |       O(n) |

---

## 14.6 Binary Search Tree

For a balanced BST:

| Operation | Complexity |
| --------- | ---------: |
| Search    |   O(log n) |
| Insert    |   O(log n) |
| Delete    |   O(log n) |

For a skewed BST:

| Operation | Complexity |
| --------- | ---------: |
| Search    |       O(n) |
| Insert    |       O(n) |
| Delete    |       O(n) |

A plain BST can degrade into a linked list.

---

## 14.7 AVL Tree / Red-Black Tree

Self-balancing trees keep height logarithmic.

C++ `std::map` and `std::set` are commonly implemented as balanced binary search trees.

| Operation         | Complexity |
| ----------------- | ---------: |
| Search            |   O(log n) |
| Insert            |   O(log n) |
| Delete            |   O(log n) |
| Ordered traversal |       O(n) |

---

## 14.8 Heap / Priority Queue

C++ `std::priority_queue` is usually implemented as a binary heap.

| Operation       | Complexity |
| --------------- | ---------: |
| Get max/min     |       O(1) |
| Insert          |   O(log n) |
| Extract max/min |   O(log n) |
| Build heap      |       O(n) |

Important:

Building a heap from `n` elements is `O(n)`, not `O(n log n)`, when using the bottom-up heapify method.

---

## 14.9 Hash Table

C++ `std::unordered_map` and `std::unordered_set` are hash-table based.

Average case:

| Operation | Complexity |
| --------- | ---------: |
| Search    |       O(1) |
| Insert    |       O(1) |
| Delete    |       O(1) |

Worst case:

```text
O(n)
```

Worst case occurs when many keys collide into the same bucket.

---

## 15. Graph Algorithm Complexities

Graphs usually use two variables:

```text
V = number of vertices
E = number of edges
```

Do not simplify everything to `n` unless the problem defines `n` clearly.

---

## 15.1 Adjacency Matrix

Space:

```text
O(V²)
```

Check if edge `(u, v)` exists:

```text
O(1)
```

Iterate over all neighbors of a vertex:

```text
O(V)
```

Good for dense graphs.

---

## 15.2 Adjacency List

Space:

```text
O(V + E)
```

Check if edge `(u, v)` exists:

```text
O(degree(u))
```

Iterate over all neighbors:

```text
O(degree(u))
```

Good for sparse graphs.

---

## 15.3 BFS

```cpp
void bfs(int start, vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
```

Using adjacency list:

```text
O(V + E)
```

Each vertex is visited once.
Each edge is considered at most twice in an undirected graph.

---

## 15.4 DFS

```cpp
void dfs(int u, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[u] = true;

    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v, graph, visited);
        }
    }
}
```

Using adjacency list:

```text
O(V + E)
```

Recursive space:

```text
O(V)
```

in the worst case due to call stack.

---

## 15.5 Dijkstra's Algorithm

With adjacency list and binary heap:

```text
O((V + E) log V)
```

Commonly written as:

```text
O(E log V)
```

for connected graphs where `E >= V - 1`.

With adjacency matrix:

```text
O(V²)
```

---

## 16. Sorting Algorithm Complexities

| Algorithm      |                   Best |     Average |       Worst |            Space | Stable?                      |
| -------------- | ---------------------: | ----------: | ----------: | ---------------: | ---------------------------- |
| Bubble Sort    | O(n) with optimization |       O(n²) |       O(n²) |             O(1) | Yes                          |
| Selection Sort |                  O(n²) |       O(n²) |       O(n²) |             O(1) | Usually No                   |
| Insertion Sort |                   O(n) |       O(n²) |       O(n²) |             O(1) | Yes                          |
| Merge Sort     |             O(n log n) |  O(n log n) |  O(n log n) |             O(n) | Yes                          |
| Quick Sort     |             O(n log n) |  O(n log n) |       O(n²) | O(log n) average | Usually No                   |
| Heap Sort      |             O(n log n) |  O(n log n) |  O(n log n) |             O(1) | No                           |
| Counting Sort  |               O(n + k) |    O(n + k) |    O(n + k) |             O(k) | Yes if implemented carefully |
| Radix Sort     |            O(d(n + k)) | O(d(n + k)) | O(d(n + k)) |         O(n + k) | Yes if stable sub-sort used  |

Where:

```text
k = range of values
 d = number of digits/passes
```

---

## 17. Amortized Analysis

Amortized analysis studies the average cost per operation over a sequence of operations.

This is different from average-case analysis.

Average-case analysis depends on probability distribution of inputs.
Amortized analysis gives a deterministic guarantee over a sequence.

---

## 17.1 Vector push_back

`vector::push_back` is usually `O(1)` amortized.

But sometimes it is `O(n)` when reallocation happens.

Example:

```cpp
vector<int> v;

for (int i = 0; i < n; i++) {
    v.push_back(i);
}
```

Although some individual insertions are expensive, the total cost of `n` insertions is:

```text
O(n)
```

Therefore each insertion is amortized:

```text
O(1)
```

### Why?

If capacity doubles each time:

```text
1 + 2 + 4 + 8 + ... + n = O(n)
```

Total copying cost across all reallocations is linear.

---

## 17.2 Stack with Occasional Expensive Operation

Suppose we have a stack where `push` is normal, but sometimes we copy the entire stack.

If copying happens rarely enough, the amortized cost may still be low.

Amortized analysis is often used for:

- dynamic arrays
- hash table resizing
- disjoint set union
- splay trees
- certain queue implementations

---

## 17.3 Disjoint Set Union / Union-Find

With path compression and union by rank/size:

```text
Almost O(1) amortized
```

More formally:

```text
O(α(n))
```

where `α(n)` is the inverse Ackermann function.

For all practical input sizes, `α(n)` is less than 5.

---

## 18. Hash Tables and Probabilistic Complexity

Hash tables are interesting because their complexity depends on collisions and hashing assumptions.

### Average Case

If keys are distributed well across buckets:

```text
insert: O(1)
search: O(1)
delete: O(1)
```

### Worst Case

If all keys collide:

```text
insert: O(n)
search: O(n)
delete: O(n)
```

### Load Factor

Load factor:

```text
α = number of elements / number of buckets
```

When load factor becomes too high, the table rehashes.

Rehashing costs:

```text
O(n)
```

But because it happens occasionally, insertion remains amortized `O(1)` on average under good hashing assumptions.

---

## 19. Advanced Examples and Edge Cases

## 19.1 Nested Loop Where Inner Variable Depends on Outer

```cpp
void example(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j += i) {
            cout << i << ' ' << j << '\n';
        }
    }
}
```

For each `i`, inner loop runs approximately:

```text
n / i
```

Total:

```text
n/1 + n/2 + n/3 + ... + n/n
```

Factor out `n`:

```text
n(1 + 1/2 + 1/3 + ... + 1/n)
```

Harmonic series:

```text
Θ(log n)
```

Total complexity:

```text
O(n log n)
```

---

## 19.2 Loop with Square Growth

```cpp
void example(int n) {
    for (int i = 1; i * i <= n; i++) {
        cout << i << '\n';
    }
}
```

Condition:

```text
i² <= n
```

So:

```text
i <= sqrt(n)
```

Complexity:

```text
O(sqrt(n))
```

---

## 19.3 Two-Pointer Technique

```cpp
bool hasPairWithSum(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) return true;
        if (sum < target) left++;
        else right--;
    }

    return false;
}
```

Each pointer moves at most `n` times total.

Complexity:

```text
O(n)
```

Not `O(n²)`, even though two indices are involved.

---

## 19.4 Sliding Window

```cpp
int maxSubarraySumK(const vector<int>& arr, int k) {
    int windowSum = 0;

    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    int best = windowSum;

    for (int right = k; right < arr.size(); right++) {
        windowSum += arr[right];
        windowSum -= arr[right - k];
        best = max(best, windowSum);
    }

    return best;
}
```

Each element is added and removed at most once.

Complexity:

```text
O(n)
```

---

## 19.5 Backtracking

```cpp
void subsets(vector<int>& arr, int index, vector<int>& current) {
    if (index == arr.size()) {
        return;
    }

    current.push_back(arr[index]);
    subsets(arr, index + 1, current);

    current.pop_back();
    subsets(arr, index + 1, current);
}
```

At each element, there are two choices:

1. Include it
2. Exclude it

Number of subsets:

```text
2^n
```

Complexity:

```text
O(2^n)
```

If copying/printing each subset takes `O(n)`, then total may become:

```text
O(n * 2^n)
```

---

## 19.6 Dynamic Programming

Dynamic programming often turns exponential recursion into polynomial time by avoiding repeated work.

Example: 0/1 Knapsack

```text
State: dp[i][w]
```

Where:

- `i` = number of items considered
- `w` = current capacity

Number of states:

```text
n * W
```

Transition per state:

```text
O(1)
```

Total time:

```text
O(nW)
```

Space:

```text
O(nW)
```

With optimization:

```text
O(W)
```

Important:

`O(nW)` is pseudo-polynomial, because `W` is a numeric value, not necessarily the input length in bits.

---

## 20. Common Mistakes

### Mistake 1: Thinking Every Nested Loop Is O(n²)

Example:

```cpp
for (int i = 1; i < n; i *= 2) {
    for (int j = 0; j < n; j++) {
        // O(1)
    }
}
```

Outer loop:

```text
O(log n)
```

Inner loop:

```text
O(n)
```

Total:

```text
O(n log n)
```

---

### Mistake 2: Ignoring Hidden STL Costs

```cpp
vector<int> v;
v.insert(v.begin(), 10);
```

This is not `O(1)`.

It is:

```text
O(n)
```

---

### Mistake 3: Confusing O(log n) With O(n log n)

Binary search alone is:

```text
O(log n)
```

Sorting then binary searching once is:

```text
O(n log n + log n) = O(n log n)
```

Sorting dominates.

---

### Mistake 4: Ignoring Recursion Stack Space

```cpp
void dfs(int u) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) dfs(v);
    }
}
```

Time:

```text
O(V + E)
```

Space:

```text
O(V)
```

because of recursion stack in worst case.

---

### Mistake 5: Calling Hash Map Always O(1)

Hash maps are average-case `O(1)`, not guaranteed worst-case `O(1)`.

Worst case:

```text
O(n)
```

---

## 21. Interview and Exam Strategy

When asked to analyze complexity, use this process:

### Step 1: Define Input Size

Example:

```text
Let n be the number of elements in the array.
```

For graphs:

```text
Let V be the number of vertices and E be the number of edges.
```

---

### Step 2: Identify Dominant Operations

Ask:

- What loops exist?
- Are loops nested or sequential?
- Does recursion branch?
- Are there hidden expensive operations?
- Does the algorithm sort first?
- Is a data structure operation average-case or worst-case?

---

### Step 3: Write the Raw Count

Example:

```text
n + n² + log n
```

---

### Step 4: Drop Constants and Lower Terms

```text
n² dominates n and log n
```

Final:

```text
O(n²)
```

---

### Step 5: Mention Space Separately

Example:

```text
Time complexity: O(n log n)
Space complexity: O(n)
```

Do not mix time and space unless explicitly asked.

---

## 22. Cheat Sheet

### Common Patterns

| Code Pattern                | Complexity |
| --------------------------- | ---------: |
| Single loop over `n`        |       O(n) |
| Loop increments by constant |       O(n) |
| Loop doubles variable       |   O(log n) |
| Loop halves input           |   O(log n) |
| Two nested full loops       |      O(n²) |
| Triangular nested loop      |      O(n²) |
| Outer `n`, inner `log n`    | O(n log n) |
| Binary search               |   O(log n) |
| Merge sort                  | O(n log n) |
| DFS/BFS adjacency list      |   O(V + E) |
| Generate all subsets        |     O(2^n) |
| Generate all permutations   |      O(n!) |

---

### C++ STL Complexity Quick Reference

| Structure / Operation          |     Complexity |
| ------------------------------ | -------------: |
| `vector[i]`                    |           O(1) |
| `vector.push_back`             | O(1) amortized |
| `vector.insert(begin)`         |           O(n) |
| `vector.erase(begin)`          |           O(n) |
| `list.push_front`              |           O(1) |
| `list.insert` with iterator    |           O(1) |
| `map/search/insert/delete`     |       O(log n) |
| `set/search/insert/delete`     |       O(log n) |
| `unordered_map` average search |           O(1) |
| `unordered_map` worst search   |           O(n) |
| `priority_queue.top`           |           O(1) |
| `priority_queue.push`          |       O(log n) |
| `priority_queue.pop`           |       O(log n) |
| `sort`                         |     O(n log n) |
| `find` on vector               |           O(n) |
| `lower_bound` on sorted vector |       O(log n) |

---

## Final Notes

Asymptotic notation is not only about memorizing Big-O values.

It is a language for reasoning about scalability.

A strong DSA analysis should answer:

1. What is the input size?
2. What operations dominate runtime?
3. Are there hidden data-structure costs?
4. Is the bound best, average, worst, amortized, or expected?
5. What is the space complexity?
6. Is the bound tight?

Professional analysis is not just saying:

```text
This is O(n²)
```

A professional explanation says:

```text
The outer loop runs n times. For each outer iteration, the inner loop runs up to n times. Therefore the total number of constant-time operations is n * n = n². Lower-order terms and constants are ignored, so the time complexity is O(n²). Since every iteration always happens regardless of input values, the tight bound is Θ(n²). The algorithm uses only a few scalar variables, so auxiliary space is O(1).
```

That is the level of explanation expected in serious DSA work.
