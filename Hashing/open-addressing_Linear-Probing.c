/* | Collision Resolution Technique   | Collision Handling                                              |
| -------------------------------- | --------------------------------------------------------------- |
| **Linear Probing**               | Check the next slot (`index + 1`) until an empty slot is found. |
| **Quadratic Probing**            | Check slots using square increments (`index + i²`).             |
| **Double Hashing**               | Use a second hash function as the step size (`index + step`).   |
| **Closed Addressing (Chaining)** | Store colliding keys in a linked list at the same index.        |
*/

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

    while(table[index] != -1)
        index = (index + 1) % SIZE;

    table[index] = key;
}

void search(int key) {
    int index = hash(key);
    int start = index;

    while(table[index] != -1) {
        if(table[index] == key) {
            printf("Key found at index %d\n", index);
            return;
        }

        index = (index + 1) % SIZE;

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

    search(45);

    return 0;
}