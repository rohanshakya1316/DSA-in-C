/* Write a C program to create doubly circular linked list that perform following operations: 
 a. adds node at the beginning. 
 b. adds node at the end.
 c. adds node at the given position. 
 d. deletes node at the beginning. 
 e. deletes node at the end.
 f. deletes node at the given position. 
 g. traverses the list. 
 h. searches given data item in a list. 
 i. counts numbers of nodes in a list.
*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function prototypes
void addNodeAtBeginning(Node** head, int data);
void addNodeAtEnd(Node** head, int data);
void addNodeAtPosition(Node** head, int data, int position);
void deleteNodeAtBeginning(Node** head);
void deleteNodeAtEnd(Node** head);
void deleteNodeAtPosition(Node** head, int position);
void traverseList(Node* head);
int searchList(Node* head, int key);
int countNodes(Node* head);
void freeList(Node** head);

// Function to add a node at the beginning
void addNodeAtBeginning(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        Node* last = (*head)->prev;

        newNode->next = *head;
        newNode->prev = last;
        
        (*head)->prev = newNode;
        last->next = newNode;

        *head = newNode;
    }
}

// Function to add a node at the end
void addNodeAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        Node* last = (*head)->prev;

        newNode->next = *head;
        newNode->prev = last;

        (*head)->prev = newNode;
        last->next = newNode;
    }
}

// Function to add a node at a given position
void addNodeAtPosition(Node** head, int data, int position) {
    if (position < 1) {
        printf("Position should be >= 1.\n");
        return;
    }

    if (position == 1) {
        addNodeAtBeginning(head, data);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    Node* temp = *head;
    for (int i = 1; temp->next != *head && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp->next == *head && position != countNodes(*head) + 1) {
        printf("Position out of range.\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

// Function to delete a node at the beginning
void deleteNodeAtBeginning(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        Node* last = (*head)->prev;
        
        *head = temp->next;
        (*head)->prev = last;
        last->next = *head;

        free(temp);
    }
}

// Function to delete a node at the end
void deleteNodeAtEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;
    if (temp->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        Node* last = (*head)->prev;

        last->prev->next = *head;
        (*head)->prev = last->prev;

        free(last);
    }
}

// Function to delete a node at a given position
void deleteNodeAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position < 1) {
        printf("Position should be >= 1.\n");
        return;
    }

    if (position == 1) {
        deleteNodeAtBeginning(head);
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;
    for (int i = 1; temp->next != *head && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == *head && position != countNodes(*head)) {
        printf("Position out of range.\n");
    } else {
        prev->next = temp->next;
        temp->next->prev = prev;
        free(temp);
    }
}

// Function to traverse the list
void traverseList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Function to search the list for a key
int searchList(Node* head, int key) {
    if (head == NULL) {
        return -1; // Key not found
    }

    Node* temp = head;
    int position = 1;
    do {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    } while (temp != head);

    return -1; // Key not found
}

// Function to count the number of nodes in the list
int countNodes(Node* head) {
    if (head == NULL) {
        return 0;
    }

    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Function to free the entire list
void freeList(Node** head) {
    if (*head == NULL) {
        return;
    }

    Node* temp = *head;
    Node* next = NULL;
    do {
        next = temp->next;
        free(temp);
        temp = next;
    } while (temp != *head);
    *head = NULL;
}

// Main function to demonstrate the operations
void main() {
    Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add node at the beginning\n");
        printf("2. Add node at the end\n");
        printf("3. Add node at a given position\n");
        printf("4. Delete node at the beginning\n");
        printf("5. Delete node at the end\n");
        printf("6. Delete node at a given position\n");
        printf("7. Traverse the list\n");
        printf("8. Search the list\n");
        printf("9. Count the number of nodes\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addNodeAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                addNodeAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                addNodeAtPosition(&head, data, position);
                break;
            case 4:
                deleteNodeAtBeginning(&head);
                break;
            case 5:
                deleteNodeAtEnd(&head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteNodeAtPosition(&head, position);
                break;
            case 7:
                traverseList(head);
                break;
            case 8:
                printf("Enter key to search: ");
                scanf("%d", &data);
                position = searchList(head, data);
                if (position != -1) {
                    printf("Node found at position: %d\n", position);
                } else {
                    printf("Node not found.\n");
                }
                break;
            case 9:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 10:
                freeList(&head);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
