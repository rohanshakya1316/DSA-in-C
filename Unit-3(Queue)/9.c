// Write a C program to implement enQueue and deQueue queue using an array.
#include<stdio.h>
#include<stdlib.h>
#define N 5 
int queue[N];
int front = -1;
int rear = -1;

void enQueue(int x) {
    if (rear == N - 1)
    {
        printf("Queue Overflow!");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear = rear + 1;
        queue[rear] = x;
    }
}

void deQueue() {
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("Deleted %d from queue.\n", queue[front]);
        front++;
    }
}

void peek() {
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty!");
    }
    else
    {
        printf("front data is %d. \n", queue[front]);
    }
}

void display() {
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty!");
    }
    else
    {
        for (int i = front; i < rear + 1; i++)
        {
            printf("queue index[%d] = %d \n", i, queue[i]);
        }
    }
}

void main() {
    int choice, value;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. enQueue\n");
        printf("2. deQueue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enQueue: ");
                scanf("%d", &value);1
                
                enQueue(value);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }
}

