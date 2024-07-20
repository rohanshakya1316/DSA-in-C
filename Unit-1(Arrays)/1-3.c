// Write a C program that inserts an elements into array.
#include<stdio.h>
void main()
{
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    int arr[n], pos, new;
    for (int i = 0; i < n; i++)
    {
        printf("Enter element at position %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter position of element to be inserted:");
    scanf("%d", &pos);
    printf("Enter new element to be inserted: ");
    scanf("%d", &new);
    for (int i = n - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = new;
    n++;
    printf("Array after inserting the element: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    } 
}