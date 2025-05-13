#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int coeff, exp;
    struct Node *next;
}Node;

Node *createNode(int coeff, int exp){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->exp = exp;
    newNode->coeff = coeff;
    newNode->next = NULL;
    return newNode;
}

Node *insertTerm(Node *head, int coeff, int exp){
    if(coeff==0) return NULL;

    Node *newNode = createNode(coeff, exp);
    if(head==NULL || head->exp < exp){
        newNode->next = head;
        return newNode;
    } 

    Node *curr = head, *prev = NULL;
    while(curr!=NULL && curr->exp > exp){
        prev = curr;
        curr = curr->next;
    }
    
    if(curr!=NULL && curr->exp==exp){
        curr->coeff += coeff;
        return head;
    }

    if(prev!=NULL){
        prev->next = newNode;
    }
    else{
        head = newNode;
    }
    newNode->next = curr;
    return head;
}

Node *multiply(Node *n1, Node *n2){
    Node *res = NULL;
    for(Node *t1=n1; t1!=NULL; t1=t1->next){
        for(Node *t2=n2; t2!=NULL; t2=t2->next){
            int coeff = t1->coeff * t2->coeff;
            int exp = t1->exp + t2->exp;
            res = insertTerm(res, coeff, exp);
        }
    }
    return res;
}

int main(){
    return 0;
}