#include <iostream>

// On that example we use manual memora managment on Heap while implementing Stack

class Stack
{
private:
    int *arr;
    int capacity;
    int topIndex;

    // to double the capacity
    void resize()
    {
        int newCapacity = capacity * 2;
        int *newArr = new int[capacity * 2];

        for (int i = 0; i < capacity; ++i)
            newArr[i] = arr[i];

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
        std::cout << "Stack capacity doubled to: " << capacity << std::endl;
    }

public:
    // Constructor
    Stack(int size = 10)
    {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    // Destructor
    ~Stack()
    {
        delete[] arr;
    }

    void push(int x)
    {
        if (topIndex == capacity - 1)
            resize();

        arr[++topIndex] = x;
    }

    void pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack Underflow\n";
            return;
        }
        --topIndex;
    }

    int top()
    {
        if (isEmpty())
        {
            std::cout << "Stack is Empty\n";
            return -1;
        }
        return arr[topIndex];
    }

    // Check if stack is empty
    bool isEmpty()
    {
        return topIndex == -1;
    }

    int size() { return topIndex + 1; }
};

int main()
{
    Stack s(2);

    s.push(10);
    s.push(20);
    s.push(30); // here it will trigger resize
    s.push(40);
    s.push(50);

    std::cout << "Top element: " << s.top() << std::endl;
    s.pop();   
    std::cout << "Top element after pop: " << s.top() << std::endl;
    std::cout << "Stack size: " << s.size() << std::endl;

    return 0;
}
