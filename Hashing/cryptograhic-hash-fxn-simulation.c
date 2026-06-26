// * Hash function: adds the ASCII values of all characters in the string, computes: index = sum % SIZE

#include <stdio.h>
#include <string.h>

#define SIZE 10

char table[SIZE][50];

// Initialize the hash table
void initialize() {
    int i;
    for(i = 0; i < SIZE; i++) {
        strcpy(table[i], "");
    }
}

// Simple hash function (sum of ASCII values)
int hashFunction(char str[]) {
    int sum = 0;
    int i;

    for(i = 0; str[i] != '\0'; i++) {
        sum += str[i];
    }

    return sum % SIZE;
}

// Insert a string into the hash table
void insert(char str[]) {
    int index = hashFunction(str);

    while(strcmp(table[index], "") != 0) {
        index = (index + 1) % SIZE;
    }

    strcpy(table[index], str);
}

// Search for a string
void search(char str[]) {
    int index = hashFunction(str);
    int start = index;

    while(strcmp(table[index], "") != 0) {

        if(strcmp(table[index], str) == 0) {
            printf("'%s' found at index %d\n", str, index);
            return;
        }

        index = (index + 1) % SIZE;

        if(index == start)
            break;
    }

    printf("'%s' not found.\n", str);
}

// Display the hash table
void display() {
    int i;

    printf("\nHash Table\n");
    printf("---------------------\n");

    for(i = 0; i < SIZE; i++) {
        printf("%d : ", i);

        if(strcmp(table[i], "") == 0)
            printf("Empty");
        else
            printf("%s", table[i]);

        printf("\n");
    }
}

int main() {

    int n, i;
    char key[50];
    char searchKey[50];

    initialize();

    printf("How many strings do you want to insert? ");
    scanf("%d", &n);

    printf("Enter the strings:\n");

    for(i = 0; i < n; i++) {
        scanf("%s", key);
        insert(key);
    }

    display();

    printf("\nEnter string to search: ");
    scanf("%s", searchKey);

    search(searchKey);

    return 0;
}