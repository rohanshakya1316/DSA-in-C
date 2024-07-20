// Write a C program to sort data items using insertion sort.
#include<stdio.h>
void displayArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    
}

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
    displayArray(arr, size);
}

void main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements of array: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Array before sorting: \n");
    displayArray(arr, n);
    printf("\n");
    printf("Array after sorting: \n");
    insertionSort(arr, n);
}