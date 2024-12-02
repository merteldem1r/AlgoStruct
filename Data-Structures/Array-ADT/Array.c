#include <stdio.h>
#include <stdlib.h>

// ARRAY ADT

#define DISPLAY 1
#define APPEND 2
#define INSERT 3
#define DELETE 4
#define SEARCH 5
#define EXIT 0

struct Array
{
    int *A;
    int size;
    int length;
};

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
        fprintf(stderr, "Error: No empty space to Append");
        return;
    }

    arr->A[arr->length] = num;
    ++arr->length;
}

void Insert(struct Array *arr, int indx, int num) // Time Worst: O(n) Best: O(1)
{
    if (arr->size == arr->length)
    {
        fprintf(stderr, "Error: No empty space to Insert\n");
        return;
    }

    if (indx < 0 || indx > arr->length)
    {
        fprintf(stderr, "Error: Invalid index. Index should be between 0 and %d\n", arr->length);
        return;
    }

    if (indx == arr->length)
    {
        Append(arr, num);
        return;
    }

    for (int i = arr->length; i > indx; --i)
        arr->A[i] = arr->A[i - 1];

    arr->A[indx] = num;
    ++arr->length;
}

int Delete(struct Array *arr, int indx) // Time Worst: O(n) Best: O(1)
{
    if (indx < 0 || indx >= arr->length)
    {
        fprintf(stderr, "Error: Invalid index for Delete\n");
        return -1;
    }

    int x = arr->A[indx];

    for (int i = indx; i < arr->length - 1; ++i)
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

void displayOptions()
{
    printf("\t1: Display\n");
    printf("\t2: Append\n");
    printf("\t3: Insert\n");
    printf("\t4: Delete\n");
    printf("\t5: Search\n");
    printf("\t0: Exit\n");
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
        fprintf(stderr, "Error: Array size must be positive\n");
        return 1;
    }

    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter number of elements: ");
    scanf("%d", &elemCount);

    if (elemCount > arr.size)
    {
        fprintf(stderr, "Error: Number of elements can not be greater than allocated array size\n");
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

            printf("\t\tDeleted value: %d\n", Delete(&arr, index));
            break;
        }
        case SEARCH:
        {
            int key;
            printf("\t\tEnter num to search: ");
            scanf("%d", &key);
            printf("\t\tFound num at index: %d\n", Search(&arr, key));
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