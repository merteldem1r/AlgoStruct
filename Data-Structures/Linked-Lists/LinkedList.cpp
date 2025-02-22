#include <iostream>

// Single Linked List Data Structure using C++ Class

struct Node
{
    int val;
    Node *next;

    Node(int data) : val(data), next(nullptr) {};
};

class SingleLinkedList
{
public:
    Node *head;
    Node *tail;
    int length;

    SingleLinkedList() : head(nullptr), tail(nullptr), length(0) {};
    SingleLinkedList(Node *newNode) : head(newNode), tail(newNode), length(1) {};

    ~SingleLinkedList()
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
        Node *prev = nullptr;

        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
            ++length;
            return newNode->val;
        }

        for (int i = 0; i != index; ++i)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = newNode;
        newNode->next = temp;

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
        Node *prev = nullptr;

        while (temp != nullptr && temp->val != data)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            std::cout << "Not found" << std::endl;
        }

        const int value = temp->val;

        if (temp == head)
        {
            head = temp->next;
        }
        else
        {
            prev->next = temp->next;

            if (temp == tail)
                tail = prev;
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

    bool isEmpty() { return length == 0; }

    int getLength() { return length; }
};

SingleLinkedList *createLinkedList(std::vector<int> arr)
{
    if (arr.size() == 0)
        return nullptr;

    SingleLinkedList *List = new SingleLinkedList();

    for (int i = 0; i < arr.size(); ++i)
        List->append(arr[i]);

    return List;
}

int main()
{
    std::vector<int> exampleArr = {1, 5, 3, 2, 7, 12};
    auto List = createLinkedList(exampleArr);

    List->traverse(); // 1 -> 5 -> 3 -> 2 -> 7 -> 12 -> NULL
    List->insert(10, 1);
    List->traverse(); // 1 -> 10 -> 5 -> 3 -> 2 -> 7 -> 12 -> NULL

    List->remove(3);
    List->traverse(); // // 1 -> 10 -> 5 -> 2 -> 7 -> 12 -> NULL

    delete List;

    return 0;
}