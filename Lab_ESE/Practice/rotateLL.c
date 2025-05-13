#include<stdio.h>
#include<stdlib.h>

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
    if(head==NULL) return newNode;
    Node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node *rotation(Node *head, int k){
    if(head==NULL) return NULL;
    Node *temp = head;
    int size = 0;

    while(temp->next!=NULL){
        temp = temp->next;
        size++;
    }

    temp->next = head;
    temp = head;

    for(int i=0; i<size-k; i++){
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}

void printLL(Node *head){
    if(head==NULL){
        printf("Empty List!\n");
        return;
    }

    while(head->next!=NULL){
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("%d\n", head->val);
}

void freeLL(Node *head){
    Node *temp;
    while(head!=NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){

    Node *head = NULL;
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 2);

    printf("Original List : ");
    printLL(head);

    head = rotation(head, 3);
    printf("List after rotation : ");
    printLL(head);

    freeLL(head);
    return 0;
}