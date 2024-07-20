// Write a C program to implement linear search by using non-recursive function.
#include<stdio.h>

void inputArray(int arr[], int size){
    printf("Enter %d elements of the array: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int linearSearch(int arr[], int size, int search){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == search)
        {
            return i;
        }
    }
    return -1;
}

void main(){
    int n, flag;
    printf("Enter total element in the array: ");
    scanf("%d", &n);
    int arr[n], search;
    inputArray(arr, n);
   
    printf("Enter element to be searched in the array: ");
    scanf("%d", &search);

    flag = linearSearch(arr, n, search);

    if (flag != -1)
    {
        printf("Element %d is found in index %d.\n", search, flag);
    }
    else
    {
        printf("Element %d is not found in the array.\n", search);
    }
}