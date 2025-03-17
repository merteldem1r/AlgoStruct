#include <iostream>

// Implementing Queue using Linked List

struct Node
{
    int val;
    Node *next;

    Node(int value) : val(value), next(nullptr) {};
};

class Queue
{
private:
    Node *front;
    Node *rear;
    int length;

public:
    Queue(int value)
    {
        const auto newNode = new Node(value);
        front = newNode;
        rear = newNode;
        length = 1;
    }

    ~Queue()
    {
        auto temp = front;

        while (temp != nullptr)
        {
            auto next = temp->next;
            delete temp;
            temp = next;
        }
    }

    void enqueue(const int value) // Time: O(1)
    {
        Node *newNode = new Node(value);

        if (front == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        ++length;
    }

    int dequeue() // Time: O(1)
    {
        if (front == nullptr)
        {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }

        int val = front->val;

        if (front == rear)
        {
            delete rear;
            front = rear = nullptr;
            --length;
            return val;
        }

        Node *frontNext = front->next;
        delete front;
        front = frontNext;
        --length;

        return val;
    }

    void traverse() // Time: O(n)
    {
        auto temp = front;

        while (temp != nullptr)
        {
            std::cout << temp->val << " -> ";
            temp = temp->next;
        }

        std::cout << "nullptr" << std::endl;
    }

    bool empty() { return length == 0; } // Time: O(1)

    int size() { return length; } // Time: O(1)
};

int main()
{
    Queue Q(1);

    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);

    Q.traverse(); // 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    Q.size();     // 5

    Q.dequeue();
    Q.dequeue();

    Q.traverse(); // 3 -> 4 -> 5 -> nullptr
    Q.size();     // 3

    std::cout << std::boolalpha;
    std::cout << Q.empty() << std::endl; // false
    std::cout << std::noboolalpha;

    return 0;
}