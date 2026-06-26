// Universal Hashing Method with Insertion and Searching

#include <stdio.h>

#define SIZE 10

int table[SIZE];

int a = 3;
int b = 7;
int p = 101;

void initialize() {
    for(int i = 0; i < SIZE; i++)
        table[i] = -1;
}

int hashFunction(int key) {
    return ((a * key + b) % p) % SIZE;
}

void insert(int key) {

    int index = hashFunction(key);

    while(table[index] != -1)
        index = (index + 1) % SIZE;

    table[index] = key;
}

void search(int key) {

    int index = hashFunction(key);
    int start = index;

    while(table[index] != -1) {

        if(table[index] == key) {
            printf("Found at index %d\n", index);
            return;
        }

        index = (index + 1) % SIZE;

        if(index == start)
            break;
    }

    printf("Key not found\n");
}

int main() {

    initialize();

    insert(20);
    insert(40);
    insert(70);

    search(70);

    return 0;
}