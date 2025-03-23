#include <iostream>

// Implementing Queue using Array with circular approach (two pointers)

class Queue
{
private:
    int *arr;
    int rear;
    int front;
    int size;
    int capacity;

public:
    Queue(int capacity)
    {
        this->arr = new int[capacity];
        this->capacity = capacity;
        this->size = 0;
        this->front = 0;
        this->rear = -1;
    }

    ~Queue() { delete[] arr; }

    void enqueue(int value) // Time: O(1)
    {
        if (isFull())
        {
            std::cout << "Queue is full" << std::endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    int dequeue() // Time: O(1)
    {
        if (empty())
        {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }

        int value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    int Front() // Time: O(1)
    {
        if (empty())
        {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        return arr[front];
    }

    bool empty() { return size == 0; } // Time: O(1)

    bool isFull() { return size == capacity; } // Time: O(1)

    int getSize() { return size; } // Time: O(1)

    void display() // Time: O(n)
    {
        if (empty())
        {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        std::cout << "- ";
        for (int i = 0; i < size; i++)
        {
            int index = (front + i) % capacity;
            std::cout << arr[index] << " - ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    Queue Q(5); // capacity: 5

    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(40);
    Q.enqueue(50);

    Q.display(); // - 10 - 20 - 30 - 40 - 50 -

    std::cout << "Front: " << Q.Front() << std::endl; // Front: 10

    Q.dequeue();
    Q.dequeue();

    Q.display();                                      // - 30 - 40 - 50 -
    std::cout << "Front: " << Q.Front() << std::endl; // Front: 30

    Q.enqueue(60);
    Q.enqueue(70);

    Q.display(); // - 30 - 40 - 50 - 60 - 70 -

    return 0;
}