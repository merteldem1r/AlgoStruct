#include <iostream>

struct Node
{
    int val;
    Node *next;

    Node(int data) : val(data), next(nullptr) {};
};

Node *createLinkedList(std::vector<int> arr)
{
    Node *head = new Node(arr[0]);
    auto temp = head;

    for (int i = 1; i < arr.size(); ++i)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = temp->next;
    }

    return head;
}

void display(Node *head)
{
    auto temp = head;

    while (temp != nullptr)
    {
        std::cout << temp->val << " -> ";
        temp = temp->next;
    }

    std::cout << "NULL" << std::endl;
}

// Reverse Linked List

Node *reverseLinkedList(Node *head) // Time: O(n) Space: O(1)
{
    auto temp = head;
    Node *prev = nullptr;

    // nullptr   1   ->   2   ->   3
    //   prev  temp     next
    // nullptr <- 1 <- 2
    while (temp != nullptr)
    {
        auto next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    return prev;
}

Node *reverseLinkedListRecursive(Node *temp, Node* prev = nullptr) // Time: O(n) Space: O(n)
{
    if (temp == nullptr)
        return prev;

    Node* next = temp->next;
    temp->next = prev;

    return reverseLinkedListRecursive(next, temp);
}

int main()
{
    const std::vector<int> arr = {1, 3, 5, 2, 6, 7, 12};
    const std::vector<int> arr2 = {1, 3, 5, 2, 6, 7, 12};
    Node *head = createLinkedList(arr);
    Node *head2 = createLinkedList(arr2);

    // Reverse linked list
    std::cout << "Linked lift before: ";
    display(head);

    std::cout << "Linked list after reverse: ";
    const auto newHead = reverseLinkedList(head);
    display(newHead);

    // Recursive reverse linked list
    std::cout << "Linked lift before: ";
    display(head2);

    std::cout << "Linked list after reverse (recursive): ";
    const auto newHead2 = reverseLinkedListRecursive(head2);
    display(newHead2);

    return 0;
}