#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

Node* createNode(int val){
    Node* newNode = ( Node*)malloc(sizeof( Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

Node* reverseLL(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* front;
    while(curr!=NULL){
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front; 
    }
    return prev;
}

Node* insertAtEnd(Node* head,int val){
    Node* newNode = createNode(val);
    if(head==NULL){
        return newNode;
    }
    else{        
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }
}

void freeLL(Node* head){
    Node* temp;
    while(head!=NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

void isPalindrome(Node* head){
    if(head==NULL){
        printf("1\n");
        return;
    } 
    
    Node* temp = head, *copy = NULL;
    while(temp!=NULL){
        copy = insertAtEnd(copy, temp->val);
        temp = temp->next;
    }
    
    copy = reverseLL(copy);
    Node* og = head;

    while(og!=NULL && copy!=NULL){
        if(copy->val!=og->val){
            printf("0\n");
            freeLL(copy);
            return;
        }
        copy = copy->next;
        og = og->next;
    }
    printf("1\n");
    freeLL(copy);
}

int main(){
    Node* head = NULL;
    int t, temp;
    printf("Enter the no. of elements : ");
    scanf("%d", &t);
    printf("Enter the elements : ");
    for(int i=0; i<t; i++){
        scanf("%d", &temp);
        head = insertAtEnd(head, temp);
    }
    isPalindrome(head);
    freeLL(head);
    return 0;
}