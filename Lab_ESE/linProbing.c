#include<stdio.h>
#include<stdlib.h>

#define hashSize 10

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

void insert(int val){
    int idx;
    idx = linearProbing(val);

    if(hashTable[idx] == NULL || hashTable[idx]->status == 'E'){
        hashTable[idx] = createNode(idx, 'O', val);
    }
    else if(hashTable[idx]->status == 'D'){
        hashTable[idx]->val = val;
        hashTable[idx]->status = 'O';
    }
}

void search(int val){
    int idx = h(val);
    if(idx){
        printf("The element %d is present at index %d.\n", val, idx);
    }
    else{
        printf("The element %d doesn't exist in the hash table!\n");
    }
}

void printHash(hashNode **hashTable){
    for(int i=0; i<hashSize; i++){
        if(hashTable[i] == NULL){
            printf("Loc %d : Empty\n", i);
        }
        else if(hashTable[i]->status == 'E'){
            printf("Loc %d : Deleted\n", i);
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
    do{
        printf("Choose an operation to perform - 1. Insert     2. Search     3. Print     4.Exit\nEnter your choice : ");
        scanf("%d", &x);
        switch(x){
            case 1:
                printf("Enter the number of elements : ");
                scanf("%d", &n);
                printf("Enter the elements -\n");
                for(int i=0; i<n; i++){
                    scanf("%d", &temp);
                    insert(temp);
                }
                break;

            case 2:
                printf("Enter the element to be searched : ");
                scanf("%d", &n);
                search(n);
                break;

            case 3:
                printHash(hashTable);
                break;

            case 4:
                printf("Exiting...");
                break;

            default:
                printf("Enter a valid input!");
        }
    }
    while(x!=4);

    freeHash();
    return 0;
}