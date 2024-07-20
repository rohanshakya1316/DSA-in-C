// Write a C program to implement push(), pop(), peek(), isFull(), isEmpty() operations in stack.
#include <stdio.h>
#include <stdlib.h>

// Stack structure
struct stack {
    int size;
    int top;
    int *arr;
};

// Function to check if the stack is empty
int isEmpty(struct stack* ptr) {
    return ptr->top == -1;
}

// Function to check if the stack is full
int isFull(struct stack* ptr) {
    return ptr->top == ptr->size - 1;
}

// Function to push an element onto the stack
void push(struct stack* ptr, int val) {
    if (isFull(ptr)) {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    } else {
        ptr->arr[++ptr->top] = val;
        printf("%d pushed to stack\n", val);
    }
}

// Function to pop an element from the stack
int pop(struct stack* ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    } else {
        return ptr->arr[ptr->top--];
    }
}

// Function to peek at the top element of the stack without popping it
int peek(struct stack* ptr) {
    if (isEmpty(ptr)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return ptr->arr[ptr->top];
    }
}

// Function to display the elements of the stack
void display(struct stack* ptr) {
    if (isEmpty(ptr)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = ptr->top; i >= 0; i--) {
            printf("%d\n", ptr->arr[i]);
        }
    }
}

// Function to free the allocated memory for the stack
void freeStack(struct stack* ptr) {
    free(ptr->arr);
    free(ptr);
}

void main() {
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 1;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");

    int choice, value;
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(sp, value);
                break;
            case 2:
                value = pop(sp);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek(sp);
                if (value != -1) {
                    printf("Top value: %d\n", value);
                }
                break;
            case 4:
                display(sp);
                break;
            case 5:
                freeStack(sp);
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }
}
