#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// ARRAY ADT
// This is array modify console aspplication. Run the application and perform various methods on Array.

#define DISPLAY 1
#define APPEND 2
#define INSERT 3
#define DELETE 4
#define SEARCH 5
#define GET 6
#define SET 7
#define MAX 8
#define MIN 9
#define SUM 10
#define AVG 11
#define REVERSE 12
#define LEFT_SHIFT 13
#define RIGHT_SHIFT 14
#define ROTATE 16
#define IS_SORTED 17
#define EXIT 0

void swap();

struct Array
{
    int *A;
    int size;
    int length;
};

// Optional: Resizing for dynamic array implementation
void Resize(struct Array *arr)
{
    arr->size *= 2;
    int *temp = (int *)realloc(arr->A, arr->size * sizeof(int));

    if (temp == NULL)
    {
        printf("**Error: Memory reallocation failed!");
        free(arr->A);
        exit(1);
    }

    arr->A = temp;
}

void Display(struct Array *arr) // Time: O(n)
{
    printf("Array: [ ");
    for (int i = 0; i < arr->length; ++i)
        printf("%d ", arr->A[i]);
    printf("]\n");
}

void Append(struct Array *arr, int num) // Time: O(1)
{
    if (arr->size == arr->length)
    {
        printf("\t\t** Error: No empty space to Append");
        return;
    }

    arr->A[arr->length] = num;
    ++arr->length;
}

void Insert(struct Array *arr, int index, int num) // Time Worst: O(n) Best: O(1)
{
    if (arr->size == arr->length)
    {
        printf("\t\t** Error: No empty space to Insert\n");
        return;
    }

    if (index < 0 || index > arr->length)
    {
        printf("\t\t** Error: Invalid index. Index should be between 0 and %d\n", arr->length);
        return;
    }

    if (index == arr->length)
    {
        Append(arr, num);
        return;
    }

    for (int i = arr->length; i > index; --i)
        arr->A[i] = arr->A[i - 1];

    arr->A[index] = num;
    ++arr->length;
}

int Delete(struct Array *arr, int index) // Time Worst: O(n) Best: O(1)
{
    if (index < 0 || index >= arr->length)
    {
        printf("\t\t** Error: Invalid index for Delete\n");
        return -1;
    }

    int x = arr->A[index];

    for (int i = index; i < arr->length - 1; ++i)
    {
        arr->A[i] = arr->A[i + 1];
    }

    --arr->length;
    arr->A[arr->length] = 0;

    return x;
}

int Search(struct Array *arr, int key) // Time Worst: O(n) Best: O(1)
{
    /*
        Suggestions for Improving Linear Search:
            1. Transposition (moving element i-1 index on each search)
            2. Mo to Front (moving element to 0 index)
            3. Two Pointer Approach (in cases when chance of key on the end is same as on beginning)
            4. Binary Search (has O(logn) time complexity for sorted elements)
     */

    for (int i = 0; i < arr->length; ++i)
    {
        if (arr->A[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int Get(struct Array *arr, int index) // Time: O(1)
{
    if (index < 0 || index >= arr->length)
    {
        printf("Error: Invalid index to Get\n");
        return -1;
    }

    return arr->A[index];
}

int Set(struct Array *arr, int index, int num) // Time: O(1)
{
    if (index < 0 || index >= arr->length)
    {
        printf("Error: Invalid index to Set\n");
        return -1;
    }

    return arr->A[index] = num;
}

int Max(struct Array *arr) // Time: O(n)
{
    if (arr->length == 0)
    {
        printf("Error: Max number not found\n");
        return -1;
    }

    int max = INT_MIN;

    for (int i = 0; i < arr->length; ++i)
    {
        if (arr->A[i] > max)
            max = arr->A[i];
    }

    return max;
}

int Min(struct Array *arr) // Time: O(n)
{
    if (arr->length == 0)
    {
        printf("Error: Min number not found\n");
        return -1;
    }

    int min = INT_MAX;

    for (int i = 0; i < arr->length; ++i)
    {
        if (arr->A[i] < min)
            min = arr->A[i];
    }

    return min;
}

int Sum(struct Array *arr) // Time: O(n)
{
    int sum = 0;

    for (int i = 0; i < arr->length; ++i)
        sum += arr->A[i];

    return sum;
}

float Avg(struct Array *arr) // Time: O(n)
{
    return (float)Sum(arr) / arr->length;
}

void Reverse(struct Array *arr) // Time: O(n)
{
    int l = 0, r = arr->length - 1;

    while (l < r)
    {
        swap(&arr->A[l], &arr->A[r]);
        ++l, --r;
    }
}

int LeftShift(struct Array *arr) // Time: O(n)
{
    int prev = arr->A[arr->length - 1];
    arr->A[arr->length - 1] = 0;

    for (int i = arr->length - 2; i >= 0; --i)
    {
        int temp = arr->A[i];
        arr->A[i] = prev;
        prev = temp;
    }
}

int RightShift(struct Array *arr) // Time: O(n)
{
    int prev = arr->A[0];
    arr->A[0] = 0;

    for (int i = 1; i < arr->length; ++i)
    {
        int temp = arr->A[i];
        arr->A[i] = prev;
        prev = temp;
    }
}

void Rotate(struct Array *arr, int k) // Time: O(n) Space: O(n)
{
    // rotate the array to the right by k steps.

    if (k < 0)
    {
        printf("\t\t** Error: Invalid negative step for Rotate\n");
        return;
    }

    if (arr->length == 1 || k == 0 || k % arr->length == 0)
        return;

    if (arr->length == 2)
    {
        if (k % 2 != 0)
            swap(&arr->A[0], &arr->A[1]);
        return;
    }

    const int arrLen = arr->length;
    int *temp = (int *)malloc(arrLen * sizeof(int));

    for (int i = 0; i < arrLen; ++i)
        temp[(i + k) % arrLen] = arr->A[i];

    for (int i = 0; i < arrLen; ++i)
        arr->A[i] = temp[i];

    free(temp);
}

int IsSorted(struct Array *arr) // Time: O(n)
{
    // non-descending order
    for (int i = 0; i < arr->length - 1; ++i)
    {
        if (arr->A[i] > arr->A[i + 1])
            return 0;
    }

    return 1;
}

void displayOptions()
{
    printf("\t1: Display\t6: Get\t\t11: Avg\t\t17: Is Sorted\n");
    printf("\t2: Append\t7: Set\t\t12: Reverse\n");
    printf("\t3: Insert\t8: Max\t\t13: Left Shift\n");
    printf("\t4: Delete\t9: Min\t\t14: Right Shift\n");
    printf("\t5: Search\t10: Sum\t\t16: Rotate\n");

    printf("0: Exit");
    printf("\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    struct Array arr;
    int elemCount;

    // Initialize Array on HEAP
    printf("Enter size of an array: ");
    scanf("%d", &arr.size);

    if (arr.size <= 0)
    {
        printf("\t\t** Error: Array size must be positive\n");
        return 1;
    }

    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter number of elements: ");
    scanf("%d", &elemCount);

    if (elemCount > arr.size)
    {
        printf("\t\t** Error: Number of elements can not be greater than allocated array size\n");
        free(arr.A);
        return 1;
    }

    printf("Enter all elements: \n");
    for (int i = 0; i < elemCount; ++i)
    {
        printf("\tElement %d: ", i + 1);
        scanf("%d", &arr.A[i]);
    }

    arr.length = elemCount;
    Display(&arr);

    // Manipulatios on created Array from console
    while (1)
    {
        printf("Choose Options on Array:  \n");
        displayOptions();

        int option;
        printf("-> ");
        scanf("%d", &option);

        switch (option)
        {
        case DISPLAY:
            Display(&arr);
            break;

        case APPEND:
        {
            printf("\t\tEnter number: ");
            int num;
            scanf("%d", &num);
            Append(&arr, num);
            break;
        }
        case INSERT:
        {
            int index, num;
            printf("\t\tEnter insert index: ");
            scanf("%d", &index);

            printf("\t\tEnter number to insert: ");
            scanf("%d", &num);

            Insert(&arr, index, num);
            break;
        }
        case DELETE:
        {
            int index;
            printf("\t\tEnter delete index: ");
            scanf("%d", &index);

            printf("-> Deleted value: %d\n", Delete(&arr, index));
            break;
        }
        case SEARCH:
        {
            int key;
            printf("\t\tEnter num to search: ");
            scanf("%d", &key);
            printf("-> Found num at index: %d\n", Search(&arr, key));
            break;
        }
        case GET:
        {
            int index;
            printf("\t\tEnter index to get: ");
            scanf("%d", &index);
            printf("-> Found num: %d\n", Get(&arr, index));
            break;
        }
        case SET:
        {
            int index, num;
            printf("\t\tEnter index to set: ");
            scanf("%d", &index);

            printf("\t\tEnter number to set: ");
            scanf("%d", &num);
            printf("-> Setted num: %d\n at index: %d\n", Set(&arr, index, num), index);
            break;
        }
        case MAX:
        {
            printf("-> Max found number: %d\n", Max(&arr));
            break;
        }
        case MIN:
        {
            printf("-> Min found number: %d\n", Min(&arr));
            break;
        }
        case SUM:
        {
            printf("-> Sum of all elements: %d\n", Sum(&arr));
            break;
        }
        case AVG:
        {
            printf("-> Average of all elements: %.2f\n", Avg(&arr));
            break;
        }
        case REVERSE:
        {
            Reverse(&arr);
            printf("-> Elements reversed: ");
            Display(&arr);
            break;
        }
        case LEFT_SHIFT:
        {
            LeftShift(&arr);
            printf("-> Elements left shifted: ");
            Display(&arr);
            break;
        }
        case RIGHT_SHIFT:
        {
            RightShift(&arr);
            printf("-> Elements right shifted: ");
            Display(&arr);
            break;
        }
        case ROTATE:
        {
            int k;
            printf("\tEnter non-negative Rotate step: ");
            scanf("%d", &k);
            Rotate(&arr, k);
            printf("-> Elements right roted for %d steps: ", k);
            Display(&arr);
            break;
        }
        case IS_SORTED:
        {

            if (IsSorted(&arr))
                printf("-> Array is Sorted in non-descending order!\n");
            else
                printf("-> Array is NOT Sorted in non-descending order!\n");

            break;
        }

        case EXIT:
            free(arr.A);
            arr.A = NULL;
            return 0;
        }
    }

    // Deallocate memory
    free(arr.A);
    arr.A = NULL;

    return 0;
}