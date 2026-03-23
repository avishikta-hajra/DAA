#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int idx = high;
    for (int i = high; i > low; i--)
    {
        if (arr[i] > pivot)
        {
            swap(&arr[idx], &arr[i]);
            idx--;
        }
    }
    swap(&arr[idx], &arr[low]);
    return idx;
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int part = partition(arr, low, high);

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
    int n = 10;
    int arr[] = {2, 6, 9, 6, 5, 1, 6, 8, 4, 3};
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}