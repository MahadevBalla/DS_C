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
    Node *prev = NULL, *curr = head, *front;
    while(curr!=NULL){
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

Node *add(Node *n1, Node *n2){
    Node *res = NULL, *temp1 = n1, *temp2 = n2;
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
        carry = sum/10;
        res = insertAtEnd(res, sum%10);
    }
    return res;
}

void printList(Node *head){
    if(head==NULL){
        printf("0\n");
        return;
    }
    Node *temp = head;
    while(temp->next!=NULL){
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("%d\n", temp->val);
}

int main(){
    Node *n1 = NULL;
    n1 = insertAtEnd(n1, 1);
    n1 = insertAtEnd(n1, 2);
    n1 = insertAtEnd(n1, 3);
    
    Node *n2 = NULL;
    n2 = insertAtEnd(n2, 1);
    n2 = insertAtEnd(n2, 2);


    printf("Number 1 : ");
    printList(n1);
    printf("Number 2 : ");
    printList(n2);
    
    Node *result = add(reverseLL(n1), reverseLL(n2));
    printf("Answer : ");
    printList(reverseLL(result));

    return 0;
}