#include <stdio.h>
#include <stdlib.h>

typedef struct Act // Each Activity
{
    int id;
    int start;
    int end;
} Act;

int compareFinish(const void *a, const void *b) // Compare function on finish time - Earliest Finish Time First
{
    Act *A = (Act *)a;
    Act *B = (Act *)b;

    if (A->end != B->end)
        return (A->end - B->end);
    return (A->start - B->start);
}

int compareStart(const void *a, const void *b) // Earliest Start Time First
{
    Act *A = (Act *)a;
    Act *B = (Act *)b;

    if (A->start != B->start)
        return (A->start - B->start);
    return (A->end - B->end);
}

int schedule(Act *activities, int n)
{
    int count = 1;
    int prev_end = activities[0].end;

    for (int i = 1; i < n; i++)
    {
        if (activities[i].start >= prev_end)
        {
            count++;
            prev_end = activities[i].end; // Updating end
        }
    }

    return count; // Max no. of acts that can be scheduled
}

void allPossibleActs(Act *acts, int idx, int maxActs, int n, int count, Act *arr, int st, int prev_end)
{
    if (count == maxActs) // Base Case -> ans found
    {
        for (int i = 0; i < count; i++) // Printing the array
        {
            printf("Activity %d : start - %d, end - %d\n", arr[i].id, arr[i].start, arr[i].end);
        }
        printf("\n");

        return;
    }

    if (st == n) // Base Case -> whole array traversed, ans not found
        return;

    for (int i = st; i < n; i++)
    {
        if (acts[i].start >= prev_end)
        {
            arr[idx] = acts[i];
            allPossibleActs(acts, idx + 1, maxActs, n, count + 1, arr, i + 1, acts[i].end); // call for next idx in og arr
        }
    }
}

int main()
{
    Act activities[] = {
        {1, 1, 4},
        {2, 3, 5},
        {3, 0, 6},
        {4, 5, 7},
        {5, 3, 9},
        {6, 5, 9},
        {7, 6, 10},
        {8, 8, 11},
        {9, 8, 12},
        {10, 2, 14},
        {11, 12, 16}};

    int n = sizeof(activities) / sizeof(activities[0]);
    qsort(activities, n, sizeof(Act), compareFinish);
    int maxActs = schedule(activities, n);

    qsort(activities, n, sizeof(Act), compareStart); // Earliest start time first

    Act *res = (Act *)malloc(maxActs * sizeof(Act));          // for storing the results
    allPossibleActs(activities, 0, maxActs, n, 0, res, 0, 0); // ( og arr, idx for res arr, max acts possible, no. of elements, res arr, starting idx of the call in the og arr, previous end time in the og arr )

    return 0;
}