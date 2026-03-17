#include <stdio.h>
#include <stdlib.h>
#define P(i) (((i) - 1) / 2)
#define L(i) (2 * (i) + 1)
#define R(i) (2 * (i) + 2)

typedef struct heapNode
{
    int val;
    int idx;
    int next;
} heapNode;

typedef struct minHeap
{
    heapNode *arr;
    int size;
} minHeap;

void swap(heapNode *a, heapNode *b)
{
    heapNode temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(minHeap *heap, int idx)
{
    int smallest = idx;
    int l = L(idx);
    int r = R(idx);
    if (l < heap->size && heap->arr[smallest].val > heap->arr[l].val)
        smallest = l;
    if (r < heap->size && heap->arr[smallest].val > heap->arr[r].val)
        smallest = r;

    if (smallest != idx)
    {
        swap(&heap->arr[idx], &heap->arr[smallest]);
        minHeapify(heap, smallest);
    }
}

void buildHeap(minHeap *heap)
{
    int n = heap->size;
    for (int i = P(n - 1); i >= 0; i--)
        minHeapify(heap, i);
}

mergeKSorted()
{
}

int main()
{
    return 0;
}