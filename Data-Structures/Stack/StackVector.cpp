#include <iostream>
#include <vector>

// This example using vector on Stack implementation

class Stack
{
private:
    std::vector<int> arr;

public:
    // Push element to stack
    void push(int x) { arr.emplace_back(x); }

    // Pop element from stack
    void pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack Underflow\n";
            return;
        }
        arr.pop_back();
    }

    int top()
    {
        if (isEmpty())
        {
            std::cout << "Stack is Empty\n";
            return -1;
        }
        return arr.back();
    }

    bool isEmpty() { return arr.empty(); }

    // Get the size of the stack
    int size() { return arr.size(); }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << "Top element: " << s.top() << std::endl;
    s.pop();
    std::cout << "Top element after pop: " << s.top() << std::endl;
    std::cout << "Stack size: " << s.size() << std::endl;
    s.pop();
    s.pop();
    s.pop();

    return 0;
}
