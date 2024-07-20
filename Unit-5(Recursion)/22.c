// Write a C program to search an element in an array using linear search. Use recursive function.
#include<stdio.h>

int linearSearch(int, int, int []);


void main(){
    int n, searchItem, flag = 0;
    printf("Enter total elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to be searched: ");
    scanf("%d", &searchItem);
    flag = linearSearch(searchItem, n - 1, arr);
    if (flag == -1)
    {
        printf("Element not found!");
    }
    else{
        printf("Element found in index [%d] and it is %d.\n", flag, searchItem);
        
    }
    
}

int linearSearch(int item, int size, int arr[size]){
    if (size < 0)
    {
        return -1;
    }
    if(arr[size] == item){
        return size;
    }
    linearSearch(item, size - 1, arr);
    

}