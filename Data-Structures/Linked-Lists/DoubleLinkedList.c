#include <stdio.h>
#include <stdlib.h>

// Double Linked List

struct Node
{
    int val;
    struct Node *prev;
    struct Node *next;
};

struct DoubleLinkedList
{
    struct Node *head;
    struct Node *tail;
    int length;
};

int append(struct DoubleLinkedList *list, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->val = data;

    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }

    ++list->length;

    return data;
}

void traverse(struct DoubleLinkedList *list)
{
    struct Node *temp = list->head;

    while (temp != NULL)
    {
        printf("Node: %d Prev: %d\n", temp->val, temp->prev ? temp->prev->val : -1);
        temp = temp->next;
    }
}

int length(struct DoubleLinkedList *list)
{
    return list->length;
}

int freeList(struct DoubleLinkedList *list)
{
    struct Node *temp = list->head;

    while (temp != NULL)
    {
        struct Node *tempNext = temp->next;
        free(temp);
        temp = tempNext;
    }

    free(list);
}

int main()
{
    struct DoubleLinkedList *List = (struct DoubleLinkedList *)malloc(sizeof(struct DoubleLinkedList));
    List->head = NULL;
    List->tail = NULL;
    List->length = 0;

    append(List, 1);
    append(List, 2);
    append(List, 3);
    append(List, 4);
    append(List, 5);

    traverse(List);

    freeList(List);

    return 0;
}
