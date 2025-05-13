#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
}Node;

Node *createNode(int val){
   Node *newNode = (Node *)malloc(sizeof(Node));
   newNode->val = val;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode;
}

Node *buildTree(){
    int val;
    printf("Enter value (-1 for NULL) : ");
    scanf("%d", &val);

    if(val==-1){
        return NULL;
    }

    Node *newNode = createNode(val);
    printf("Left child of %d -\n", val);
    newNode->left = buildTree();
    printf("Right child of %d -\n", val);
    newNode->right = buildTree();

    return newNode;
}

void inOrderTraversal(Node *root){
   if(root!=NULL){
       inOrderTraversal(root->left);
       printf("%d ", root->val);
       inOrderTraversal(root->right);
   }
}

void preOrderTraversal(Node *root){
   if(root!=NULL){
        printf("%d ", root->val);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
   }
}

void postOrderTraversal(Node *root){
   if(root!=NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->val);
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

    Node *root = NULL;
    root = buildTree();

    printf("\nPreorder Traversal : ");
    preOrderTraversal(root);

    printf("\nInorder Traversal : ");
    inOrderTraversal(root);

    printf("\nPostorder Traversal : ");
    postOrderTraversal(root);

    freeTree(root);
    return 0;
}