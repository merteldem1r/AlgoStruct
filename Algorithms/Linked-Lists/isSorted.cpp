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

// Check wether the linked list sorted or not (in ascending order)

bool isSorted(Node *head) // Time: O(n) Space: O(1)
{
    auto temp = head;

    while (temp->next != nullptr)
    {
        if (temp->next->val < temp->val)
            return false;
        temp = temp->next;
    }

    return true;
}

int main()
{
    const std::vector<int> arr = {1, 3, 5, 2, 6, 7, 12};
    const std::vector<int> arr2 = {1, 3, 5, 7, 12, 18, 25};
    Node *head = createLinkedList(arr);
    Node *head2 = createLinkedList(arr2);

    // code
    std::cout << std::boolalpha;

    std::cout << isSorted(head) << std::endl;  // false
    std::cout << isSorted(head2) << std::endl; // true

    std::cout << std::noboolalpha;
    return 0;
}