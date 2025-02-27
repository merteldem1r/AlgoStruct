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

// Find the middle element of the linked list
// 1 -> 2 -> 3 -> 4     middle = 3
// 1 -> 2 -> 3 -> 4 -> 5    middle = 3

// Method 1 using additional array
int middleOfLinkedList(Node *head) // Time: O(n) Space: O(n)
{
    auto temp = head;
    std::vector<int> arr;

    while (temp != nullptr)
    {
        arr.emplace_back(temp->val);
        temp = temp->next;
    }

    const int mid = arr.size() / 2;
    return arr[mid];
}

// Efficient method using Two Pointers (slow and fast)
int middleOfLinkedListTwoPointers(Node *head) // Time: O(n) Space: O(1)
{
    auto slow = head;
    auto fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow->val;
}

int main()
{
    const std::vector<int> arr = {1, 3, 5, 2, 6, 7, 12};
    const std::vector<int> arr2 = {1, 3, 5, 18, 6, 7};
    Node *head = createLinkedList(arr);
    Node *head2 = createLinkedList(arr2);

    // std::cout << middleOfLinkedList(head) << std::endl; // 2
    std::cout << "1 Method (adittional space): " << std::endl;
    std::cout << middleOfLinkedList(head) << std::endl;  // 2
    std::cout << middleOfLinkedList(head2) << std::endl; // 18

    std::cout << "2 Method (two pointers): " << std::endl;
    std::cout << middleOfLinkedListTwoPointers(head) << std::endl;  // 2
    std::cout << middleOfLinkedListTwoPointers(head2) << std::endl; // 18

    return 0;
}