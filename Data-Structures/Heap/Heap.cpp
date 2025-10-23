#include <iostream>

// HEAP
// AUTHOR: Mert Eldemir

/*

HEAP also known as Priority Queue, is a Complete Binary tree; so it's height is always logN
BUT Heap it's not useful for searching purposes


Deleting on Heap mostly done only for the root:

 * if MaxHeap then you delete largest element
 * if MinHeap then you delete smallest element
   So we delete the highest priority element

*/

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

    MaxHeap(int cap, int arr[], int arrSize)
    {
        this->capacity = cap;
        this->heapSize = arrSize;
        this->heapArr = arr;
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

    void MaxHeapify(int i, int arrSize) // Time: O(logN) Space: O(n)
    {
        int l = left(i);
        int r = right(i);
        int max = i;

        if (l < arrSize && heapArr[max] < heapArr[l])
        {
            max = l;
        }

        if (r < arrSize && heapArr[max] < heapArr[r])
        {
            max = r;
        }

        if (i != max)
        {
            std::swap(heapArr[i], heapArr[max]);
            MaxHeapify(max, arrSize);
        }
    }

    void MaxHeapifyIterative(int i, int arrSize) // Time: O(log N) Space: O(1)
    {
        while (true)
        {
            int l = left(i);
            int r = right(i);

            int largest = i;

            if (l < arrSize && heapArr[l] > heapArr[largest])
                largest = l;

            if (r < arrSize && heapArr[r] > heapArr[largest])
                largest = r;

            if (largest == i)
            {
                break;
            }

            std::swap(heapArr[i], heapArr[largest]);
            i = largest;
        }
    }

    void removeMax()
    {
        if (heapSize == 0)
        {
            std::cout << "Heap is already empty." << std::endl;
            return;
        }
        else if (heapSize == 1)
        {
            --heapSize;
            return;
        }

        heapArr[0] = heapArr[heapSize - 1];
        --heapSize;
        MaxHeapify(0, heapSize);
    }

    // Helpers
    int left(int i) { return (2 * i) + 1; }

    int right(int i) { return (2 * i) + 2; }

    int parent(int i) { return (i - 1) / 2; }

    int getMax() { return heapArr[0]; }

    int *getHeapArr() { return heapArr; }

    void printHeapArr()
    {
        std::cout << "[ ";
        for (int i = 0; i < heapSize; ++i)
        {
            std::cout << heapArr[i] << " ";
        }
        std::cout << "]" << std::endl;
    }
};

int main()
{
    // ************** Max Heap Example **************
    MaxHeap HeapA(10);

    HeapA.Insert(30);
    HeapA.Insert(20);
    HeapA.Insert(15);
    HeapA.Insert(5);
    HeapA.Insert(10);
    HeapA.Insert(12);
    HeapA.Insert(6);

    HeapA.printHeapArr(); // [ 30 20 15 5 10 12 6 ]

    /*
        Should look like this:

        Tree:

                30
              /    \
            20      15
           /  \    /  \
          5   10  12   6

        Array:

        [ 30 20 15 5 10 12 6 ]
    */

    // ************** CREATE HEAP from Array using INSERT | Time: O(nlogN) **************
    int arr[] = {10, 30, 20, 5, 45, 35, 25};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    MaxHeap HeapB(arrSize);

    for (int i = 0; i < arrSize; ++i) // Time: O(nlogN)
    {
        HeapB.Insert(arr[i]);
    }

    HeapB.printHeapArr();                     // [ 45 30 35 5 10 20 25 ]
    std::cout << HeapB.getMax() << std::endl; // 45

    // ************** Creating Heap using Max-Heapify method and implementing Heap Sort **************
    int C[] = {10, 20, 25, 5, 40, 35, 15};
    int arrSizeC = sizeof(C) / sizeof(C[0]);

    // first let's create Max Heap from given array
    MaxHeap HeapC(arrSizeC, C, arrSizeC);

    std::cout << "C array before Heap Sort: ";
    HeapC.printHeapArr();

    // start from the last non-leaf element and call Max Heapify for each
    for (int i = (arrSizeC / 2) - 1; i >= 0; --i) // Time: O(n) Space: O(logN)
    {
        HeapC.MaxHeapify(i, arrSizeC);
    }

    std::cout << "C Max-Heap (after Max-Heapify): ";
    HeapC.printHeapArr();

    // * First element of our Heap is always the largest one
    // 1 - So by moving this element at the end by swapping with last element, we can move the largest element at the end (swap(lastIndex, 0))
    // 2 - Then by applying MaxHeapify on first element (arr[0]) we can restore Heap property again by moving largest to the top

    auto heapArrC = HeapC.getHeapArr();

    for (int i = arrSizeC - 1; i >= 0; --i) // Time: O(nlogN) Space: O(logN)
    {
        std::swap(heapArrC[0], heapArrC[i]);
        HeapC.MaxHeapify(0, i);
    }

    std::cout << "C Array (after Heap Sort): ";
    HeapC.printHeapArr();

    return 0;
}