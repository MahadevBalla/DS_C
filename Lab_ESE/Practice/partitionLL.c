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

Node *partition(Node *head, int x){
    if(head==NULL) return NULL;
    Node *res = NULL, *temp = head;
    while(temp!=NULL){
        if(temp->val < x){
            res = insertAtEnd(res, temp->val);
        }
        temp = temp->next;
    }
    res = insertAtEnd(res, x);
    temp = head;
    while(temp!=NULL){
        if(temp->val > x){
            res = insertAtEnd(res, temp->val);
        }
        temp = temp->next;
    }
    return res;
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

    Node *partitionedLL = partition(head, 3);
    printf("List after partition : ");
    printLL(partitionedLL);

    freeLL(head);
    freeLL(partitionedLL);
    return 0;
}