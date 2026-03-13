/*

Problem 1 :

Left Shifting an array of integers by d positions
eg : {7, 8, 5, 6, 4, 3} when left shifted by d=3 => {6, 4, 3, 7, 8, 5}

*/

#include <stdio.h>
#include <stdlib.h>

void reverse(int *arr, int s, int e) // O(n)
{
    while (s < e) // 2 pointers
    {
        // Swap
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;

        s++;
        e--;
    }

    return;
};

void leftShift(int *arr, int n, int d) // O(n)
{
    d = d % n; // cyclic
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
};

void printArray(int *arr, int n) // O(n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
};

int main()
{
    int n;
    printf("Enter the no. of elements : ");
    scanf("%d", &n);

    if (n == 0) // Edge Case
    {
        printf("Array can't be empty !\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) // malloc failed
    {
        printf("Malloc Failed !\n");
        return 1;
    }
    printf("Enter the elements :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int d;
    printf("Enter the no. of positions to be left shifted by : ");
    scanf("%d", &d);

    printf("The original array is : ");
    printArray(arr, n);
    leftShift(arr, n, d);
    printf("The resultant array is : ");
    printArray(arr, n);

    free(arr);
    return 0;
}