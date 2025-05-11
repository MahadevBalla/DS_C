#include <stdio.h>
#include <stdlib.h>

#define HASH_TABLE_SIZE 1000

typedef struct HashNode {
    int value;
    int index;
    struct HashNode* next;
} HashNode;

HashNode* hashTable[HASH_TABLE_SIZE];

HashNode* createNode(int value, int index) {
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->value = value;
    newNode->index = index;
    newNode->next = NULL;
    return newNode;
}

int hashFunction(int value) {
    return abs(value) % HASH_TABLE_SIZE;
}

void insert(int value, int index) {
    int hashIndex = hashFunction(value);
    HashNode* newNode = createNode(value, index);
    newNode->next = hashTable[hashIndex];
    hashTable[hashIndex] = newNode;
}

int search(int value) {
    int hashIndex = hashFunction(value);
    HashNode* current = hashTable[hashIndex];
    while (current != NULL) {
        if (current->value == value) {
            return current->index;
        }
        current = current->next;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target) {
    int* result = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int index = search(complement);
        if (index != -1) {
            result[0] = index;
            result[1] = i;
            return result;
        }
        insert(nums[i], i);
    }
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int* result = twoSum(nums, numsSize, target);
    if (result != NULL) {
        printf("Indices: %d, %d\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}