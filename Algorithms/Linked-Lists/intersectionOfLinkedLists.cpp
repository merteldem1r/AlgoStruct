#include <iostream>
#include <unordered_set>

// LeetCode: 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
*/

struct Node
{
    int val;
    Node *next;

    Node(int data) : val(data), next(nullptr) {};
};

// 1) Method using Additional Space (unordered_map)
Node *getIntersectionNode(Node *headA, Node *headB) // Time: O(n) Space: O(n)
{
    std::unordered_set<Node *> listSet;

    while (headA != nullptr)
    {
        listSet.insert(headA);
        headA = headA->next;
    }

    while (headB != nullptr)
    {
        if (listSet.find(headB) != listSet.end())
            return headB;

        headB = headB->next;
    }

    return nullptr;
}

// 2) Method using Lists Length Difference
class Solution // Time: O(n) Space: O(1)
{
public:
    int listLength(Node *head)
    {
        int len;
        auto temp = head;
        for (len = 0; temp != nullptr; temp = temp->next, ++len)
        {
        }
        return len;
    }

    Node *skipList(Node *head, int skipCount)
    {
        auto temp = head;
        for (int i = 0; i < skipCount; temp = temp->next, ++i)
        {
        }
        return temp;
    }

    Node *intersection(Node *head1, Node *head2)
    {
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1 == head2)
                return head1;

            head1 = head1->next;
            head2 = head2->next;
        }

        return nullptr;
    }

    Node *getIntersectionNode(Node *headA, Node *headB)
    {
        int headALen = listLength(headA);
        int headBLen = listLength(headB);

        int diff = headALen - headBLen;

        if (diff == 0)
            return intersection(headA, headB);

        auto ptr1 = diff > 0 ? skipList(headA, std::abs(diff)) : headA;
        auto ptr2 = diff > 0 ? headB : skipList(headB, std::abs(diff));

        return intersection(ptr1, ptr2);
    }
};

// 3) Method using Two Pointers (most efficient)
Node *getIntersectionNode2(Node *headA, Node *headB) // Time: O(n) Space: O(1)
{
    auto tempA = headA;
    auto tempB = headB;

    while (tempA != tempB)
    {
        tempA = tempA == nullptr ? headB : tempA->next;
        tempB = tempB == nullptr ? headA : tempB->next;
    }

    return tempA;
}

int main()
{
    return 0;
}