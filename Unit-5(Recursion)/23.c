// Write a C program to search an element in an array using binary search. Use recursive function.
#include <stdio.h>

// Function prototype
int binarySearch(int arr[], int left, int right, int element);

void main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Example sorted array
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int search; // Element to search for
    printf("Enter the element to be searched: ");
    scanf("%d", &search);

    // Call the recursive function to search for the element
    int flag = binarySearch(arr, 0, size - 1, search);

    // Check if the element was found and print the result
    if (flag != -1) {
        printf("Element %d found at index %d.\n", search, flag);
    } 
    else {
        printf("Element %d not found in the array.\n", search);
    }
}

// Recursive function to perform binary search
int binarySearch(int arr[], int left, int right, int search) 
{
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the searching element is present at the middle
        if (arr[mid] == search) {
            return mid;
        }
        // If the searching element is smaller than mid, it can only be present in the left subarray
        if (arr[mid] > search) {
            return binarySearch(arr, left, mid - 1, search);
        }
        // Otherwise, the searching element can only be present in the right subarray
        else
        {
            return binarySearch(arr, mid + 1, right, search);
        }  
    }
    // If the element is not present in the array
    return -1;
}
