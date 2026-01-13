#include <iostream>

// LeetCode: 146. LRU Cache
// https://leetcode.com/problems/lru-cache/description/
/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.


Example 1:
    Input
    ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
    [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
    Output
    [null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
    LRUCache lRUCache = new LRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    lRUCache.get(1);    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.get(2);    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.get(1);    // return -1 (not found)
    lRUCache.get(3);    // return 3
    lRUCache.get(4);    // return 4
*/

struct Node
{
    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};

class LRUCache // Time: O(1) for get() and put() Space: O(n)
{
public:
    std::unordered_map<int, Node *> cache;
    Node *head; // dummy node for LRU
    Node *tail; // dummy node for MRU
    int capacity;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void insert(Node *node)
    {
        Node *prev = tail->prev;
        prev->next = node;
        node->next = tail;
        node->prev = prev;
        tail->prev = node;
    }

    void remove(Node *node)
    {
        Node *next = node->next;
        Node *prev = node->prev;
        prev->next = next;
        next->prev = prev;
    }

    int get(int key)
    {
        if (cache.count(key) == 0)
        {
            return -1;
        }

        Node *node = cache[key];
        // step 1: add to MRU
        remove(node);
        insert(node);

        // step 2: return val
        return node->value;
    }

    void put(int key, int value)
    {
        // case 1: if key exists remove from double linked list
        if (cache.count(key) > 0)
        {
            Node *node = cache[key];
            node->value = value; // update old value
            remove(node);
            insert(node); // move to MRU
            return;
        }

        // case 2: insert new element to cache and MRU
        Node *newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        // case 3: if size is exceed capacity remove the LRU which is head->next
        if (cache.size() > capacity)
        {
            Node *lru = head->next;
            cache.erase(lru->key);
            remove(lru);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    return 0;
}