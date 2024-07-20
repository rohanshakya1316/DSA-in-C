// Write a C program to prints n Fibonacci numbers using recursive funciton.
#include<stdio.h>

int fibo(int n){
    if (n <= 1)  // Base Condition
    {
        return n;
    }
    else{
        return fibo(n-1) + fibo(n-2); // Recursive fxn 
    }
    
}

void main(){
    int terms;
    printf("Enter number of terms: ");
    scanf("%d", &terms);
    for (int i = 0; i < terms; i++)
    {
        int series = fibo(i);
        printf("%d", series);
        if (i < terms - 1)  // Condition for comma(,) printing
        {
            printf(", ");
        }
        
    }
    
}
