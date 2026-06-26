// Hashing With Division Method with Insertion and Searching

#include <stdio.h>

#define SIZE 10

int table[SIZE];

void initialize() {
    for(int i = 0; i < SIZE; i++)
        table[i] = -1;
}

void insert(int key) {
    int index = key % SIZE;

    while(table[index] != -1)
        index = (index + 1) % SIZE;

    table[index] = key;
}

void search(int key) {
    int index = key % SIZE;
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
        printf("%d : ", i);

        if(table[i] == -1)
            printf("Empty");
        else
            printf("%d", table[i]);

        printf("\n");
    }
}

int main() {

    initialize();

    int n, key, choice;

    printf("How many keys? ");
    scanf("%d", &n);

    printf("Enter keys:\n");

    for(int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();

    printf("\nEnter key to search: ");
    scanf("%d", &key);

    search(key);

    return 0;
}