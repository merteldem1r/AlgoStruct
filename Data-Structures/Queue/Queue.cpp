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
    int size;
    int length;

public:
    Queue(int frontValue, int size)
    {
        const auto newNode = new Node(frontValue);
        this->front = newNode;
        this->rear = newNode;
        this->size = size;
        this->length = 1;
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

        if (isFull())
        {
            std::cout << "Queue is already full" << std::endl;
            return;
        }

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
        if (empty())
        {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }

        int val = front->val;
        Node *frontNext = front->next;

        delete front;
        front = frontNext;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        --length;

        return val;
    }

    int Front()
    {
        if (!empty())
        {
            return front->val;
        }
        else
        {
            return -1;
            std::cout << "Queue is empty" << std::endl;
        }
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

    int getLength() { return length; } // Time: O(1)

    bool isFull()
    {
        return length == size;
    }
};

int main()
{
    Queue Q(1, 10); // Front Element: 1 Size: 10

    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);

    Q.traverse();  // 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    Q.getLength(); // 5

    Q.dequeue();
    Q.dequeue();

    Q.traverse();                            // 3 -> 4 -> 5 -> nullptr
    std::cout << Q.Front() << std::endl;     // 3
    std::cout << Q.getLength() << std::endl; // 3

    std::cout << std::boolalpha;
    std::cout << Q.empty() << std::endl;  // false
    std::cout << Q.isFull() << std::endl; // false
    std::cout << std::noboolalpha;

    return 0;
}