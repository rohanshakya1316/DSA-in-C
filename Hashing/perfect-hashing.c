// Perfect Hashing Method with Insertion and Searching

// * Note: Perfect hashing only works in this simple form when keys are unique and fall within the table's valid index range.

#include <stdio.h>

#define SIZE 100

int table[SIZE];

void initialize() {
    for(int i = 0; i < SIZE; i++)
        table[i] = -1;
}

void insert(int key) {
    table[key] = key;
}

void search(int key) {

    if(table[key] == key)
        printf("Key found at index %d\n", key);
    else
        printf("Key not found\n");
}

int main() {

    initialize();

    insert(10);
    insert(20);
    insert(35);

    search(20);

    return 0;
}