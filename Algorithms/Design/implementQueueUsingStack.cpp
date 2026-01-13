#include <iostream>

// This question is from LeetCode: https://leetcode.com/problems/implement-queue-using-stacks/description/

/*

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:
    void push(int x) Pushes element x to the back of the queue.
    int pop() Removes the element from the front of the queue and returns it.
    int peek() Returns the element at the front of the queue.
    boolean empty() Returns true if the queue is empty, false otherwise.

Notes:
    You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
*/

class MyQueue
{
    std::stack<int> s1;
    std::stack<int> s2;

public:
    MyQueue() {}

    void push(int x) // Time: O(n)
    {
        s1.push(x);
    }

    int pop() // Time: O(n)
    {
        int temp;
        while (!s1.empty())
        {
            temp = s1.top();
            s2.push(temp);
            s1.pop();
        }
        s2.pop();
        int last = temp;
        while (!s2.empty())
        {
            temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        return last;
    }

    int peek() // Time: O(n)
    {
        int temp;

        while (!s1.empty())
        {
            temp = s1.top();
            s2.push(temp);
            s1.pop();
        }

        int peekTemp = temp;

        while (!s2.empty())
        {
            temp = s2.top();
            s1.push(temp);
            s2.pop();
        }

        return peekTemp;
    }

    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    MyQueue Q = MyQueue();

    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);

    std::cout << Q.peek() << std::endl; // 1

    Q.pop();
    Q.pop();
    Q.pop();

    std::cout << Q.peek() << std::endl; // 4

    return 0;
}