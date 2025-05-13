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

int max(int a, int b){
    return (a>b)?a:b;
}

int getHeight(Node *root){
    if(root==NULL) return 0;

    int lh = getHeight(root->left);
    int rh = getHeight(root->right);

    return 1+max(lh, rh); 
}

void traverse(Node *root, int val){
    if(root!=NULL){
        if(root->val==val){
            int temp = getHeight(root);
            printf("\nThe height of node %d is %d\n", val, temp);
        }
        else{
            traverse(root->left, val);
            traverse(root->right, val);
        }
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

    int temp;
    printf("\nEnter the value of the node whose height is to be found : ");
    scanf("%d", &temp);

    traverse(root, temp);

    freeTree(root);
    return 0;
}