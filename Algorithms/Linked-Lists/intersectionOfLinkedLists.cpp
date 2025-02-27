#include <iostream>
#include <unordered_map>

struct Node
{
    int val;
    Node *next;

    Node(int data) : val(data), next(nullptr) {};
};

Node *getIntersectionNode(Node *headA, Node *headB)
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
        {
            return headB;
        }
        headB = headB->next;
    }

    return nullptr;
}

int main()
{
    return 0;
}