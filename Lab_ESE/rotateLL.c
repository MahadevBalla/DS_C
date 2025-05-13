#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

Node* createNode(int val){
    Node* new = ( Node*)malloc(sizeof( Node));
    new->val = val;
    new->next = NULL;
    return new;
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

Node* rotate(Node* head, int k){
    int len = 0;
    Node *tail = head;
    
    while(tail->next!=NULL){
        len++;
        tail = tail->next;
    }

    tail->next = head;
    tail = head;
    for(int i=0; i<len-k; i++){
        tail = tail->next;
    }

    head = tail->next;
    tail->next = NULL;
    return head;
}

void freeLL(Node* head){
    Node* temp;
    while(head!=NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

void printList(Node* node){
    while(node->next!=NULL){
        printf("%d->", node->val);
        node = node->next;
    }
    printf("%d\n", node->val);
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

    printf("Enter the value of k : ");
    scanf("%d", &temp);

    printf("Original LL : ");
    printList(head);

    head = rotate(head, temp);
    printf("LL after rotation : ");
    printList(head);

    freeLL(head);
    return 0;
}