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

Node* reverseLL(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* nex;
    while(curr != NULL){
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex; 
    }
    return prev;
}

Node* insertAtEnd(Node* head,int val){
    Node* newNode = createNode(val);
    if(head == NULL){
        return newNode;
    }
    else{        
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }
}

void printList(Node* node){
    if(node == NULL){
        printf("0\n");
        return;
    }

    while(node->next != NULL){
        printf("%d->", node->val);
        node = node->next;
    }
    printf("%d\n", node->val);
}

Node* addTwoLL(Node* n1, Node* n2){
    Node* temp1 = n1;
    Node* temp2 = n2;
    Node* result = NULL;
    int sum = 0, carry = 0;
    while(temp1 || temp2 || carry){
        sum = carry;
        if(temp1){
            sum += temp1->val;
            temp1 = temp1->next;
        }
        if(temp2){
            sum += temp2->val;
            temp2 = temp2->next;
        }
        // printf("%d\n", sum);
        carry = sum/10;
        result = insertAtEnd(result, sum%10);
    }
    return result;   
}

void freeLL( Node* head){
    Node* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    Node *n1 = NULL, *n2 = NULL;
    int n1_size, n2_size, temp;

    printf("Enter the number of digits in the first number : ");
    scanf("%d", &n1_size);
    printf("Enter the first number digit by digit : ");
    for(int i=0; i<n1_size; i++){
        scanf("%d", &temp);
        n1 = insertAtEnd(n1, temp);
    }

    printf("Enter the number of digits in the second number : ");
    scanf("%d", &n2_size);
    printf("Enter the second number digit by digit : ");
    for(int i=0; i<n2_size; i++){
        scanf("%d", &temp);
        n2 = insertAtEnd(n2, temp);
    }

    printf("Number 1 : ");
    printList(n1);
    printf("Number 2 : ");
    printList(n2);

    Node *result = addTwoLL(reverseLL(n1), reverseLL(n2));
    printf("Answer : ");
    printList(reverseLL(result));

    freeLL(n1); freeLL(n2); freeLL(result);
    return 0;
}