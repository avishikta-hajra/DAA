#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int idx = low;
    for (int i = low; i < high; i++)
    {
        if (arr[i] < pivot)
        {
            swap(&arr[idx], &arr[i]);
            idx++;
        }
    }
    swap(&arr[idx], &arr[high]);
    return idx;
}

int randPartition(int *arr, int low, int high)
{
    int randIdx = low + rand() % (high - low + 1);
    swap(&arr[randIdx], &arr[high]);
    return partition(arr, low, high);
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int part = randPartition(arr, low, high);

        // Sorting the subarrays before and after pivot
        quickSort(arr, low, part - 1);
        quickSort(arr, part + 1, high);
    }
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
    srand(time(NULL));

    int n = 10;
    int arr[] = {2, 6, 9, 6, 5, 1, 6, 8, 4, 3};
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}