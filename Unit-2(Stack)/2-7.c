// Write a C program to evaluate postfix expression.
// C program to evaluate value of a postfix expression

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Stack structure
typedef struct {
    int top;
    int items[100];
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == 99;
}

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->items[++s->top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* exp) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        // If the character is a digit, convert it to integer and push onto stack
        if (isdigit(c)) {
            push(&stack, c - '0');
        } 
        // If the character is an operator, pop two elements from the stack, apply the operator and push the result back onto the stack
        else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            switch (c) {
                case '+':
                    push(&stack, val1 + val2);
                    break;
                case '-':
                    push(&stack, val1 - val2);
                    break;
                case '*':
                    push(&stack, val1 * val2);
                    break;
                case '/':
                    push(&stack, val1 / val2);
                    break;
            }
        }
    }

    // The final result will be at the top of the stack
    return pop(&stack);
}

// Driver code
void main() {
    char exp[100];
    
    printf("Enter postfix expression: ");
    scanf("%s", exp);
    
    printf("Result of postfix evaluation: %d\n", evaluatePostfix(exp));
}
