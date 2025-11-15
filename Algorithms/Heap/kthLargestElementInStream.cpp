#include <iostream>

// LeetCode: 703. Kth Largest Element in a Stream
// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

/*
You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.

Example 1:

    Input:
    ["KthLargest", "add", "add", "add", "add", "add"]
    [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

    Output: [null, 4, 5, 5, 8, 8]

    Explanation:
        KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
        kthLargest.add(3); // return 4
        kthLargest.add(5); // return 5
        kthLargest.add(10); // return 5
        kthLargest.add(9); // return 8
        kthLargest.add(4); // return 8
*/

// Naive solutiion (WILL GET TIME LIMIT EXCEEDED ON LARGE DATA)
class KthLargestSorting // Time: O(m * nlogN) m: is number of calls made add()
{
private:
    std::vector<int> arr;
    int k;

    static bool comparator(int a, int b)
    {
        return a > b;
    }

public:
    KthLargestSorting(int k, std::vector<int> &nums)
    {
        this->k = k;
        this->arr = nums;
    }

    int add(int val)
    {
        arr.emplace_back(val);
        std::sort(arr.begin(), arr.end(), comparator); // Time: O(nlogN)
        return arr[k - 1];
    }
};

// SOLUTION 1: Manual Implementaion of Priority Queue (Heap)
class KthLargestManual // Time: O(log k) Space: O(k)
{
public:
    std::vector<int> minHeap;
    int k = 0;

    int parentIndex(int i) { return (i - 1) / 2; }

    int top() { return minHeap[0]; }

    // push value to the minHeap
    void push(int num)
    {
        minHeap.emplace_back(num);
        int i = minHeap.size() - 1;

        while (i > 0 && minHeap[parentIndex(i)] > minHeap[i])
        {
            std::swap(minHeap[parentIndex(i)], minHeap[i]);
            i = parentIndex(i);
        }
    }

    // remove top min value from minHeap
    void pop()
    {
        if (minHeap.size() == 0)
        {
            return;
        }

        if (minHeap.size() == 1)
        {
            minHeap.pop_back();
            return;
        }

        const int lastIndx = minHeap.size() - 1;
        minHeap[0] = minHeap[lastIndx];
        minHeap.pop_back();
        minHeapify(0);
    }

    void minHeapify(int i)
    {
        while (true)
        {
            int l = i * 2 + 1, r = i * 2 + 2, smallest = i;

            if (l < minHeap.size() && minHeap[l] < minHeap[smallest])
            {
                smallest = l;
            }

            if (r < minHeap.size() && minHeap[r] < minHeap[smallest])
            {
                smallest = r;
            }

            if (smallest == i)
            {
                break;
            }

            std::swap(minHeap[smallest], minHeap[i]);
            i = smallest;
        }
    }

    KthLargestManual(int k, std::vector<int> &nums)
    {
        this->k = k;

        // build minHeap from inital nums arr
        for (auto num : nums)
        {
            if (minHeap.size() < k)
            {
                push(num);
            }
            else if (num > top())
            {
                push(num);
                if (minHeap.size() > k)
                {
                    pop();
                }
            }
        }

        std::cout << "arr after KthLargest: ";
    }

    void printArr()
    {
        std::cout << "{ ";

        for (int i = 0; i < minHeap.size(); ++i)
            std::cout << minHeap[i] << " ";

        std::cout << "}" << std::endl;
    }

    int add(int val)
    {
        if (minHeap.size() < k)
        {
            push(val);
        }
        else if (val > top())
        {
            push(val);
            if (minHeap.size() > k)
            {
                pop();
            }
        }
        return top();
    }
};

// SOLUTION 2: using built-in std::priority_queue<> data structure
class KthLargestBuiltIn // Time: O(log k) Space: O(k)
{
public:
    std::vector<int> minHeap;
    int k = 0;

    int parentIndex(int i) { return (i - 1) / 2; }

    int top() { return minHeap[0]; }

    // push value to the minHeap
    void push(int num)
    {
        minHeap.emplace_back(num);
        int i = minHeap.size() - 1;

        while (i > 0 && minHeap[parentIndex(i)] > minHeap[i])
        {
            std::swap(minHeap[parentIndex(i)], minHeap[i]);
            i = parentIndex(i);
        }
    }

    // remove top min value from minHeap
    void pop()
    {
        if (minHeap.size() == 0)
        {
            return;
        }

        if (minHeap.size() == 1)
        {
            minHeap.pop_back();
            return;
        }

        const int lastIndx = minHeap.size() - 1;
        minHeap[0] = minHeap[lastIndx];
        minHeap.pop_back();
        minHeapify(0);
    }

    void minHeapify(int i)
    {
        while (true)
        {
            int l = i * 2 + 1, r = i * 2 + 2, smallest = i;

            if (l < minHeap.size() && minHeap[l] < minHeap[smallest])
            {
                smallest = l;
            }

            if (r < minHeap.size() && minHeap[r] < minHeap[smallest])
            {
                smallest = r;
            }

            if (smallest == i)
            {
                break;
            }

            std::swap(minHeap[smallest], minHeap[i]);
            i = smallest;
        }
    }

    KthLargestBuiltIn(int k, std::vector<int> &nums)
    {
        this->k = k;

        // build minHeap from inital nums arr
        for (auto num : nums)
        {
            if (minHeap.size() < k)
            {
                push(num);
            }
            else if (num > top())
            {
                push(num);
                if (minHeap.size() > k)
                {
                    pop();
                }
            }
        }

        std::cout << "arr after KthLargest: ";
    }

    void printArr()
    {
        std::cout << "{ ";

        for (int i = 0; i < minHeap.size(); ++i)
            std::cout << minHeap[i] << " ";

        std::cout << "}" << std::endl;
    }

    int add(int val)
    {
        if (minHeap.size() < k)
        {
            push(val);
        }
        else if (val > top())
        {
            push(val);
            if (minHeap.size() > k)
            {
                pop();
            }
        }
        return top();
    }
};

int main()
{
    return 0;
}