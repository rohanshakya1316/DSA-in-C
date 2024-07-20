// Write a C program to find sum of digits of a number using recursive function.
#include<stdio.h>

int sumOfDigits(int n){
    if (n == 0)     // Base Condition
    {
        return 0;
    }
    else
    {
        return (n %10) + sumOfDigits(n / 10);   // Recursive funciton
    }
}

void main(){
    int num, sum = 0;
    printf("Enter any number to find sum of its digits: ");
    scanf("%d", &num);
    
    sum = sumOfDigits(num);

    printf("The sum of the digits of %d is %d.", num, sum);
}