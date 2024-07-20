// Write a C program to implement binary search by using non-recursive function.
#include <stdio.h>

void inputArray(int arr[], int size){
    printf("Enter %d elements of the array: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void displaySortedArray(int arr[], int size){
    printf("First sorting the array for binary search as:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }  
    printf("\n");  
}

// Insertion Sorting
void insertionSort(int arr[], int size){
    int temp, i, j;
    for (i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i - 1;
         /* Move elements of arr[0..i-1], 
           that are greater than temp, 
           to one position ahead of 
           their current position */
        while(temp < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;      
    }
    displaySortedArray(arr, size);
}

int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high) 
    {
        int mid = (low + high) / 2;

        // Check if x is present at mid of the array
        if (arr[mid] == x)
            return mid;

        // If x is greater, ignore left half of the array
        if (arr[mid] < x)
            low = mid + 1;

        // If x is smaller, ignore right half of the array
        else
            high = mid - 1;
    }

    // If reach here, then element was not present
    return -1;
}

void main()
{

    int n, flag;
    printf("Enter total element in the array: ");
    scanf("%d", &n);
    int arr[n], search;

    inputArray(arr, n); // Taking inputs for the array.

    insertionSort(arr, n); // Sorting the array first.

    printf("Enter element to be searched in the array: ");
    scanf("%d", &search);

    flag = binarySearch(arr, 0, n - 1, search); // low = 0th index, high = (n - 1)th index in array

    if (flag != -1)
    {
        printf("Element %d is found in index %d.\n", search, flag);
    }
    else
    {
        printf("Element %d is not found in the array.\n", search);
    }
}
