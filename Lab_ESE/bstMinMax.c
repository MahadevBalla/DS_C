#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min = INT_MAX , max = INT_MIN;

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

Node *insertNode(Node *root, int val){
   if(root == NULL){
       return createNode(val);
   }
   if(val < root->val){
       root->left = insertNode(root->left, val);
   }
   else if(val > root->val){
       root->right = insertNode(root->right, val);
   }
   return root;
}

void findMinMax(Node *root){
   if(root != NULL){
       findMinMax(root->left);
       if(root->val>max) max = root->val;
       if(root->val<min) min = root->val;
       findMinMax(root->right);
   }
}

void freeBST(Node* root){
   if(root != NULL){
       freeBST(root->left);
       freeBST(root->right);
       free(root);
   }
}

int main(){
    int n, temp, o, t=1;
    Node *root = NULL;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    printf("Enter elements : ");
    for(int i=0; i<n; i++){
        scanf("%d", &temp); 
        root = insertNode(root, temp);
    }

    findMinMax(root);
    printf("Min. key : %d\n", min);
    printf("Max. key : %d", max);

    freeBST(root);
    return 0;
}