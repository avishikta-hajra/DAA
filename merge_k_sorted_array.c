#include <stdio.h>
#include <stdlib.h>
#define P(i) (((i) - 1) / 2)
#define L(i) (2 * (i) + 1)
#define R(i) (2 * (i) + 2)

typedef struct heapNode // (val, array no., index no.)
{
    int val;
    int arrIdx;
    int eleIdx;
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

int *mergeKSorted(int **arrs, int *sizes, int k, int total)
{
    int *res = (int *)malloc(total * sizeof(int)); // final array
    minHeap *heap = (minHeap *)malloc(sizeof(minHeap));
    heap->arr = (heapNode *)malloc(k * sizeof(heapNode));
    heap->size = 0; // increments as the nodes are successfully added

    for (int i = 0; i < k; i++) // Initialisation of the heap arr with first elemnts from each input k arrays
    {
        if (sizes[i] > 0) // Check so that the size of input arrays is not empty
        {
            heap->arr[heap->size].val = arrs[i][0];
            heap->arr[heap->size].arrIdx = i;
            heap->arr[heap->size].eleIdx = 0;
            heap->size++; // Incrementing for the final size
        }
    }
    buildHeap(heap);

    for (int count = 0; count < total; count++)
    {
        heapNode root = heap->arr[0]; // Extraction
        res[count] = root.val;

        if (root.eleIdx + 1 < sizes[root.arrIdx]) // if next ele exists
        {
            root.val = arrs[root.arrIdx][root.eleIdx + 1];
            root.eleIdx++; // Updated the element Index of root, array Index remains the same
        }
        else // if the input array has beeen completed
        {
            root = heap->arr[heap->size - 1];
            heap->size--; // Reducing the heap size as an array has been exhausted
        }

        heap->arr[0] = root; // PLacing the new root
        if (heap->size > 0)  // minHeapify on the updated array after root has been extracted
            minHeapify(heap, 0);
    }

    free(heap->arr);
    free(heap);
    return res;
}

void printArray(int *arr, int n) // O(n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int k;
    printf("Enter the no. of arrays to be merged : ");
    scanf("%d", &k);
    int total = 0;
    int *sizes = (int *)malloc(k * sizeof(int));
    printf("Enter the sizes of the arrays :\n");
    for (int i = 0; i < k; i++)
    {
        printf("For array %d : ", i + 1);
        scanf("%d", &sizes[i]);
        total += sizes[i];
    }

    int **arrs = (int **)malloc(k * sizeof(int *));
    for (int i = 0; i < k; i++)
    {
        arrs[i] = (int *)malloc(sizes[i] * sizeof(int));
        printf("Enter the elements for array %d :\n", i + 1);
        for (int j = 0; j < sizes[i]; j++)
        {
            scanf("%d", &arrs[i][j]);
        }
    }

    for (int i = 0; i < k; i++)
    {
        printf("Array %d :\n", i + 1);
        printArray(arrs[i], sizes[i]);
    }

    int *res = mergeKSorted(arrs, sizes, k, total);

    printf("The merged array is : ");
    printArray(res, total);

    // free
    for (int i = 0; i < k; i++)
    {
        free(arrs[i]);
    }
    free(arrs);
    free(sizes);
    free(res);

    return 0;
}