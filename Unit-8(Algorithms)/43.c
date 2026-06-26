// A C program to implement binary insertion sort.

#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int item, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (item == arr[mid])
            return mid + 1;
        else if (item > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

// Function for Binary Insertion Sort
void binaryInsertionSort(int arr[], int n)
{
    int i, j, key, pos;

    for (i = 1; i < n; i++)
    {
        key = arr[i];

        // Find insertion position using binary search
        pos = binarySearch(arr, key, 0, i - 1);

        // Shift elements to the right
        for (j = i - 1; j >= pos; j--)
        {
            arr[j + 1] = arr[j];
        }

        // Insert key at correct position
        arr[pos] = key;
    }
}

// Function to print array
void printArray(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int arr[] = {37, 23, 0, 17, 12, 72, 31};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    binaryInsertionSort(arr, n);

    printf("Sorted Array:\n");
    printArray(arr, n);

    return 0;
}