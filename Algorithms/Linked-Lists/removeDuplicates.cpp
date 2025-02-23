#include <iostream>
#include <unordered_set>

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

// Remove duplicates from the SORTED list
void removeDuplicatesSorted(Node *head) // Time: O(n) Spcae: O(1)
{
    if (head == nullptr) 
        return;

    auto temp = head;

    while (temp->next != nullptr)
    {
        auto next = temp->next;

        if (temp->val == next->val)
        {
            temp->next = next->next;
            delete next;
        }
        else
        {
            temp = next;
        }
    }
}

// Remove duplicates from UNSORTED list
void removeDuplicatesUnsorted(Node *head) // Time: O(n) Space: O(n)
{
    if (head == nullptr)
        return;

    auto temp = head;
    std::unordered_set<int> uniq;
    uniq.insert(temp->val);

    while (temp->next != nullptr)
    {
        const auto next = temp->next;

        if (uniq.find(next->val) != uniq.end())
        {
            temp->next = next->next;
            delete next;
        }
        else
        {
            uniq.insert(next->val);
            temp = temp->next;
        }
    }
}

int main()
{
    const std::vector<int> arr = {1, 1, 2, 2, 3, 5, 12, 18, 18};      // sorted
    const std::vector<int> arr2 = {1, 2, 5, 1, 5, 8, 12, 15, 18, 12}; // unsorted
    Node *head = createLinkedList(arr);
    Node *head2 = createLinkedList(arr2);

    // remove from SORTED
    std::cout << "sorted array BEFORE: ";
    display(head);

    std::cout << "sorted array AFTER: ";
    removeDuplicatesSorted(head);
    display(head);

    // remove from UNSORTED
    std::cout << "unsosted array BEFORE: ";
    display(head2);

    std::cout << "unsosted array AFTER: ";
    removeDuplicatesUnsorted(head2);
    display(head2);

    return 0;
}