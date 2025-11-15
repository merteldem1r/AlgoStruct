#include <iostream>

// LeetCode: 1290. Convert Binary Number in a Linked List to Integer
// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/

/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.
*/

struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

class Solution // Time: O(n) Space: O(1)
{
public:
    int getDecimalValue(Node *head)
    {
        int res = 0;

        auto temp = head;
        while (temp != nullptr)
        {
            res |= temp->val;
            res <<= 1;
            temp = temp->next;
        }

        return res >> 1;
    }
};

int main()
{
    return 0;
}