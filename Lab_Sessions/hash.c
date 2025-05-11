#include<stdio.h>
#include<stdlib.h>

// #define hashSize 10 //for linear and quadratic
#define hashSize 19 //for double hashing

typedef struct hashNode{
    int index;
    char status;
    int val;
}hashNode;

hashNode *hashTable[hashSize] = {NULL};

hashNode *createNode(int index, char status, int val){
    hashNode *new = (hashNode *)malloc(sizeof(hashNode));
    new->index = index;
    new->status = status;
    new->val = val;
    return new;
}

int h(int k){
    return k % hashSize;
}

int linearProbing(int val){
    int idx = h(val);
    while(hashTable[idx] != NULL && hashTable[idx]->status != 'E'){
        if(hashTable[idx]->status == 'D'){
            return idx;
        }
        idx = (idx + 1) % hashSize;
    }
    return idx;
}

int quadraticProbing(int val){
    int idx = h(val);
    int i=1;
    while(hashTable[idx] != NULL && hashTable[idx]->status != 'E'){
        if(hashTable[idx]->status == 'D'){
            return idx;
        }
        idx = (h(val) + (i*i)) % hashSize;
        i++;
    }
    return idx;
}

int h2(int k) {
    return k % hashSize;
}

int g(int k) {
    return 7 - (k % 7);
}

int doubleHashing(int val){
    int idx = h2(val);
    int i=1;
    while(hashTable[idx] != NULL && hashTable[idx]->status != 'E'){
        if(hashTable[idx]->status == 'D'){
            return idx;
        }
        idx = (h(val) + (i*g(val))) % hashSize;
        i++;
    }
    return idx;
}

void insert(int val, int x){
    int idx;
    switch(x){
        case 1:
            idx = linearProbing(val);
            break;

        case 2:
            idx = quadraticProbing(val);
            break;

        case 3:
            idx = doubleHashing(val);
            break;

        default:
            printf("Invalid..");
            return;
    }

    if(hashTable[idx] == NULL || hashTable[idx]->status == 'E'){
        hashTable[idx] = createNode(idx, 'O', val);
    }
    else if(hashTable[idx]->status == 'D'){
        hashTable[idx]->val = val;
        hashTable[idx]->status = 'O';
    }
}

void printHash(hashNode **hashTable){
    for(int i=0; i<hashSize; i++){
        if(hashTable[i] == NULL || hashTable[i]->status == 'E'){
            printf("Loc %d : -1\n", i);
        }
        else{
            printf("Loc %d : %d\n", i, hashTable[i]->val);
        }
    }
}

void freeHash(){
    for(int i=0; i<hashSize; i++){
        if(hashTable[i]!=NULL){
            free(hashTable[i]);
            hashTable[i] = NULL;
        }
    }
}

int main(){
    int n=0, temp=0, x=0;

    printf("Enter the number of elements : ");
    scanf("%d", &n);

    printf("Choose the probing method -\n1. Linear Probing\n2. Quadratic Probing\n3. Double Hashing\nEnter your choice : ");
    scanf("%d", &x);

    printf("Enter the elements -\n");
    for(int i=0; i<n; i++){
        scanf("%d", &temp);
        insert(temp, x);
    }

    printHash(hashTable);
    freeHash();
    return 0;
}