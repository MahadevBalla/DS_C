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

void freeLL(Node* head){
    Node* temp;
    while(head!=NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

Node* partition(Node* head, int x){
    if(head==NULL) return head;
    
    Node* curr = head, *partitionedLL = NULL;
    while(curr!=NULL){
        if(curr->val < x){
            partitionedLL = insertAtEnd(partitionedLL, curr->val);
        }
        curr = curr->next;
    }

    partitionedLL = insertAtEnd(partitionedLL, x);

    curr = head;
    while(curr!=NULL){
        if(curr->val > x){
            partitionedLL = insertAtEnd(partitionedLL, curr->val);
        }
        curr = curr->next;
    }
    return partitionedLL;
}

void printList(Node* node){
    if(node==NULL){
        printf("Empty List!\n");
        return;
    }
    
    while(node->next!=NULL){
        printf("%d->", node->val);
        node = node->next;
    }
    printf("%d\n", node->val);
}

int main(){
    int t, temp;
    Node* head = NULL, *partitionedLL;
    
    printf("Enter the no of elements : ");
    scanf("%d", &t);
    
    printf("Enter the elements : ");
    for(int i=0; i<t; i++){
        scanf("%d", &temp);
        head = insertAtEnd(head, temp);
    }

    printf("Enter the value 'x' : ");
    scanf("%d", &temp);
    
    printf("Original LL : ");
    printList(head);
    partitionedLL = partition(head, temp);
    printf("LL after partitioning : ");
    printList(partitionedLL);
    
    freeLL(head);
    freeLL(partitionedLL);
    return 0;
}