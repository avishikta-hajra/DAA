#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void dnf(int *arr, int n, int pivot)
{
    // Boundaries : (0 to low-1) < x, (low to mid-1) == x, (mid to high) is Unsorted, (high+1 to n-1) > x
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] > pivot)
        {
            swap(&arr[high], &arr[mid]);
            high--;
        }
        else if (arr[mid] < pivot)
        {
            swap(&arr[low], &arr[mid]);
            low++;
            mid++;
        }
        else // arr[mid]==pivot
        {
            mid++;
        }
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
    int pivot = 6;

    printArray(arr, n);
    dnf(arr, n, pivot);
    printArray(arr, n);

    return 0;
}