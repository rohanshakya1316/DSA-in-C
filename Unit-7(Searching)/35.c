// Write a C program to sort data items using quick sort.
 
#include <stdio.h> 

void swap(int* a, int* b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 

// Partition function 
int partition(int arr[], int low, int high) 
{ 

	// initialize pivot to be the first element 
	int pivot = arr[low]; 
	int i = low; 
	int j = high; 

	while (i < j) { 

		// condition 1: find the first element greater than 
		// the pivot (from starting) 
		while (arr[i] <= pivot && i <= high - 1) { 
			i++; 
		} 

		// condition 2: find the first element smaller than 
		// the pivot (from last) 
		while (arr[j] > pivot && j >= low + 1) { 
			j--; 
		} 
		if (i < j) { 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[low], &arr[j]); 
	return j; 
} 

// QuickSort function 
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) { 

		// call Partition function to find Partition Index 
		int partitionIndex = partition(arr, low, high); 

		// Recursively call quickSort() for left and right 
		// half based on partition Index 
		quickSort(arr, low, partitionIndex - 1); 
		quickSort(arr, partitionIndex + 1, high); 
	} 
} 

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
void main() 
{ 
	int size;
    printf("Enter total elements of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements of the array: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
	printf("Before Sorting: \n");
    displayArray(arr, size);
	 

	// calling quickSort() to sort the given array 
	quickSort(arr, 0, size - 1); 

	// printing the sorted array 
	printf("After Sorting:\n"); 
	displayArray(arr, size);
}
