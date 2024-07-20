// Write a C program to implement hashing.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Define the structure for the nodes in the linked list
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

// Define the structure for the hash table
typedef struct HashTable {
    Node* table[TABLE_SIZE];
} HashTable;

// Function to create a new node
Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Hash function to map keys to table indices
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to initialize the hash table
HashTable* createTable() {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

// Function to insert a key-value pair into the hash table
void insert(HashTable* hashTable, int key, int value) {
    int index = hashFunction(key);
    Node* newNode = createNode(key, value);

    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newNode;
    } else {
        Node* temp = hashTable->table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted (%d, %d) into hash table.\n", key, value);
}

// Function to search for a value by key in the hash table
int search(HashTable* hashTable, int key) {
    int index = hashFunction(key);
    Node* temp = hashTable->table[index];
    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1; // Key not found
}

// Function to delete a key-value pair from the hash table
void delete(HashTable* hashTable, int key) {
    int index = hashFunction(key);
    Node* temp = hashTable->table[index];
    Node* prev = NULL;

    while (temp != NULL && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key %d not found in hash table.\n", key);
        return;
    }

    if (prev == NULL) {
        hashTable->table[index] = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Deleted key %d from hash table.\n", key);
}

// Function to print the hash table
void printTable(HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = hashTable->table[i];
        while (temp != NULL) {
            printf("(%d, %d) -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function
void main() {
    HashTable* hashTable = createTable();

    insert(hashTable, 1, 10);
    insert(hashTable, 2, 20);
    insert(hashTable, 12, 30);
    insert(hashTable, 22, 40);

    printf("Hash Table:\n");
    printTable(hashTable);

    int value = search(hashTable, 12);
    if (value != -1) {
        printf("Value for key 12 is %d\n", value);
    } else {
        printf("Key 12 not found in hash table\n");
    }

    delete(hashTable, 12);
    printf("Hash Table after deletion:\n");
    printTable(hashTable);
}
