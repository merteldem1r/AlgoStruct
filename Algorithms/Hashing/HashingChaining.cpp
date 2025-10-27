#include <iostream>

// Hashing - Chaining
// Author: Mert Eldemir

/*
    In hashing there is a hash function that maps keys to some values. But these hashing functions may lead to a collision that is two or more keys are mapped to same value. Chain hashing avoids collision. The idea is to make each cell of hash table point to a linked list of records that have same hash function value.

    Look at the "Algorithms/Hashing/Hashing.cpp" and "Algorithms/Hashing/Hashing.md" to understand time analysis and lambda (loading factor) formula.

    Time Complexity for Searching:

        Example:
            n = 100, tableSize = 10

            Minimum comparasion = 1
            Maximum comparasion = 10
            Average = half = lamda / 2 = 10 / 2 = 5

    Average Successfull Search Time Complexity: 1 + lambda / 2
        * 1 comes from hash functions

    Average Unsuccessfull Search Time Complexity: 1 + lambda

    Worst Case Time Complexity = O(n) (if the hash functions generates same index for all keys)
*/

struct Node
{
    int val;
    Node *next;

    Node(int val) : val(val), next(nullptr) {}
};

int hashFunction(int key)
{
    return key % 10;
}

void printHashTable(Node *hashMap[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Index " << i << ": ";
        Node *temp = hashMap[i];
        while (temp != nullptr)
        {
            std::cout << temp->val << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }
}

int main()
{
    // Hash Function: h(x) = x % 10

    int keys[] = {16, 12, 25, 39, 6, 122, 5, 68, 75, 13, 10};
    int keysSize = sizeof(keys) / sizeof(keys[0]);

    Node *hashMap[10] = {nullptr};

    // INSERTING Phase
    for (int i = 0; i < keysSize; ++i)
    {
        const int hashedIdx = hashFunction(keys[i]);
        Node *newNode = new Node(keys[i]);

        if (hashMap[hashedIdx] == nullptr)
        {
            hashMap[hashedIdx] = newNode;
        }
        else
        {
            Node *temp = hashMap[hashedIdx];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    printHashTable(hashMap, 10);

    /*
        Index 0: 10 -> nullptr
        Index 1: nullptr
        Index 2: 12 -> 122 -> nullptr
        Index 3: 13 -> nullptr
        Index 4: nullptr
        Index 5: 25 -> 5 -> 75 -> nullptr
        Index 6: 16 -> 6 -> nullptr
        Index 7: nullptr
        Index 8: 68 -> nullptr
        Index 9: 39 -> nullptr
    */

    // SEARCHING Phase
    int lookingKey = 3; // modify this line for finding key
    int hashedIdx = hashFunction(lookingKey);

    if (hashMap[hashedIdx] == nullptr)
    {
        std::cout << "Key not found" << std::endl;
        exit(0);
    }

    Node *temp = hashMap[hashedIdx];
    while (temp != nullptr)
    {
        if (temp->val == lookingKey)
        {
            std::cout << "Key found" << std::endl;
            exit(0);
            break;
        }
        temp = temp->next;
    }

    std::cout << "Key not found" << std::endl;

    // DRAWBACKS: Without selecting proper cash functions we can make terrible hash collision which will get time complexity as O(n)

    return 0;
}