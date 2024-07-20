// Write a C program to implement push and pop operation in stack using an array.
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

// Driver code
void main() {
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");

    int choice, value;
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
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
                display(sp);
                break;
            case 4:
                free(sp->arr);
                free(sp);
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }
}

