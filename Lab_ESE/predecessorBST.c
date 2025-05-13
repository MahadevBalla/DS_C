#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

Node* getMax(Node *root){
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
}

Node* getPredecessor(Node *root, int k){
    Node* pred = NULL;
    while(root!=NULL){
        if(k > root->val){
            pred = root;
            root = root->right;
        }
        else if(k < root->val){
            root = root->left;
        }
        else{
            if(root->left!=NULL){
                pred = getMax(root->left);
            }
            return pred;
        }
    }
    return pred;
}

void freeBST(Node* root){
   if(root != NULL){
       freeBST(root->left);
       freeBST(root->right);
       free(root);
   }
}

int main(){
    int n, temp;
    Node *root = NULL;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    printf("Enter elements : ");
    for(int i=0; i<n; i++){
        scanf("%d", &temp); 
        root = insertNode(root, temp);
    }

    printf("Enter a value : ");
    scanf("%d", &temp);
    
    Node *predecessor = getPredecessor(root, temp);
    if(predecessor!=NULL){
        printf("Predecessor of %d : %d\n", temp, predecessor->val);
    }
    else{
        printf("Predecessor of %d doesn't exist!", temp);
    }

    freeBST(root);
    return 0;
}