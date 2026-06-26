#include <stdio.h>

#define SIZE 10

int table[SIZE];

void initialize() {
    for(int i = 0; i < SIZE; i++)
        table[i] = -1;
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {

    int index = hash(key);
    int i = 1;

    while(table[index] != -1) {
        index = (hash(key) + i * i) % SIZE;
        i++;
    }

    table[index] = key;
}

void search(int key) {

    int index = hash(key);
    int i = 1;

    while(table[index] != -1) {

        if(table[index] == key) {
            printf("Key found at index %d\n", index);
            return;
        }

        index = (hash(key) + i * i) % SIZE;
        i++;

        if(i == SIZE)
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

    search(55);

    return 0;
}