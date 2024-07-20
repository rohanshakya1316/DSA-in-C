// Write a C program to sort data items using shell sort.

#include<stdio.h>

void shellSort(int arr[], int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i += 1)
        {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }   
            arr[j] = temp;
        }   
    }   
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void main(){
    int size;
    printf("Enter total elements of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements of the array: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Before sorting:\n");
    displayArray(arr, size);

    shellSort(arr, size);
    
    printf("After sorting:\n");
    displayArray(arr, size);
}


// // C++ implementation of Shell Sort
// #include  <iostream>
// using namespace std;
 
// /* function to sort arr using shellSort */
// int shellSort(int arr[], int n)
// {
//     // Start with a big gap, then reduce the gap
//     for (int gap = n/2; gap > 0; gap /= 2)
//     {
//         // Do a gapped insertion sort for this gap size.
//         // The first gap elements a[0..gap-1] are already in gapped order
//         // keep adding one more element until the entire array is
//         // gap sorted 
//         for (int i = gap; i < n; i += 1)
//         {
//             // add a[i] to the elements that have been gap sorted
//             // save a[i] in temp and make a hole at position i
//             int temp = arr[i];
 
//             // shift earlier gap-sorted elements up until the correct 
//             // location for a[i] is found
//             int j;            
//             for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
//                 arr[j] = arr[j - gap];
             
//             //  put temp (the original a[i]) in its correct location
//             arr[j] = temp;
//         }
//     }
//     return 0;
// }
 
// void printArray(int arr[], int n)
// {
//     for (int i=0; i<n; i++)
//         cout << arr[i] << " ";
// }
 
// int main()
// {
//     int arr[] = {12, 34, 54, 2, 3}, i;
//     int n = sizeof(arr)/sizeof(arr[0]);
 
//     cout << "Array before sorting: \n";
//     printArray(arr, n);
 
//     shellSort(arr, n);
 
//     cout << "\nArray after sorting: \n";
//     printArray(arr, n);
 
//     return 0;
// }



// #include <stdio.h>    
// /* function to implement shellSort */  
// int shell(int a[], int n)  
// {  
//     /* Rearrange the array elements at n/2, n/4, ..., 1 intervals */  
//     for (int interval = n/2; interval > 0; interval /= 2)  
//     {  
//         for (int i = interval; i < n; i += 1)  
//         {  
//             /* store a[i] to the variable temp and make the ith position empty */  
//             int temp = a[i];  
//             int j;        
//             for (j = i; j >= interval && a[j - interval] > temp; j -= interval)  
//                 a[j] = a[j - interval];  
              
//             // put temp (the original a[i]) in its correct position  
//             a[j] = temp;  
//         }  
//     }  
//     return 0;  
// }  
// void printArr(int a[], int n) /* function to print the array elements */  
// {  
//     int i;  
//     for (i = 0; i < n; i++)  
//         printf("%d ", a[i]);  
// }    
// int main()  
// {  
//     int a[] = { 33, 31, 40, 8, 12, 17, 25, 42 };  
//     int n = sizeof(a) / sizeof(a[0]);  
//     printf("Before sorting array elements are - \n");  
//     printArr(a, n);  
//     shell(a, n);  
//     printf("\nAfter applying shell sort, the array elements are - \n");    
//     printArr(a, n);  
//     return 0;  
// }  
