// Write a C program that finds sum of first 100 natural numbers using recursive function.
#include<stdio.h>

int sum(int);

void main() {
    int n = 100, result = 0;
    result = sum(n);
    printf("Sum of first 100 natural numbers is %d.", result);

}

int sum(int num){
    if (num == 1) // Base Condition
    {
        return 1;
    }
    else{
        return num + sum(num - 1); // Recursive fxn 
    }
}