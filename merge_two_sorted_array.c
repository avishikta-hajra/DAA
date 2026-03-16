#include <stdio.h>
#include <stdlib.h>

void mergeSortedArray(int *arr1, int *arr2, int m, int n)
{
    int idx = (m + n - 1);
    int i = m - 1, j = n - 1;

    while (i >= 0 && j >= 0)
    {
        if (arr1[i] > arr2[j])
            arr1[idx--] = arr1[i--];
        else
            arr1[idx--] = arr2[j--];
    }

    while (j >= 0) // if i>=0 and j<0 then as arr1 is final, we don't need to copy
    {
        arr1[idx--] = arr2[j--];
    }

    return;
}

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int m, n;
    int *arr1 = (int *)calloc((m + n), sizeof(int));
    int *arr2 = (int *)malloc(n * sizeof(int));

    printf("Enter the size for arr1 :\n");
    scanf("%d", &m);
    printf("Enter the elements for arr1 :\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("The elements for arr1 :");
    printArr(arr1, m);

    printf("Enter the size for arr2 :\n");
    scanf("%d", &n);
    printf("Enter the elements for arr2 :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }
    printf("The elements for arr2 :");
    printArr(arr2, n);

    mergeSortedArray(arr1, arr2, m, n);
    printf("The sorted array :");
    printArr(arr1, (m + n));

    return 0;
}