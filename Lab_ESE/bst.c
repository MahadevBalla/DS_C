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

void inOrderTraversal(Node *root){
   if(root != NULL){
       inOrderTraversal(root->left);
       printf("%d ", root->val);
       inOrderTraversal(root->right);
   }
}

void preOrderTraversal(Node *root){
   if(root != NULL){
        printf("%d ", root->val);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
   }
}

void postOrderTraversal(Node *root){
   if(root != NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->val);
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
    do{
        printf("1. Inorder Traversal     2. Preorder Traversal     3. Postorder Traversal     4. Exit\nEnter your choice : ");
        scanf("%d", &o);
        switch(o){
        case 1:
            printf("Inorder Traversal : ");
            inOrderTraversal(root);
            printf("\n");
            break;

        case 2:
        printf("Preorder Traversal : ");
            preOrderTraversal(root);
            printf("\n");
            break;

        case 3:
            printf("Postorder Traversal : ");
            postOrderTraversal(root);
            printf("\n");
            break;
        
        case 4:
            printf("Exiting...");
            t=0;
            break;

        default:
            printf("Enter a valid input!");
            printf("\n");
        }
    }
    while(t);
    freeBST(root);
    return 0;
}