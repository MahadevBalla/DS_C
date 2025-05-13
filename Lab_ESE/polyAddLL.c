#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int coeff;
    int exp;
    struct Node* next;
} Node;

Node* createNode(int coeff, int exp){
    Node* new = (Node*)malloc(sizeof(Node));
    new->coeff = coeff;
    new->exp = exp;
    new->next = NULL;
    return new;
}


Node* insertTerm(Node* head, int coeff, int exp){
    if(coeff==0) return head;

    Node* newNode = createNode(coeff, exp);
    if(head==NULL || head->exp < exp){
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    Node* prev = NULL;

    while(current!=NULL && current->exp > exp){
        prev = current;
        current = current->next;
    }

    if(current!=NULL && current->exp==exp){
        current->coeff += coeff;
        free(newNode);
        return head;
    }

    if(prev!=NULL){
        prev->next = newNode;
    } else{
        head = newNode;
    }
    newNode->next = current;
    return head;
}

//can alternatively define result LL in the main func and call insertTerm in the i/p loops
Node* add(Node* n1, Node* n2){
    Node* result = NULL;
    
    for(Node *p=n1; p!=NULL; p=p->next){
        result = insertTerm(result, p->coeff, p->exp);
    }

    for(Node *p=n2; p!=NULL; p=p->next){
        result = insertTerm(result, p->coeff, p->exp);
    }
    return result;
}

void printList(Node* node){
    if(node==NULL){
        printf("0\n");
        return;
    }

    while(node!=NULL){
        printf("%dx^%d", node->coeff, node->exp);
        node = node->next;
        if(node){
            printf(" + ");
        }
    }
    printf("\n");
}

void freeLL(Node* head){
    Node* temp;
    while(head!=NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    int p, q, coeff;
    Node *n1 = NULL, *n2 = NULL;

    printf("Enter the degree of the first polynomial : ");
    scanf("%d", &p);
    printf("Enter the coeffs. - \n");
    for(int i=p; i>=0; i--){
        printf("Enter coeff. for x^%d : ", i);
        scanf("%d", &coeff);
        n1 = insertTerm(n1, coeff, i);
    }

    printf("Enter the degree of the second polynomial : ");
    scanf("%d", &q);
    printf("Enter the coeffs. - \n");
    for(int i=q; i>=0; i--){
        printf("Enter coeff. for x^%d : ", i);
        scanf("%d", &coeff);
        n2 = insertTerm(n2, coeff, i);
    }

    printf("1st polynomial: ");
    printList(n1);
    printf("2nd polynomial: ");
    printList(n2);

    Node* result = add(n1, n2);
    printf("Result : ");
    printList(result);

    freeLL(n1);
    freeLL(n2);
    freeLL(result);
    return 0;
}