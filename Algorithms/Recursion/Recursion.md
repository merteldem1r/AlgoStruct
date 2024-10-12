# Recursion

Assume that you have to paint a few balls. If you do it alone, it will take a lot of time. One thing you can do is to take help from your friend. Assuming that you have the same work speed, the task will be done in half of the time. Now, instead of taking help from only one of your friends, you take help from multiple friends such that each friend have only one ball to paint. The task will be done much faster as compared to when you were doing it alone. Recursion is a problem-solving technique that works in a similar way.

Recursion in C++ is a technique in which a function calls itself repeatedly until a given condition is satisfied. In other words, recursion is the process of solving a problem by breaking it down into smaller, simpler sub-problems.

**Syntax Structure of Recursion:**

return_type recursive_func {
....
// Base Condition
// Recursive Case
....
}

**What is Stack Overflow?**

Stack overflow is one of the most common errors associated with the recursion which occurs when a function calls itself too many times. As we know that each recursive call requires separate space in the limited stack memory. When there is a large number of recursive calls or recursion goes on infinite times, this stack memory may get exhausted and may not be able to store more data leading to programs’ termination.
