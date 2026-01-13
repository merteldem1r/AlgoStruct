#include <iostream>

// 705. Design HashSet
// https://leetcode.com/problems/design-hashset/description/

/*
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

    * void add(key) Inserts the value key into the HashSet.
    * bool contains(key) Returns whether the value key exists in the HashSet or not.
    * void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
*/

class MyHashSetArray // Time: O(1) | Space: O(1)
{
private:
    bool keys[1000001] = {false};

public:
    MyHashSetArray() {}

    void add(int key)
    {
        keys[key] = true;
    }

    void remove(int key)
    {
        keys[key] = false;
    }

    bool contains(int key)
    {
        return keys[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main()
{
    return 0;
}