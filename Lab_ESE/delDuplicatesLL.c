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

Node* delDuplicates(Node* head){
    if(head==NULL) return head;
    Node* curr = head, *front=curr->next;
    while(curr!=NULL && front!=NULL){
        if(curr->val==front->val){
            curr->next = front->next;
            front = curr->next;
        }
        else{
            curr = curr->next;
            front = front->next;
        }
    }
    return head;
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
    Node* head = NULL;
    printf("Enter the no of elements : ");
    scanf("%d", &t);
    printf("Enter the elements : ");
    for(int i=0; i<t; i++){
        scanf("%d", &temp);
        head = insertAtEnd(head, temp);
    }
    printf("Original LL : ");
    printList(head);
    head = delDuplicates(head);
    printf("LL after deleting duplicates : ");
    printList(head);
    freeLL(head);
    return 0;
}