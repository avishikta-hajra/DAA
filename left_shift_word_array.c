/*

Problem 2 :

Left Shifting an array of words(strings) by d positions
eg : "Coding in C" when left shifted by d=2 => "C Coding in"

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

void reverse(char **arr, int s, int e) // O(n)
{
    while (s < e)
    {
        // Swapping the pointers
        char *temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;

        s++;
        e--;
    }

    return;
};

void leftShift(char **arr, int n, int d) // O(n)
{
    d = d % n; // cyclic
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
};

void printArray(char **arr, int n) // O(n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s ", arr[i]);
    }
    printf("\n");
};

int main()
{
    int n;
    printf("Enter the no. of words : ");
    scanf("%d", &n);

    if (n == 0) // Edge Case
    {
        printf("Array can't be empty !\n");
        return 1;
    }

    char **words = (char **)malloc(n * sizeof(char *));
    if (words == NULL) // malloc failed
    {
        printf("Malloc Failed !\n");
        return 1;
    }
    printf("Enter the words :\n");
    for (int i = 0; i < n; i++)
    {
        words[i] = (char *)malloc(MAX * sizeof(char));
        if (words[i] == NULL) // malloc failed
        {
            printf("Malloc failed for word %d\n", i + 1);
            return 1;
        }
        scanf("%s", words[i]);
    }

    int d;
    printf("Enter the no. of positions to be left shifted by : ");
    scanf("%d", &d);

    printf("The original sentence is : ");
    printArray(words, n);
    leftShift(words, n, d);
    printf("The resultant sentence is : ");
    printArray(words, n);

    for (int i = 0; i < n; i++)
    {
        free(words[i]);
    }
    free(words);
    return 0;
}