/*

Problem 3 :

A point P(x1, y1) is said to dominate another point Q(x2, y2) if : (x1 >= x2) and (y1 >= y2), where P and Q are not the exact same point. A point is considered maximal if it is not dominated by any other point in the set.
eg : in a set of points {(0,0), (0,2), (2,0), (2,2)} -> (2,2) is the maximal

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct pair
{
    int x;
    int y;
} pair;

int compare(const void *a, const void *b)
{
    pair *A = (pair *)a;
    pair *B = (pair *)b;

    // Return : <0 when A->x < B->x, >0 when A->x > B->x, when A->x == B->x : don't return 0, sort by y
    if (A->x != B->x)
        return (A->x - B->x);
    return (A->y - B->y);
}

void maximalPoint(pair *arr, int n)
{
    qsort(arr, n, sizeof(pair), compare); // Sorting in ascending order with respect to x-coordinates

    // For A to dominate on B, AND is followed (both coords of A must be greater than B) -> then for B to survive, i.e., for B to be the dominating point, OR is to be met (either x or y of B has to be greater)
    printf("The maximal points are :\n");
    int max_y = arr[n - 1].y; // Rightmost point is always maximal -> no point has greater x to dominate
    printf("(%d, %d) ", arr[n - 1].x, arr[n - 1].y);

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i].y > max_y) // taller in the left -> no point with greater x has greater y to dominate
        {
            printf("(%d, %d) ", arr[i].x, arr[i].y);
            max_y = arr[i].y; // Updating the tallest
        }
    }
    printf("\n");
}

void printArray(pair *arr, int n)
{
    printf("The points are :\n");
    for (int i = 0; i < n; i++)
    {
        printf("(%d, %d) ", arr[i].x, arr[i].y);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the no. of points : ");
    scanf("%d", &n);
    if (n == 0) // Edge Case
    {
        printf("No. of points can't be zero !\n");
        return 1;
    }

    pair *arr = (pair *)malloc(n * sizeof(pair));
    if (arr == NULL) // malloc failed
    {
        printf("Malloc Failed !\n");
        return 1;
    }

    printf("Enter the points :\n");
    for (int i = 0; i < n; i++)
    {
        printf("Point %d : ", i + 1);
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }

    printArray(arr, n);
    maximalPoint(arr, n);
    printArray(arr, n);

    free(arr);
    return 0;
}