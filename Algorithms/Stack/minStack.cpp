#include <iostream>

// LeetCode: 155 Min Stack
// https://leetcode.com/problems/min-stack/description/

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.


Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2

*/

class MinStack // Time: O(1) for all operations Space: O(n)
{
private:
    int min = INT_MIN;
    std::vector<std::pair<int, int>> s;

public:
    MinStack() {}

    void push(int val)
    {
        if (s.size() == 0)
        {
            s.emplace_back(std::make_pair(val, val));
        }
        else
        {
            auto untilMax = top();
            s.emplace_back(std::make_pair(val, std::min(s.back().second, val)));
        }
    }

    void pop()
    {
        s.pop_back();
    }

    int top()
    {
        return s.back().first;
    }

    int getMin()
    {
        return s.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    return 0;
}