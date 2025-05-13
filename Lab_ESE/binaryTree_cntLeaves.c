#include <stdio.h>
#include <stdlib.h>

int cnt = 0;

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

void cntLeaves(Node *root){
   if(root!=NULL){
        if(root->left==NULL && root->right==NULL){
            cnt++;
        }
        cntLeaves(root->left);
        cntLeaves(root->right);
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

    cntLeaves(root);
    printf("\nNumber of leaf nodes : %d\n", cnt);

    freeTree(root);
    return 0;
}