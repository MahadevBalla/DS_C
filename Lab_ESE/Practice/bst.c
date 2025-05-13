#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node{
    int val;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int val){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *root, int val){
    if(root==NULL) return createNode(val);
    if(val < root->val){
        root->left = insertNode(root->left, val);
    }
    else if(val > root->val){
        root->right = insertNode(root->right, val);

    }
    return root;
}

Node *findNode(Node *root, int val){
    while(root!=NULL){
        if(val>root->val){
            root = root->right;
        }
        else if(val<root->val){
            root = root->left;
        }
        else{
            return root;
        }
    }
    return NULL;
}

Node *getMin(Node *root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

Node *getMax(Node *root){
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
}

Node *getSuccessor(Node *root, int x){
    Node *successor = NULL;
    while(root!=NULL){
        if(x>root->val){
            root = root->right;
        }
        else if(x<root->val){
            successor = root;
            root = root->left;
        }
        else{
            if(root->right!=NULL){
                successor = getMin(root->right);
            }
            return successor;
        }
    }
    return successor;
}

Node *getPredecessor(Node *root, int x){
    Node *predecessor = NULL;
    while(root!=NULL){
        if(x<root->val){
            root = root->left;
        }
        else if(x>root->val){
            predecessor = root;
            root = root->right;
        }
        else{
            if(root->left!=NULL){
                predecessor = getMax(root->left);
            }
            return predecessor;
        }
    }
    return predecessor;
}

int maxKey = INT_MIN, minKey = INT_MAX;

void inOrder(Node *root){
    if(root!=NULL){
        if(root->val > maxKey) maxKey = root->val;
        if(root->val < minKey) minKey = root->val;
        inOrder(root->left);
        printf("%d  ", root->val);
        inOrder(root->right);
    }
}

void preOrder(Node *root){
    if(root!=NULL){
        printf("%d  ", root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d  ", root->val);
    }
}

int max(int a, int b){
    return (a>b)?a:b;
}

int getHeight(Node *root){
    if(root==NULL) return 0;
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    return 1 + max(lh, rh);
}

int getBF(Node *root, int val){
    Node *node = findNode(root, val);
    if(node==NULL) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

void freeTree(Node *root){
    if(root!=NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(){
    Node *root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 12);
    root = insertNode(root, 6);
    root = insertNode(root, 3);
    root = insertNode(root, 15);
    root = insertNode(root, 7);
    root = insertNode(root, 1);

    printf("\nPreorder Traversal : ");
    preOrder(root);
    printf("\nInorder Traversal : ");
    inOrder(root);
    printf("\nPostorder Traversal : ");
    postOrder(root);

    printf("\nMax Key : %d", maxKey);
    printf("\nMin Key : %d", minKey);

    int temp;
    printf("\nEnter a value : ");
    scanf("%d", &temp);
    Node *successor =  getSuccessor(root, temp);
    Node *predecessor = getPredecessor(root, temp);
    printf("\nSuccessor of %d : %d", temp, successor->val);
    printf("\nPredecessor of %d : %d", temp, predecessor->val);
    printf("\nBalance Factor of %d : %d", temp, getBF(root, temp));

    freeTree(root);
    return 0;
}