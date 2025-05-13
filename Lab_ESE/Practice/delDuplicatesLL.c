#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *next; 
}Node;

Node *createNode(int val){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val; 
    newNode->next = NULL;
    return newNode;
}

Node *insertAtEnd(Node *head, int val){
    Node *newNode = createNode(val);
    if(head==NULL) return createNode(val);
    
    Node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node *delDuplicates(Node *head){
    Node *curr = head, *front = curr->next;
    while(curr!=NULL && front!=NULL){
        if(curr->val==front->val){
            curr->next = front->next;
            front = curr->next;
        }
        else{
            curr = curr->next;
            front = curr->next;
        }
    }
    return head;
}

void printLL(Node *head){
    if(head==NULL){
        printf("Empty List");
        return;
    }

    Node *temp = head;
    while(temp->next!=NULL){
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("%d\n", temp->val);
}

void freeLL(Node *head){
    Node *temp;
    while(temp!=NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    Node *head = NULL;
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 5);

    printf("Original List : ");
    printLL(head);
    head = delDuplicates(head);
    printf("List after deleting duplicates : ");
    printLL(head);
    return 0;
}