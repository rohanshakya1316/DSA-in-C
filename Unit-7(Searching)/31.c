// Write a C program to sort data items using bubble sort.

#include<stdio.h>
void displayArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    
}

void bubbleSort(int arr[], int size){
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            
        }
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
    bubbleSort(arr, n);
}