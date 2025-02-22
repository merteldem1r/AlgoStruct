#include <iostream>

// Double Linked List Data Structure using C++ Class

struct Node
{
    int val;
    Node *next;
    Node *prev;

    Node(int data) : val(data), next(nullptr), prev(nullptr) {};
};

class DoubleLinkedList
{
public:
    Node *head;
    Node *tail;
    int length;

    DoubleLinkedList() : head(nullptr), tail(nullptr), length(0) {};
    DoubleLinkedList(Node *newNode) : head(newNode), tail(newNode), length(1) {};

    ~DoubleLinkedList()
    {
        auto temp = head;
        while (temp != nullptr)
        {
            auto next = temp->next;
            delete temp;
            temp = next;
        }
    }

    int append(int data)
    {
        Node *newNode = new Node(data);
        ++length;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        return data;
    }

    int insert(int data, int index)
    {
        if (index < 0)
        {
            std::cout << "Wrong index number" << std::endl;
            return -1;
        }
        else if (index >= length || length == 0)
        {
            append(data);
            return data;
        }

        Node *newNode = new Node(data);
        auto temp = head;

        if (index == 0)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            ++length;
            return newNode->val;
        }

        for (int i = 0; i != index; ++i)
        {
            temp = temp->next;
        }

        newNode->prev = temp->prev;
        newNode->next = temp;
        temp->prev->next = newNode;
        temp->prev = newNode;

        ++length;
        return newNode->val;
    }

    int remove(int data)
    {
        if (length == 0)
        {
            std::cout << "List already empty" << std::endl;
            return -1;
        }

        auto temp = head;

        while (temp != nullptr && temp->val != data)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            std::cout << "Not found" << std::endl;
            return -1;
        }

        const int value = temp->val;

        if (temp == head)
        {
            head = temp->next;
            if (head != nullptr)
                head->prev = nullptr;
        }
        else if (temp == tail)
        {
            tail = temp->prev;
            tail->next = nullptr;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        --length;
        delete temp;

        return value;
    }

    void traverse()
    {
        auto temp = head;

        while (temp != nullptr)
        {
            std::cout << temp->val << " -> ";
            temp = temp->next;
        }

        std::cout << "NULL" << std::endl;
    }

    void traverseReverse()
    {
        auto temp = tail;

        while (temp != nullptr)
        {
            std::cout << temp->val << " -> ";
            temp = temp->prev;
        }

        std::cout << "NULL" << std::endl;
    }

    bool isEmpty() { return length == 0; }

    int getLength() { return length; }
};

// Utility function to create DoubleLinkedList from an array
DoubleLinkedList *createLinkedList(std::vector<int> arr)
{
    if (arr.size() == 0)
        return nullptr;

    DoubleLinkedList *List = new DoubleLinkedList();

    for (int i = 0; i < arr.size(); ++i)
        List->append(arr[i]);

    return List;
}

int main()
{
    std::vector<int> exampleArr = {1, 5, 3, 2, 7, 12};
    auto List = createLinkedList(exampleArr);

    List->traverse();        // 1 -> 5 -> 3 -> 2 -> 7 -> 12 -> NULL
    List->traverseReverse(); // 12 -> 7 -> 2 -> 3 -> 5 -> 1 -> NULL

    List->insert(10, 1);
    List->traverse(); // 1 -> 10 -> 5 -> 3 -> 2 -> 7 -> 12 -> NULL

    List->remove(3);
    List->traverse(); // 1 -> 10 -> 5 -> 2 -> 7 -> 12 -> NULL

    List->traverseReverse(); // 12 -> 7 -> 2 -> 5 -> 10 -> 1 -> NULL

    delete List;

    return 0;
}
