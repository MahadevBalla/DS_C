#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node *right;
    struct Node *left;
    int val;
}Node;

Node *createNode(int val){
    Node *new = (Node*)malloc(sizeof(Node));
    new->right = NULL;
    new->left = NULL;
    new->val = val;
    return new;
}

Node *insertAtEnd(Node *head, int val){
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

void freeLL(Node* head){
    Node *temp = NULL;
    while(head != NULL){
        temp = head;
        head = head->right;
        free(temp);
    }
}

void printList(Node *head){
    while(head->right != NULL){
        printf("%d <-> ", head->val);
        head = head->right;
    }
    printf("%d", head->val);
}

int main(){
    int t=1, o, temp;
    Node* head = NULL;
    do{
        printf("Choose an operation to perform - 1. Insert at the end     2. Concatenate two lists     3. Display     4. Exit\nEnter your choice : ");
        scanf("%d", &o);
        switch(o){
            case 1:
                printf("Enter the value : ");
                scanf("%d", &temp);
                insertAtEnd(head, temp);
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