#include <iostream>

// HEAP

/*
    Heap Properties:

        * It's complete binary tree which means always the  height of the tree will be log N only

        * Max Heap: Every node should have the element greater or equal to it's all descendants.

        * Min Heap: Every node should have the element less or equal to it's all descendants.

        * From the Heap you can only delete largest (for Max Heap) or smallets (for Min Heap), you can not delete other elements

        * Heaps usually represented as arrays where:

            * Root element will be at arr[0]
            * arr[(i - 1) / 2] returns the parent node
            * arr[(2 * i) + 1] returns the left child node
            * arr[(2 * i) + 2] return the right child node

*/

class MaxHeap
{
    int *heapArr;
    int capacity;
    int heapSize;

public:
    MaxHeap(int capacity);

    MaxHeap(int capacity, int A[], int arrSize);

    void MaxHeapify(int i, int arrSize);

    int extractMax();

    int Parent(int i) { return (i - 1) / 2; };

    int Left(int i) { return (i * 2) + 1; };

    int Right(int i) { return (i * 2) + 2; };

    void insert(int key);

    void print();

    int getMax() { return heapArr[0]; }

    int *getHeapArr() { return heapArr; }

    // ~MaxHeap() { std::cout << "Deleting Heap\n"; };
};

MaxHeap::MaxHeap(int cap)
{
    heapSize = 0;
    capacity = cap;
    heapArr = new int[cap];
}

MaxHeap::MaxHeap(int cap, int A[], int arrSize)
{
    heapSize = arrSize;
    capacity = cap;
    heapArr = A;
}

void MaxHeap::insert(int key)
{
    if (heapSize == capacity)
    {
        std::cout << "Could not insert, heap is already full." << std::endl;
        return;
    }

    // First we insert the key at the end of the array
    ++heapSize;
    int i = heapSize - 1;
    heapArr[i] = key;

    // If the max heap property if violated then we fix it
    while (i > 0 && heapArr[Parent(i)] < heapArr[i])
    {
        std::swap(heapArr[i], heapArr[Parent(i)]);
        i = Parent(i);
    }
}

void MaxHeap::MaxHeapify(int i, int arrSize) // Time Complexity: O(logn)
{
    int l = Left(i);
    int r = Right(i);

    int largest = i;

    if (l < arrSize && heapArr[l] > heapArr[largest])
        largest = l;

    if (r < arrSize && heapArr[r] > heapArr[largest])
        largest = r;

    if (largest != i)
    {
        std::swap(heapArr[i], heapArr[largest]);
        MaxHeapify(largest, arrSize);
    }
}

int MaxHeap::extractMax()
{
    if (heapSize == 0)
        return INT_MIN;

    if (heapSize == 1)
    {
        --heapSize;
        return heapArr[0];
    }

    int root = heapArr[0];
    heapArr[0] = heapArr[heapSize - 1];
    --heapSize;
    MaxHeapify(0, heapSize);

    return root;
}

void MaxHeap::print()
{
    std::cout << "{ ";

    for (int i = 0; i < heapSize; ++i)
        std::cout << heapArr[i] << " ";

    std::cout << "}" << std::endl;
}

int main()
{
    // ************** Max Heap Example
    MaxHeap HeapA(10);

    HeapA.insert(30);
    HeapA.insert(20);
    HeapA.insert(15);
    HeapA.insert(5);
    HeapA.insert(10);
    HeapA.insert(12);
    HeapA.insert(6);

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

    std::cout << "A Max-Heap: ";
    HeapA.print(); // [ 30 20 15 5 10 12 6 ]

    HeapA.extractMax();

    std::cout << "A Max-Heap (after extractMax function): ";
    HeapA.print(); // [ 20 10 15 5 6 12 ]

    // ************** Creating Heap from given array using Insert() function
    std::cout << "\n";
    int A[] = {10, 20, 25, 5, 40, 35};

    MaxHeap HeapB(6);

    for (int i = 0; i < 6; ++i) // Time Complexity: O(n log(n))
        HeapB.insert(A[i]);

    std::cout << "B Max-Heap: ";
    HeapB.print();

    // ************** Creating Heap using Max-Heapify method and implementing Heap Sort
    std::cout << "\n";
    int C[] = {10, 20, 25, 5, 40, 35, 15};
    int cSize = 6;

    MaxHeap HeapC(6, C, cSize);

    std::cout << "C Array (not Max-Heap yet): ";
    HeapC.print();

    for (int i = cSize / 2 - 1; i >= 0; --i)
    {
        HeapC.MaxHeapify(i, cSize);
    }

    std::cout << "C Max-Heap (after Max-Heapify): ";
    HeapC.print();

    // Implementing Heap Sort on created Max Heap
    auto cArr = HeapC.getHeapArr();

    // Here we starting from the last non-leaf node and keep extracting elements from heap and calling max heapify on reduced size Heap
    for (int i = cSize - 1; i > 0; --i) // Time Complexity: O(n logn)
    {
        std::swap(cArr[0], cArr[i]);
        HeapC.MaxHeapify(0, i);
    }

    std::cout << "C Array (after Heap Sort): ";
    HeapC.print();

    return 0;
}
