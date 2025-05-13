#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void printList(Node* head){
    if(head==NULL) return;

    Node* temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp!=head);

    printf("\n");
}

Node* append(Node* head, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(head==NULL){
        newNode->next = newNode;
        return newNode;
    }

    Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

Node* deleteEveryKthNode(Node* head, int k){
    if(head==NULL || k<=0) return head;

    Node* current = head;
    Node* prev = NULL;
    int count = 1;

    int length = 0;
    Node* temp = head;
    do{
        length++;
        temp = temp->next;
    } 
    while(temp!=head);

    while(length>1){
        for(int i=1; i<k; i++){
            prev = current;
            current = current->next;
        }
        printList(head);

        if(current==head){
            head = head->next;
        }
        prev->next = current->next;
        free(current);
        current = prev->next;
        length--;
    }
    printList(head);
    return head;
}

int main(){
    Node* head = NULL;
    int n, temp, k;

    printf("Enter the no. of nodes : ");
    scanf("%d", &n);
    printf("Enter the values : ");
    for(int i=0; i<n; i++){
        scanf("%d", &temp);
        head = append(head, temp);
    }

    printf("Enter the value of k : ");
    scanf("%d", &k);

    printf("Original Circular Linked List :\n");
    printList(head);

    printf("Deleting every %d-th node :\n", k);
    head = deleteEveryKthNode(head, k);

    if(head!=NULL){
        free(head);
    }
    return 0;
}