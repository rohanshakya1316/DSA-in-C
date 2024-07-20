// Write a C program that deletes an element from array.
#include<stdio.h>
void main()
{
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    int arr[n], pos;
    for (int i = 0; i < n; i++)
    {
        printf("Enter element at position %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter position of element to be deleted:");
    scanf("%d", &pos);
    for (int i = pos; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("Array after deletion of the element: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    } 
}