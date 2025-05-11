#include <stdio.h>
#include <stdlib.h>

int cnt = 0;

struct Node{
   int val;
   struct Node *left, *right;
};

struct Node *createNode(int val){
   struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   newNode->val = val;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode;
}

struct Node *insertNode(struct Node *root, int val){
   if(root == NULL){
       return createNode(val);
   }
   if(val < root->val){
       root->left = insertNode(root->left, val);
   }
   else if(val >= root->val){
       root->right = insertNode(root->right, val);
   }
   return root;
}

void inOrderTraversal(struct Node *root, int x){
   if(root != NULL){
       inOrderTraversal(root->left, x);
       printf("%d ", root->val);
       if(root->val == x) cnt++;
       inOrderTraversal(root->right, x);
   }
}

void freeBST(struct Node* root){
   if(root != NULL){
       freeBST(root->left);
       freeBST(root->right);
       free(root);
   }
}

int main(){
   int n, x;
   struct Node *root = NULL;
   printf("Enter the number of elements : ");
   scanf("%d", &n);
   int arr[n];
   printf("Enter elements : ");
   for (int i = 0; i < n; i++){
       scanf("%d", &arr[i]);
       root = insertNode(root, arr[i]);
   }
   printf("Enter a value : ");
   scanf("%d", &x);
   printf("Inorder traversal : ");
   inOrderTraversal(root, x);
   printf("\nOccurence of %d : %d\n", x, cnt);

   freeBST(root);   
   return 0;
}