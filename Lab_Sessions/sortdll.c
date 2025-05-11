#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node *right;
    struct Node *left;
    int val;
}Node;

Node *createNode(int val){
    Node *new = ( Node*)malloc(sizeof( Node));
    new->right = NULL;
    new->left = NULL;
    new->val = val;
    return new;
}

Node *insertAtEnd( Node *head, int val){
     Node *newNode = createNode(val);
    if(head == NULL){
        return newNode;
    }
    else{
        Node *temp = head;
        while (temp->right != NULL){
            temp = temp->right;
        }
        temp->right = newNode;
        newNode->left = temp;
        return head;
    }
}

void freeLL( Node* head){
     Node *temp = NULL;
    while(head != NULL){
        temp = head;
        head = head->right;
        free(temp);
    }
}

void swapAdjacentNodes( Node **head,  Node *curr){
     Node *next = curr->right;
    if(curr->left != NULL){
        curr->left->right = next;
    } 
    else{
        *head = next;
    }
    if(next->right != NULL){
        next->right->left = curr;
    }

    curr->right = next->right;
    next->left = curr->left;
    next->right = curr;
    curr->left = next;
}

 Node *sortdll( Node *head) {
    if (head == NULL || head->right == NULL) {
        return head; // Empty or single-node list
    }

    int swapped;
     Node *temp;    
    do{
        swapped = 0;
        temp = head;

        while(temp->right != NULL){
            if(temp->val > temp->right->val){
                swapAdjacentNodes(&head, temp);
                swapped = 1;
            }
            else{
                temp = temp->right;
            }
        }
    }
    while(swapped);
    return head;
}

void printList( Node *head){
    while(head->right != NULL){
        printf("%d <-> ", head->val);
        head = head->right;
    }
    printf("%d", head->val);
}

int main(){
     Node *head = NULL; int size, val;
    printf("Enter the size of the doubly linked list : ");
    scanf("%d", &size);
    printf("Enter the elements : ");
    for(int i=0; i<size; i++){
        scanf("%d",&val);
        head = insertAtEnd(head, val);
    }
    printf("Original DLL : ");
    printList(head);
    printf("\n");
    head = sortdll(head);
    printf("Sorted DLL : ");
    printList(head);
    printf("\n");

    freeLL(head);
    return 0;
}