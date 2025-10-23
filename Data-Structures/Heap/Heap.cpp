#include <iostream>

// HEAP
// AUTHOR: Mert Eldemir

// Heap is a Complete Binary tree; so it's height is always logN
// but Heap it's not useful for searching purpose

class MaxHeap
{
private:
    int *heapArr = nullptr;
    int capacity;
    int heapSize;

public:
    MaxHeap(int cap)
    {
        this->capacity = cap;
        this->heapSize = 0;
        this->heapArr = new int[capacity];
    }

    void Insert(int val) // Time: logN (as height of Heap) Space: O(1)
    {
        if (heapSize == capacity)
        {
            std::cout << "Heap is already full." << std::endl;
            return;
        }

        // insert at the end
        int currIdx = heapSize;
        heapArr[currIdx] = val;

        // move to top while inserted value is bigget than it's parents
        while (currIdx >= 0 && heapArr[currIdx] > heapArr[parent(currIdx)])
        {
            std::swap(heapArr[currIdx], heapArr[parent(currIdx)]);
            currIdx = parent(currIdx);
        }

        ++heapSize;
    }

    // helpers
    int left(int i) { return (2 * i) + 1; }

    int right(int i) { return (2 * i) + 2; }

    int parent(int i) { return (i - 1) / 2; }

    int getMax() { return heapArr[0]; }

    void printHeap()
    {
        std::cout << "[ ";
        for (int i = 0; i < heapSize; ++i)
        {
            std::cout << heapArr[i] << " ";
        }
        std::cout << "]";
    }
};

int main()
{

    // Create Heap using Insert | Time: O(nlogN)
    int arr[] = {10, 30, 20, 5, 45, 35, 25};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    MaxHeap *heap = new MaxHeap(arrSize);

    for (int i = 0; i < arrSize; ++i) // Time: O(nlogN)
    {
        heap->Insert(arr[i]);
    }

    heap->printHeap(); // [ 45 30 35 5 10 20 25 ]

    return 0;
}