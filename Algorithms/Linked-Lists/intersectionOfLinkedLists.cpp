#include <iostream>
#include <unordered_map>

struct Node
{
    int val;
    Node *next;

    Node(int data) : val(data), next(nullptr) {};
};

// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
// LeetCode problem: https://leetcode.com/problems/intersection-of-two-linked-lists/description/

// 1) Method using Additional Space (unordered_map)
Node *getIntersectionNode(Node *headA, Node *headB) // Time: O(n) Space: O(n)
{
    std::unordered_map<Node *, int> listMap;

    while (headA != nullptr)
    {
        listMap[headA]++;
        headA = headA->next;
    }

    while (headB != nullptr)
    {
        if (listMap.count(headB) > 0)
            return headB;

        headB = headB->next;
    }

    return nullptr;
}

// 2) Method using One Iteration
Node *getIntersectionNode2(Node *headA, Node *headB)
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