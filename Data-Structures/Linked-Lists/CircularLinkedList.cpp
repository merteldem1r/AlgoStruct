#include <iostream>

// Circular Linked List Data Structure using C++ Class

struct Node
{
    int val;
    Node *next;

    Node(int data) : val(data), next(nullptr) {};
};

class CircularLinkedList
{
public:
    Node *head;
    Node *tail;
    int length;

    CircularLinkedList() : head(nullptr), tail(nullptr), length(0) {};
    CircularLinkedList(Node *newNode) : head(newNode), tail(newNode), length(1)
    {
        newNode->next = newNode; // Pointing to itself
    };

    ~CircularLinkedList()
    {
        if (length == 0)
            return;

        Node *temp = head;
        do
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        } while (temp != head);
    }

    int append(int data)
    {
        Node *newNode = new Node(data);
        ++length;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            newNode->next = head;
        }
        else
        {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }

        return data;
    }

    void traverse()
    {
        if (length == 0)
        {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node *temp = head;
        do
        {
            std::cout << temp->val << " -> ";
            temp = temp->next;
        } while (temp != head);

        std::cout << "HEAD" << std::endl;
    }

    bool isEmpty() { return length == 0; }

    int getLength() { return length; }
};

int main()
{
    CircularLinkedList List;

    List.append(1);
    List.append(2);
    List.append(3);
    List.append(4);

    List.traverse(); // 1 -> 2 -> 3 -> 4 -> HEAD

    return 0;
}
