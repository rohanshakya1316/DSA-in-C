// Write a C program that reads n numbers and find their sum using dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
void main() 
{
    int n, *ptr, sum = 0;
    printf("Enter number of elements in an array: ");
    scanf("%d", &n);
    ptr = (int*) malloc(n * sizeof(int)); // Dynamic Memory Alloction
    if (ptr == NULL)
    {
        printf("Could not allocate the memory.");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", (ptr + i));
    }
    for (int i = 0; i < n; i++)
    {
        sum += *(ptr + i);
    }
    printf("Total Sum: %d", sum);
    free(ptr); // Deallocating memory
}

// #include <stdio.h>
// #include <stdlib.h>
// // To add n numbers.
// void main() {
//   int n, i, *ptr, sum = 0;
//   printf("Enter number of elements: ");
//   scanf("%d", &n);
//   ptr = (int*) malloc(n * sizeof(int));
//    // if memory cannot be allocated
//   if(ptr == NULL) {
//     printf("Error! memory not allocated.");
//     exit(0);
//   }
//   printf("Enter elements: ");
//   for(i = 0; i < n; ++i) {
//     scanf("%d", ptr + i);
//     sum += *(ptr + i);
//   }
//   printf("Sum = %d", sum);
//     // deallocating the memory
//   free(ptr);
// }