#include <iostream>

struct Node
{
    int val;
    Node *next;
    Node *prev;

    Node(int value) : val(value), next(nullptr), prev(nullptr) {}
};

class Deque
{
private:
    Node *front;
    Node *rear;
    int size;
    int length;

public:
    Deque(int frontValue, int size)
    {
        Node *newNode = new Node(frontValue);
        this->front = newNode;
        this->rear = newNode;
        this->size = size;
        this->length = 1;
    }

    ~Deque()
    {
        while (front != nullptr)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isFull() { return length == size; }
    bool empty() { return length == 0; }
    int getLength() { return length; }

    void pushFront(int value)
    {
        if (isFull())
        {
            std::cout << "Deque is full already" << std::endl;
            return;
        }

        Node *newNode = new Node(value);
        if (empty())
        {
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        ++length;
    }

    void pushRear(int value)
    {
        if (isFull())
        {
            std::cout << "Deque is full" << std::endl;
            return;
        }
        Node *newNode = new Node(value);
        if (empty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        ++length;
    }

    int popFront()
    {
        if (empty())
        {
            std::cout << "Deque is empty." << std::endl;
            return -1;
        }

        const int val = front->val;
        Node *temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;
        else
            front->prev = nullptr;

        delete temp;
        --length;

        return val;
    }

    int popRear()
    {
        if (empty())
        {
            std::cout << "Deque is empty." << std::endl;
            return -1;
        }

        const int val = rear->val;
        Node *temp = rear;
        rear = rear->prev;

        if (rear == nullptr)
            front = nullptr;
        else
            rear->next = nullptr;

        delete temp;
        --length;
        return val;
    }

    int Front() { return empty() ? -1 : front->val; }

    int Rear() { return empty() ? -1 : rear->val; }

    void traverse()
    {
        Node *temp = front;
        while (temp != nullptr)
        {
            std::cout << temp->val << " <-> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main()
{
    Deque Dq(1, 10);

    Dq.pushRear(2);
    Dq.pushRear(3);
    Dq.pushFront(0);
    Dq.pushFront(-1);

    Dq.traverse();                                     // -1 <-> 0 <-> 1 <-> 2 <-> 3 <-> nullptr
    std::cout << "Front: " << Dq.Front() << std::endl; // 1
    std::cout << "Rear: " << Dq.Rear() << std::endl;   //  3

    Dq.popFront();
    Dq.popRear();

    Dq.traverse(); // 0 <-> 1 <-> 2 <-> nullptr

    return 0;
}