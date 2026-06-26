// Hashing With Multiplication Method with Insertion and Searching

#include <stdio.h>

#define SIZE 10

int table[SIZE];

float A = 0.618033;

void initialize() {
    for(int i = 0; i < SIZE; i++)
        table[i] = -1;
}

int hashFunction(int key) {
    float temp = key * A;
    temp = temp - (int)temp;
    return (int)(SIZE * temp);
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
    for(int i = 0; i < SIZE; i++) {
        if(table[i] == -1)
            printf("%d : Empty\n", i);
        else
            printf("%d : %d\n", i, table[i]);
    }
}

int main() {

    initialize();

    int n, key;

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