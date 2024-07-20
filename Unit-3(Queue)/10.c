// Write a C program to implement linear queue with enQueue(), deQueue(), peek(), isFull() and isEmpty() operations.
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  // Define the size of the queue

// Define the queue structure
typedef struct {
    int items[SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Function to check if the queue is full
int isFull(Queue *q) {
    return q->rear == SIZE - 1;
}

// Function to add an element to the queue
void enQueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted %d\n", value);
    }
}

// Function to remove an element from the queue
int deQueue(Queue *q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            // Reset the queue
            q->front = q->rear = -1;
        }
        return item;
    }
}

// Function to get the front element of the queue
int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        return q->items[q->front];
    }
}

// Main function to test the queue operations
void main() {
    Queue q;
    initializeQueue(&q);

    enQueue(&q, 100);
    enQueue(&q, 200);
    enQueue(&q, 300);
    enQueue(&q, 400);
    enQueue(&q, 500);

    printf("Front element is %d\n", peek(&q));

    printf("Removed %d from the queue\n", deQueue(&q));
    printf("Removed %d from the queue\n", deQueue(&q));
    
    enQueue(&q, 600);

    while (!isEmpty(&q)) {
        printf("Removed %d from the queue\n", deQueue(&q));
    }
}
