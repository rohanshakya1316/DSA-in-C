// * Cryptographic-style hash (DJB2 — classic string hash)

// * Real crypto: use OpenSSL or libsodium for SHA/MD5

/* 
* How it works
? 1. Hash Function: djb2_hash() converts a string into a numeric hash value.

? 2. Insertion: The hash value determines the index. If the slot is occupied, linear probing (index = (index + 1) % SIZE) finds the next empty slot.

? 3. Searching: Starts from the hashed index and uses the same linear probing sequence until the string is found or an empty slot/full cycle is reached.

*/

#include <stdio.h>
#include <string.h>

#define SIZE 10

char table[SIZE][50];

// DJB2 Hash Function
unsigned long djb2_hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;   // hash * 33 + c
    }

    return hash % SIZE;
}

// Initialize hash table
void initialize() {
    int i;
    for(i = 0; i < SIZE; i++) {
        strcpy(table[i], "");
    }
}

// Insert a string
void insert(char str[]) {
    int index = djb2_hash(str);

    while(strcmp(table[index], "") != 0) {
        index = (index + 1) % SIZE;   // Linear Probing
    }

    strcpy(table[index], str);
}

// Search for a string
void search(char str[]) {
    int index = djb2_hash(str);
    int start = index;

    while(strcmp(table[index], "") != 0) {

        if(strcmp(table[index], str) == 0) {
            printf("\n'%s' found at index %d\n", str, index);
            return;
        }

        index = (index + 1) % SIZE;

        if(index == start)
            break;
    }

    printf("\n'%s' not found.\n", str);
}

// Display hash table
void display() {
    int i;

    printf("\nHash Table\n");
    printf("-----------------\n");

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
    char word[50];
    char searchWord[50];

    initialize();

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter strings:\n");

    for(i = 0; i < n; i++) {
        scanf("%s", word);
        insert(word);
    }

    display();

    printf("\nEnter string to search: ");
    scanf("%s", searchWord);

    search(searchWord);

    return 0;
}