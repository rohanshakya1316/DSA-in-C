// Hashing With Folding Method with Insertion and Searching


#include <stdio.h>

#define SIZE 100

int table[SIZE];

void initialize() {
    for(int i = 0; i < SIZE; i++)
        table[i] = -1;
}

int hashFunction(int key) {

    int sum = 0;

    while(key > 0) {
        sum += key % 1000;
        key /= 1000;
    }

    return sum % SIZE;
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

    insert(123456);
    insert(789654);

    search(123456);

    return 0;
}