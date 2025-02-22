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

// Display Linked List

// using while loop
void display(Node * head) { // Time: O(n) Space: O(1)
    auto temp = head;

    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
}

// using recursion
void displayRecursion(Node* head) { // Time: O(n) Space: O(n)
    if (head == nullptr) return;

    std::cout << head->val << " ";
    displayRecursion(head->next);    
}

int main()
{
    const std::vector<int> arr = {1, 3, 5, 2, 6, 7, 12};
    Node *head = createLinkenList(arr);

    display(head);
    std::cout << std::endl;
    displayRecursion(head);

    return 0;
}