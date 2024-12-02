#include <stdio.h>
#include <stdlib.h>

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

void Insert(struct Array *arr, int indx, int num) // Time: 0(n)
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

void displayOptions()
{
    printf("\t1: Display\n");
    printf("\t2: Append\n");
    printf("\t3: Insert\n");
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

    while (1)
    {
        printf("Choose Options on Array:  \n");
        displayOptions();

        int option;
        printf("-> ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            Display(&arr);
            break;

        case 2:
        {
            printf("\t\tEnter number: ");
            int num;
            scanf("%d", &num);
            Append(&arr, num);
            break;
        }
        case 3:
        {
            int index, num;
            printf("\t\tEnter insert index: ");
            scanf("%d", &index);

            printf("\t\tEnter number to insert: ");
            scanf("%d", &num);

            Insert(&arr, index, num);
            break;
        }
        case 0:
            break;
        }
    }

    // Deallocate memory
    free(arr.A);
    arr.A = NULL;

    return 0;
}