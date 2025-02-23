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

// Merge two sorted linked lists
Node *mergeLinkedLists(Node *h1, Node *h2)
{
    Node *dummy = new Node(-1);
    auto temp = dummy;

    while (h1 != nullptr && h2 != nullptr)
    {
        if (h1->val <= h2->val)
        {
            temp->next = h1;
            h1 = h1->next;
        }
        else
        {
            temp->next = h2;
            h2 = h2->next;
        }

        temp = temp->next;
    }

    if (h1 != nullptr)
        temp->next = h1;

    if (h2 != nullptr)
        temp->next = h2;

    return dummy->next;
}

int main()
{
    const std::vector<int> arr = {1, 3, 5, 7, 12, 18};
    const std::vector<int> arr2 = {1, 2, 3, 7, 18, 25, 42};
    Node *h1 = createLinkedList(arr);
    Node *h2 = createLinkedList(arr2);

    // code
    std::cout << "After merging: ";
    auto const newHead = mergeLinkedLists(h1, h2);
    display(newHead);

    return 0;
}