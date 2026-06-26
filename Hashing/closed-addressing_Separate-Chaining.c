#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node *next;
};

struct Node *table[SIZE];

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {

    int index = hash(key);

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = key;
    newNode->next = table[index];

    table[index] = newNode;
}

void search(int key) {

    int index = hash(key);

    struct Node *temp = table[index];

    while(temp != NULL) {

        if(temp->data == key) {
            printf("Key found\n");
            return;
        }

        temp = temp->next;
    }

    printf("Key not found\n");
}

void display() {

    printf("\nHash Table\n");

    for(int i = 0; i < SIZE; i++) {

        printf("%d : ", i);

        struct Node *temp = table[i];

        while(temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main() {

    for(int i = 0; i < SIZE; i++)
        table[i] = NULL;

    insert(25);
    insert(35);
    insert(45);
    insert(55);

    display();

    search(45);

    return 0;
}