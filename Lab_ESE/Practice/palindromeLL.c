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
    if(head==NULL) return newNode;

    Node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node *reverseLL(Node *head){
    Node *curr = head, *prev = NULL, *front;
    while(curr!=NULL){
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

void isPalindrome(Node *head){
    if(head==NULL){ 
        printf("1");
    }

    Node* temp = head, *copy = NULL;
    while(temp!=NULL){
        copy = insertAtEnd(copy, temp->val);
        temp = temp->next;
    }

    copy = reverseLL(copy);
    temp = head;
    while(copy!=NULL){
        if(copy->val!=temp->val){
            printf("0");
            return;
        }
        temp = temp->next;
        copy = copy->next;
    }
    printf("1");
}

int main(){

    Node *n1 = NULL;
    n1 = insertAtEnd(n1, 1);
    n1 = insertAtEnd(n1, 2);
    n1 = insertAtEnd(n1, 2);
    n1 = insertAtEnd(n1, 1);
    n1 = insertAtEnd(n1, 1);

    isPalindrome(n1);

    return 0;
}