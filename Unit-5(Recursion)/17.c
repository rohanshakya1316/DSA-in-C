// Write a C program that finds the product of two numbers using recursive function.
#include<stdio.h>

int product(int n1, int n2){
    if(n2 == 0){        // Base Condition
        return 0;
    }
    if (n2 > 0)         
    {
        return n1 + product(n1, n2 - 1); // Recursive fxn for +ve n2.
    }
    if (n2 < 0)
    {
        return - product(n1, -n2); // Recursive fxn for -ve n2.
    }
}

// int product(int n1, int n2){
//     if (n2 == 1) // Base Condition
//     {
//         return n1;
//     }
//     else
//         return n1 + product(n1, n2 - 1);  // recursive function
// } 

// int product(int n1, int n2){
//     if (n1 < n2) // Base Condition
//     {
//         return product(n2, n1);
//     }
//     else if(n2 != 0){
//         return n1 + product(n1, n2 - 1);  // recursive function
//     }
//     else if(n2 < 0){
//         return -product(n1, n2-1);
//     }
//         return 0;
// } 
void main(){
    int num1, num2, result = 0;
    printf("Enter any two numbers: ");
    scanf("%d %d", &num1, &num2);
    result = product(num1, num2);
    printf("The product of %d and %d is %d.", num1, num2, result);
}




// int product(int n1, int n2){  // while loop logic simple one.
//     int res = 0;
//     while (n1 != 0)
//     {
//         res += n2;
//         n1--;
//     }
//     return res;
// } 

