#include <iostream>
#include <unordered_set>

struct Node
{
    int val;
    Node *next;

    Node(int data) : val(data), next(nullptr) {};
};

Node *createLinkedList(const std::vector<int> arr, bool isCycle = false)
{
    Node *head = new Node(arr[0]);
    auto temp = head;
    Node *toNode;

    for (int i = 1; i < arr.size(); ++i)
    {
        if (isCycle && i == 4)
            toNode = temp;

        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = temp->next;
    }

    if (isCycle)
        temp->next = toNode;

    return head;
}

// Determine if the linked list have a cycle. There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
// 1 -> 2 -> 5 -> 4
//      ^---------|

// using additional space
bool isCycle(Node *head) // Time: O(n) Space: O(n)
{
    auto temp = head;
    std::unordered_set<Node *> nodeSet;

    while (temp != nullptr)
    {
        if (nodeSet.find(temp) != nodeSet.end())
            return true;
        else
            nodeSet.insert(temp);
        temp = temp->next;
    }

    return false;
}


// using two pointer approach (better approach)
bool isCycleTwoPointer(Node* head) { // Time: O(n) Space: O(1)
    auto slow = head;
    auto fast = head->next;

    while (slow != nullptr && fast != nullptr) {
        if (slow == fast) 
            return true;

        slow = slow->next;
        fast = fast->next->next;
    }

    return false;
}

int main()
{
    const std::vector<int> arr = {1, 3, 5, 2, 6, 7, 12};
    Node *cycledHead = createLinkedList(arr, true);
    Node *head = createLinkedList(arr);

    std::cout << std::boolalpha;

    std::cout << "is cycledHead has cycle: " << isCycle(cycledHead) << std::endl; // true
    std::cout << "is head has cycle: " << isCycle(head) << std::endl;             // false

    std::cout << "is cycledHead has cycle (using two pointer): " << isCycleTwoPointer(cycledHead) << std::endl; // true
    std::cout << "is head has cycle (using two pointer): " << isCycleTwoPointer(head) << std::endl;             // false

    std::cout << std::noboolalpha;

    return 0;
}