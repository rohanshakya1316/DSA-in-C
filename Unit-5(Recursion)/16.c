// Write a C program that finds factorial of a number using recursive function.
#include<stdio.h>
int factorial(int n){
    if (n == 0)     // Base Condition
        return 1;
    else
        return n * factorial(n - 1); // Recursive function 
}
void main(){
    int num, fact;
    printf("Enter any number: ");
    scanf("%d", &num);
    fact = factorial(num);
    printf("The factorial of %d is %d.\n", num, fact);
}