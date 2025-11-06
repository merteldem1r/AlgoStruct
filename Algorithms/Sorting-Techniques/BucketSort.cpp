#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// BUCKET SORT
// AUTHOR: Mert Eldemir

/*
 * BUCKET SORT - Adaptive distribution-based sorting algorithm
 * 
 * Concept: Distributes elements into buckets, sorts each bucket, then concatenates them.
 * Best for: Uniformly distributed data over a known range.
 * 
 * Time Complexity:
 *   - Best/Average: O(n + k) where k is number of buckets
 *   - Worst: O(n²) when all elements fall into one bucket
 * 
 * Space Complexity: O(n + k)
 * 
 * Adaptive: Yes - implementation varies based on data type and range
 * Stable: Yes - if bucket sort algorithm preserves order
 */

template <typename T>
void printArr(T &arr, int arrSize)
{
    std::cout << "{ ";
    for (int i = 0; i < arrSize; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "}" << std::endl;
}

// 1) ****************** Bucket Sort Linked List Version (for Non-Negative Integers) ******************
// Time: O(n + k) Space: O(n + k)

struct Node
{
    int value;
    Node *next;
};

void Insert(Node **ptrBins, int idx)
{
    // create new Node
    Node *newNode = new Node;
    newNode->value = idx;
    newNode->next = nullptr;

    if (ptrBins[idx] == nullptr) // ptrBins[idx] is head ptr
    {
        ptrBins[idx] = newNode;
    }
    else
    {
        // add to the tail
        Node *temp = ptrBins[idx];
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int Delete(Node **ptrBins, int idx)
{
    Node *head = ptrBins[idx]; // ptrBins[idx] is head ptr
    ptrBins[idx] = head->next;
    int tempVal = head->value;

    delete head;
    return tempVal;
}

int Max(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

void BucketSort1(int A[], int n)
{
    int max = Max(A, n);

    // Create bins array
    Node **bins = new Node *[max + 1];

    // Initialize bins array with nullptr
    for (int i = 0; i < max + 1; i++)
    {
        bins[i] = nullptr;
    }

    // Update count array values based on A values
    for (int i = 0; i < n; i++)
    {
        Insert(bins, A[i]);
    }

    // Update A with sorted elements
    int j = 0;

    for (int i = 0; i < max + 1; ++i)
    {
        if (bins[i] == nullptr)
        {
            continue;
        }

        Node *temp = bins[i];
        while (temp != nullptr)
        {
            Node *next = temp->next;
            A[j++] = temp->value;
            delete temp;
            temp = next;
        }
    }

    // Delete heap memory
    delete[] bins;
}

// 2) ****************** Bucket Sort for Normilized Data Range = [0, 1) ******************
// Time: O(n + k) Space: O(n + k)

void insertionSort(std::vector<float> &bucket)
{
    for (int i = 1; i < bucket.size(); ++i)
    {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to sort arr[] of size n using bucket sort
void BucketSort2(float arr[], int n)
{
    // 1) Create n empty buckets
    std::vector<std::vector<float>> b(n);

    // 2) Put array elements in different buckets
    for (int i = 0; i < n; i++)
    {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    // 3) Sort individual buckets using insertion sort
    for (int i = 0; i < n; i++)
    {
        insertionSort(b[i]);
    }

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            arr[index++] = b[i][j];
        }
    }
}

// 3) ****************** Bucket Sort General Range Version (Works for Any Numeric Data) ******************
// Time: O(n + k) average case, O(n^2) worst case Space: O(n + k)

void BucketSort3(float arr[], int n)
{
    if (n <= 0)
        return;

    // 1) Find min and max values
    float minVal = arr[0], maxVal = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] < minVal)
            minVal = arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    // 2) Calculate range and create buckets
    float range = maxVal - minVal;
    int bucketCount = n; // Using n buckets for optimal distribution

    std::vector<std::vector<float>> buckets(bucketCount);

    // 3) Distribute elements into buckets
    for (int i = 0; i < n; ++i)
    {
        int bi;
        if (range == 0)
        {
            bi = 0; // All elements are the same
        }
        else
        {
            bi = static_cast<int>((arr[i] - minVal) / range * (bucketCount - 1));
        }
        buckets[bi].push_back(arr[i]);
    }

    // 4) Sort individual buckets
    for (int i = 0; i < bucketCount; ++i)
    {
        if (buckets[i].size() > 1)
        {
            std::sort(buckets[i].begin(), buckets[i].end());
        }
    }

    // 5) Concatenate all buckets back into arr[]
    int idx = 0;
    for (int i = 0; i < bucketCount; ++i)
    {
        for (float val : buckets[i])
        {
            arr[idx++] = val;
        }
    }
}

int main()
{

    // 1) ********** Bucket Sort Linked List Version (for Non-Negative Integers) **********
    int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int aSize = sizeof(A) / sizeof(A[0]);

    std::cout << "1 - Not Sorted: ";
    printArr(A, aSize); // { 2 5 8 12 3 6 7 10 }
    BucketSort1(A, aSize);

    std::cout << "1 - Sorted: ";
    printArr(A, aSize); // { 2 3 5 6 7 8 10 12 }

    std::cout << std::endl;

    // 2) ********** Bucket Sort for Normilized Data Range = [0, 1) **********
    float B[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int bSize = sizeof(B) / sizeof(B[0]);

    std::cout << "2 - Not Sorted: ";
    printArr(B, bSize); // { 0.897 0.565 0.656 0.1234 0.665 0.3434 }
    BucketSort2(B, bSize);

    std::cout << "2 - Sorted: ";
    printArr(B, bSize); // { 0.1234 0.3434 0.565 0.656 0.665 0.897 }

    std::cout << std::endl;

    // 3) ********** Bucket Sort General Range Version (Works for any range including negatives) **********
    float C[] = {-5.5, 3.2, 10.8, -2.1, 7.4, 0.0, -8.9, 4.6};
    int cSize = sizeof(C) / sizeof(C[0]);

    std::cout << "3 - Not Sorted: ";
    printArr(C, cSize); // { -5.5 3.2 10.8 -2.1 7.4 0 -8.9 4.6 }
    BucketSort3(C, cSize);

    std::cout << "3 - Sorted: ";
    printArr(C, cSize); // { -8.9 -5.5 -2.1 0 3.2 4.6 7.4 10.8 }

    return 0;
}