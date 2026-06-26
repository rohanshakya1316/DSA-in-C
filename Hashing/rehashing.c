// * Rehashing: creating a new, larger hash table when the current table becomes too full, then reinserting all existing keys into the new table using the new hash function (usually key % newSize).

#include <stdio.h>

#define INITIAL_SIZE 5
#define NEW_SIZE 10

int table[NEW_SIZE];

// Initialize hash table
void initialize() {
    for(int i = 0; i < NEW_SIZE; i++)
        table[i] = -1;
}

// Hash function
int hashFunction(int key, int size) {
    return key % size;
}

// Insert using Linear Probing
void insert(int key, int size) {
    int index = hashFunction(key, size);

    while(table[index] != -1) {
        index = (index + 1) % size;
    }

    table[index] = key;
}

// Display table
void display(int size) {
    printf("\nHash Table:\n");

    for(int i = 0; i < size; i++) {
        if(table[i] == -1)
            printf("%d : Empty\n", i);
        else
            printf("%d : %d\n", i, table[i]);
    }
}

int main() {

    int oldTable[INITIAL_SIZE] = {12, 7, 22, 15, -1};

    initialize();

    printf("Old Hash Table:\n");

    for(int i = 0; i < INITIAL_SIZE; i++) {
        if(oldTable[i] == -1)
            printf("%d : Empty\n", i);
        else
            printf("%d : %d\n", i, oldTable[i]);
    }

    printf("\nRehashing...\n");

    // Reinsert all keys into larger table
    for(int i = 0; i < INITIAL_SIZE; i++) {
        if(oldTable[i] != -1)
            insert(oldTable[i], NEW_SIZE);
    }

    display(NEW_SIZE);

    return 0;
}