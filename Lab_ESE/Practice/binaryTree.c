#include <stdio.h>
#include <stdlib.h>

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

Node *makeTree(){
    int temp;
    printf("Enter value of node(-1 for NULL) : ");
    scanf("%d", &temp);
    if(temp==-1) return NULL;
    Node *newNode = createNode(temp);
    printf("Left child of %d -\n", temp);
    newNode->left = makeTree();
    printf("Right child of %d -\n", temp);
    newNode->right = makeTree();
    return newNode;
}

int count = 0;

void countLeaves(Node *root){
    if(root!=NULL){
        if(root->left==NULL && root->right==NULL) count++;
        countLeaves(root->left);
        countLeaves(root->right);
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
    if(root==NULL) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

void traverseHeight(Node *root, int val){
    if(root!=NULL){
        if(root->val==val) printf("\nHeight of node %d : %d\n", val, getHeight(root));
    }
    traverseHeight(root->left, val);
    traverseHeight(root->right, val);
}

void inOrder(Node *root){
    if(root!=NULL){
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

void freeTree(Node *root){
    if(root!=NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(){
    Node *root = makeTree();

    printf("\nPreorder Traversal : ");
    preOrder(root);
    printf("\nInorder Traversal : ");
    inOrder(root);
    printf("\nPostorder Traversal : ");
    postOrder(root);

    countLeaves(root);
    printf("\nNo. of leaf nodes : %d\n", count);

    int temp;
    printf("Enter value of the node whose height is to be found : ");
    scanf("%d", &temp);
    traverseHeight(root, temp);
    
    freeTree(root);
    return 0;
}