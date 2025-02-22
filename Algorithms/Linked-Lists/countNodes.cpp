#include <iostream>

struct Node
{
    int val;
    Node *next;

    Node(int data) : val(data), next(nullptr) {};
};

Node *createLinkenList(std::vector<int> arr)
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

// Recursive
int countNodes(Node *head) // Time
{
    if (head == nullptr)
        return 0;

    return countNodes(head->next) + 1;
}

// Loop
int countNodesLoop(Node* head) {
    int count = 0;
    auto temp = head;

    while (temp != nullptr) {
        ++count;
        temp = temp->next;
    }

    return count;
}

int main()
{
    const std::vector<int> arr = {1, 3, 5, 2, 6, 7, 12};
    Node *head = createLinkenList(arr);

    std::cout << "Node count: " << countNodes(head); // 7

    return 0;
}