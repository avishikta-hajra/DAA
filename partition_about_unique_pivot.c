#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void partition(int *arr, int n, int pivot)
{
    int pivotIdx = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == pivot)
        {
            pivotIdx = i;
            break;
        }
    }

    if (pivotIdx == -1) // If pivot dne
        return;

    swap(&arr[pivotIdx], &arr[n - 1]); // placing pivot in the end so that its idx is not lost

    int idx = 0; // for swap
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] <= pivot) // or (arr[i] < pivot)
        {
            swap(&arr[idx], &arr[i]);
            idx++;
        }
    }

    swap(&arr[idx], &arr[n - 1]); // idx after the loop points to the first ele > pivot
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n = 10;
    int arr[] = {2, 4, 9, 6, 5, 1, 7, 8, 4, 3};
    int pivot = 6;

    printArray(arr, n);
    partition(arr, n, pivot);
    printArray(arr, n);

    return 0;
}