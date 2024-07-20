// Write a C program to sort data items using selection sort.
#include<stdio.h>
void displayArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    
}

void selectionSort(int arr[], int size){
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1 ; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
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
    selectionSort(arr, n);
}