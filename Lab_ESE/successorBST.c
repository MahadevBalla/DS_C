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

Node* getMin(Node *root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

Node* getSuccessor(Node *root, int k){
    Node* successor = NULL;
    while(root!=NULL){
        if(k > root->val){
            root = root->right;
        }
        else if(k < root->val){
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
    
    Node *successor = getSuccessor(root, temp);
    if(successor!=NULL){
        printf("Successor of %d : %d\n", temp, successor->val);
    }
    else{
        printf("Successor of %d doesn't exist!", temp);
    }

    freeBST(root);
    return 0;
}