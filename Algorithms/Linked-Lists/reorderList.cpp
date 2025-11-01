#include <iostream>

// LeetCode: 143. Reorder List
// https://leetcode.com/problems/reorder-list/description/

/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
*/

struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

class SolutionVector
{
public:
    void reorderList(Node *head) // Time: O(n) Space: O(n)
    {
        if (head->next == nullptr)
        {
            return;
        }

        std::vector<Node *> v;
        for (auto temp = head; temp != nullptr; temp = temp->next)
            v.emplace_back(temp);

        int l = 0, r = v.size() - 1;
        while (l < r)
        {
            v[l++]->next = v[r];
            if (l == r)
                break;
            v[r--]->next = v[l];
        }

        v[l]->next = nullptr;
    }
};

class SolutionFaster
{
public:
    void reorderList(Node *head) // Time: O(n) Space: O(1)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }

        // find middle
        auto slow = head, fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half
        Node *prev = nullptr;
        Node *curr = slow->next;
        slow->next = nullptr;
        while (curr != nullptr)
        {
            auto currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
        }

        // merging first and second half
        auto second = prev;
        auto first = head;
        while (second != nullptr)
        {
            auto fNext = first->next;
            auto sNext = second->next;
            first->next = second;
            second->next = fNext;
            first = fNext;
            second = sNext;
        }
    }
};

int main()
{
    return 0;
}