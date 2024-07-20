// Write a C program to print array element using recursive function.
#include<stdio.h>
#define N 100

void displayArray(int, int, int []);

void main(){
    int arr[N], n;
    printf("Enter total elements of array: ");
    scanf("%d", &n);
    printf("Enter %d elements of array: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Now displaying the array elements: \n");
    displayArray(n, 0, arr);
}

void displayArray(int size, int index, int array[size]){
    if (index == size)
    {
        return;
    }
    printf("Array element in index [%d] is %d.\n", index, array[index]);
    displayArray(size, index + 1, array);
    
}


// void displayArray(int n, int array[n]){
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d  ", array[i]);
//     }
    
// }
