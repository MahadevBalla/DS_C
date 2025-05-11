#include <stdio.h>
int cnt = 0;

// Function to move disks from source to destination
void moveDisk(char from_rod, char to_rod, int disk) {
    cnt++;
    printf("Move disk %d from rod %c to rod %c\n", disk, from_rod, to_rod);
}

// Recursive function to solve Towers of Hanoi
void towersOfHanoi(int n, char source_rod, char destination_rod, char auxiliary_rod) {
    if (n == 1) {
        moveDisk(source_rod, destination_rod, n);
        return;
    }
    
    // Move n-1 disks from source to auxiliary rod
    towersOfHanoi(n - 1, source_rod, auxiliary_rod, destination_rod);
    
    // Move the nth disk from source to destination rod
    moveDisk(source_rod, destination_rod, n);
    
    // Move the n-1 disks from auxiliary to destination rod
    towersOfHanoi(n - 1, auxiliary_rod, destination_rod, source_rod);
}

int main() {
    int n; // Number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    // Function call to solve Towers of Hanoi
    towersOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    printf("Total no. of moves : %d", cnt);
    return 0;
}