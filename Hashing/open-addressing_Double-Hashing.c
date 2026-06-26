#include <stdio.h>

#define SIZE 10

int table[SIZE];

void initialize() {
    for(int i = 0; i < SIZE; i++)
        table[i] = -1;
}

int hash1(int key) {
    return key % SIZE;
}

int hash2(int key) {
    return 7 - (key % 7);
}

void insert(int key) {

    int index = hash1(key);
    int step = hash2(key);

    while(table[index] != -1)
        index = (index + step) % SIZE;

    table[index] = key;
}

void search(int key) {

    int index = hash1(key);
    int step = hash2(key);
    int start = index;

    while(table[index] != -1) {

        if(table[index] == key) {
            printf("Key found at index %d\n", index);
            return;
        }

        index = (index + step) % SIZE;

        if(index == start)
            break;
    }

    printf("Key not found\n");
}

void display() {

    printf("\nHash Table\n");

    for(int i = 0; i < SIZE; i++) {
        if(table[i] == -1)
            printf("%d : Empty\n", i);
        else
            printf("%d : %d\n", i, table[i]);
    }
}

int main() {

    initialize();

    insert(25);
    insert(35);
    insert(45);
    insert(55);

    display();

    search(35);

    return 0;
}