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

std::pair<int, int> maxMin(Node *head)
{
    int max = head->val;
    int min = head->val;
    auto temp = head;

    while (temp != nullptr)
    {
        if (temp->val > max)
            max = temp->val;
        if (temp->val < min)
            min = temp->val;

        temp = temp->next;
    }

    return {max, min};
}

int main()
{
    const std::vector<int> arr = {1, 3, 5, 2, 6, 7, 12};
    Node *head = createLinkenList(arr);

    auto [max, min] = maxMin(head);

    std::cout << "Min: " << min << " Max: " << max << std::endl; // Min: 1 Max: 12

    return 0;
}