// Write a C program to solve Tower of Hanoi (TOH) problem using recursive function.
#include<stdio.h>

void towerOfHanoi(int, char, char, char);

void main(){
    int disk;
    printf("Enter numbers of disk in the tower: ");
    scanf("%d", &disk);

    towerOfHanoi(disk, 'A', 'B', 'C');

}

void towerOfHanoi(int n, char rodLeft, char rodMid, char rodRight){ // (n, A, B, C)
    if (n == 1)
    {
        printf("Disk moved from %c to %c.\n", rodLeft, rodRight);  //(A, C)
        return;
    }
    else{
        towerOfHanoi(n - 1, rodLeft, rodRight, rodMid);   // (n-1, A, C, B)
        towerOfHanoi(1, rodLeft, rodMid, rodRight);       // (1, A, B, C)
        towerOfHanoi(n - 1, rodMid, rodLeft, rodRight);   // (n-1, B, A, C)
    }
}