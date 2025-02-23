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



int main()
{
    const std::vector<int> arr = {1, 3, 5, 2, 6, 7, 12};
    const std::vector<int> arr2 = {1, 3, 5, 7, 12, 18, 25};
    Node *head = createLinkedList(arr);
    Node* head2 = createLinkedList(arr2);

    // code

    return 0;
}