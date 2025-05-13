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

Node* insertAfterPosn(Node* head, int val, int k){
    Node* newNode = createNode(val);
    if(head==NULL) return newNode;
    Node* temp = head;
    for(int i=0; i<k && temp->right!=NULL; i++){
        temp = temp->right;
    }
    newNode->left = temp;
    newNode->right = temp->right;
    if(temp->right!=NULL){
        temp->right->left = newNode;
    }
    temp->right = newNode;
    return head;
}

void swapAdjacentNodes(Node **head,  Node *curr){
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

// gpt gang :(
Node *sortDLL(Node *head){
    if(head == NULL || head->right == NULL){
        return head;
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

void freeLL( Node* head){
     Node *temp = NULL;
    while(head != NULL){
        temp = head;
        head = head->right;
        free(temp);
    }
}

int main(){
    int t=1, o, temp, k;
    Node* head = NULL;
    do{
        printf("Choose an operation to perform - 1. Insert after position     2. Sort the list     3. Display     4. Exit\nEnter your choice : ");
        scanf("%d", &o);
        switch(o){
            case 1:
                printf("Enter the value : ");
                scanf("%d", &temp);
                printf("Enter the position : ");
                scanf("%d", &k);
                insertAfterPosn(head, temp, k);
                break;
            
            case 2:
                sortDLL(head);
                printf("Sorted DLL : ");
                printList(head);
                break;

            case 3:
                printf("DLL : ");
                printList(head);
                break;

            case 4:
            printf("Exiting...");
            break;

            default:
            printf("Enter a valid input!");
        }
    }
    while(t);
    freeLL(head);
    return 0;
}