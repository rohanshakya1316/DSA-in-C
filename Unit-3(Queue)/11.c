// Write a C program to implement priority queue using linked list.
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

// Function to create a new node
Node* newNode(int data, int priority) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

// Function to insert a node into the priority queue
void insert(Node** head, int data, int priority) {
    Node* start = *head;

    // Create new node
    Node* temp = newNode(data, priority);

    // Special case: The head of the list has lesser priority than new node
    if (*head == NULL || (*head)->priority > priority) {
        // Insert new node before the head
        temp->next = *head;
        *head = temp;
    } else {
        // Traverse the list and find a position to insert new node
        while (start->next != NULL && start->next->priority <= priority) {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

// Function to remove the node with the highest priority
void delete(Node** head) {
    if (*head == NULL) {
        printf("Priority queue is empty!\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    printf("Removed element with data %d and priority %d\n", temp->data, temp->priority);
    free(temp);
}

// Function to display the priority queue
void display(Node* head) {
    if (head == NULL) {
        printf("Priority queue is empty!\n");
        return;
    }
    printf("Priority Queue:\n");
    while (head != NULL) {
        printf("Data: %d, Priority: %d\n", head->data, head->priority);
        head = head->next;
    }
}

// Main function to test the priority queue operations
void main() {
    Node* pq = NULL;

    insert(&pq, 4, 1);
    insert(&pq, 5, 2);
    insert(&pq, 6, 0);
    insert(&pq, 7, 3);

    display(pq);

    delete(&pq);
    display(pq);

    delete(&pq);
    display(pq);
}
