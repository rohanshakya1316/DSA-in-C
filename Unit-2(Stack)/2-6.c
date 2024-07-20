// Write a C program to convert infix expression into prefix expression.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to return precedence of operators
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to return associativity of operators
char associativity(char c) {
    if (c == '^')
        return 'R';
    return 'L'; // Default to left-associative
}

// Function to reverse a string
void reverse(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

// The main function to convert infix expression to prefix expression
void infixToPrefix(char s[]) {
    char result[1000];
    int resultIndex = 0;
    int len = strlen(s);
    char stack[1000];
    int stackIndex = -1;

    // Reverse the infix expression
    reverse(s);

    for (int i = 0; i < len; i++) {
        char c = s[i];

        // If the scanned character is an operand, add it to the output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result[resultIndex++] = c;
        }
        // If the scanned character is an ')', push it to the stack.
        else if (c == ')') {
            stack[++stackIndex] = c;
        }
        // If the scanned character is an '(', pop and add to the output string from the stack
        // until an ')' is encountered.
        else if (c == '(') {
            while (stackIndex >= 0 && stack[stackIndex] != ')') {
                result[resultIndex++] = stack[stackIndex--];
            }
            stackIndex--; // Pop ')'
        }
        // If an operator is scanned
        else {
            while (stackIndex >= 0 && (prec(s[i]) < prec(stack[stackIndex]) ||
                                       (prec(s[i]) == prec(stack[stackIndex]) &&
                                        associativity(s[i]) == 'R'))) {
                result[resultIndex++] = stack[stackIndex--];
            }
            stack[++stackIndex] = c;
        }
    }

    // Pop all the remaining elements from the stack
    while (stackIndex >= 0) {
        result[resultIndex++] = stack[stackIndex--];
    }

    result[resultIndex] = '\0';

    // Reverse the result to get the prefix expression
    reverse(result);

    printf("%s\n", result);
}

// Driver code
void main() {
    char exp[1000];
    printf("Enter infix expression: ");
    scanf("%s", exp);
    
    // Function call
    infixToPrefix(exp);
}
