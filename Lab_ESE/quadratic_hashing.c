#include <stdio.h>
#include <stdlib.h>

int *hashTableQuadratic;

// Initializing
void initializeTable(int hashTable[], int size) {
    for (int i = 0; i < size; i++) {
        hashTable[i] = -1; // -1 means empty
    }
}

int hashFunction(int key, int size) { // h1(k)
    return key % size;
}

// Quadratic probing
void quadraticProbing(int key, int tableSize) {
    int index = hashFunction(key, tableSize);
    int i = 0;

    printf("Inserting %d using Quadratic Probing:\n", key);
    printf("h(%d) = %d %% %d = %d\n", key, key, tableSize, index);

    while (hashTableQuadratic[(index + i * i) % tableSize] != -1) {
        printf("Collision occurred at index %d.\n", (index + i * i) % tableSize);
        i++;
        printf("Probing %d step:\n", i);
        printf("Probing index = (h(%d) + %d^2) %% %d = (%d + %d^2) %% %d = %d\n",
               key, i, tableSize, index, i, tableSize, (index + i * i) % tableSize);
    }

    hashTableQuadratic[(index + i * i) % tableSize] = key;
    printf("Inserted %d at index %d after %d step(s).\n\n", key, (index + i * i) % tableSize, i + 1);
}

// Function to display the hash table
void displayHashTable(int hashTable[], int size, char *method) {
    printf("Hash Table using %s:\n", method);
    for (int i = 0; i < size; i++) {
        if (hashTable[i] == -1) {
            printf("[%d] --> Empty\n", i);
        } else {
            printf("[%d] --> %d\n", i, hashTable[i]);
        }
    }
    printf("\n");
}

int main() {
    int tableSize;
    printf("Enter the size of the hash table: ");
    scanf("%d", &tableSize);
    hashTableQuadratic = (int *)malloc(tableSize * sizeof(int)); // Allocate memory for quadratic probing table

    initializeTable(hashTableQuadratic, tableSize); // Initialize hash table for quadratic probing

    int n;
    printf("Enter the number of elements you want to insert: ");
    scanf("%d", &n);

    int *keys = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements (space-separated): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    // Insert keys using quadratic probing
    for (int i = 0; i < n; i++) {
        quadraticProbing(keys[i], tableSize);
    }

    // Display the hash table for quadratic probing
    displayHashTable(hashTableQuadratic, tableSize, "Quadratic Probing");
    

    return 0;
}
