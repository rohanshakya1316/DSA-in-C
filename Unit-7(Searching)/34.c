// Write a C program to sort data items using merge sort.

#include <stdio.h> 
#include <stdlib.h> 

void merge(int arr[], int left, int mid, int right) { 
	int i, j, k; 
	int n1 = mid - left + 1; 
	int n2 = right - mid; 
 
	int L[n1], R[n2];  // temporary arrays

	// Copy data to temp arrays 
	// L[] and R[] 
	for (i = 0; i < n1; i++) 
		L[i] = arr[left + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[mid + 1 + j]; 

	// Merge the temp arrays back 
	// into arr[l..r] 
	// Initial index of first subarray 
	i = 0; 

	// Initial index of second subarray 
	j = 0; 

	// Initial index of merged subarray 
	k = left; 
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			arr[k] = L[i]; 
			i++; 
		} 
		else { 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	// Copy the remaining elements 
	// of L[], if there are any 
	while (i < n1) { 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	// Copy the remaining elements of 
	// R[], if there are any 
	while (j < n2) { 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

// l is for left index and r is 
// right index of the sub-array 
// of arr to be sorted 
void mergeSort(int arr[], int l, int r){ 
	if (l < r) { 
		// Same as (l+r)/2, but avoids 
		// overflow for large l and r 
		int m = l + (r - l) / 2; 

		// Sort first and second halves 
		mergeSort(arr, l, m); 
		mergeSort(arr, m + 1, r); 

		merge(arr, l, m, r); 
	} 
} 

void displayArray(int arr[], int size) { 
	int i; 
	for (i = 0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

void main() { 
	int size;
    printf("Enter total elements of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements of the array: ", size);
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

	printf("Before Sorting:\n"); 
	displayArray(arr, size); 

	mergeSort(arr, 0, size - 1); 

	printf("After Sorting:\n"); 
	displayArray(arr, size); 
}
