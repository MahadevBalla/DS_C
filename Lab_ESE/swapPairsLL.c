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

Node* swapPairs(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* p=head, *q=head->next, *prev=NULL, *newHead=q; 
    while(p!=NULL && p->next!=NULL){
        q = p->next;
        p->next = q->next;
        q->next = p;
        if(prev!=NULL) prev->next = q;
        prev = p;
        p = p->next;
    }
    return newHead;
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
    printf("Original LL : ");
    printList(head);
    head = swapPairs(head);
    printf("LL after swapping : ");
    printList(head);
    freeLL(head);
    return 0;
}