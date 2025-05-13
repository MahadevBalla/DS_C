#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *left;
    struct Node *right;
    int height;
}Node;

Node *getNode(int val){
    Node *new = (Node *)malloc(sizeof(Node));
    new->left = new->right = NULL;
    new->val = val;
    new->height = 1;
    return new;
}

int max(int a, int b){
    if(a>b) return a;
    return b;
}

int getHeight(Node *node){
    if(node==NULL) return 0;
    return node->height;
}

void inOrderTraversal(Node *root){
    if(root!=NULL){
        inOrderTraversal(root->left);
        printf("%d  ", root->val);
        inOrderTraversal(root->right);
    }
}

Node *RR(Node *node){
    Node *temp1 = node->right;
    Node *temp2 = temp1->left;

    temp1->left = node;
    node->right = temp2;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    temp1->height = max(getHeight(temp1->left), getHeight(temp1->right)) + 1;

    return temp1;
}

Node *LL(Node *node){
    Node *temp1 = node->left;
    Node *temp2 = temp1->right;

    temp1->right = node;
    node->left = temp2;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    temp1->height = max(getHeight(temp1->left), getHeight(temp1->right)) + 1;
    
    return temp1;
}

Node *LR(Node *node){
    node->left = RR(node->left);
    return LL(node);
}

Node *RL(Node *node){
    node->right = LL(node->right);
    return RR(node);
}

Node* insertNode(Node *root, int val){
    if(root == NULL) return getNode(val);

    if(val > root->val){
        root->right = insertNode(root->right, val);
    }
    else if(val < root->val){
        root->left = insertNode(root->left, val);
    }
    else{
        return root;
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int bal = getHeight(root->left) - getHeight(root->right);

    if(bal > 1  &&  val < root->left->val){
        printf("Left-Left Case...Inorder Traversal at this moment : ");
        inOrderTraversal(root);
        printf("\n");
        return LL(root);
    }
    if(bal < -1  &&  val > root->right->val){
        printf("Right-Right Case...Inorder Traversal at this moment : ");
        inOrderTraversal(root);
        printf("\n");
        return RR(root);
    }
    if(bal > 1  &&  val > root->left->val){
        printf("Left-Right Case...Inorder Traversal at this moment : ");
        inOrderTraversal(root);
        printf("\n");
        return LR(root);
    }
    if(bal < -1  &&  val < root->right->val){
        printf("Right-Left Case...Inorder Traversal at this moment : ");
        inOrderTraversal(root);
        printf("\n");
        return RL(root);
    }
    return root;
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
    int t, val;
    printf("Enter N : ");
    scanf("%d", &t);
    printf("Enter the values : ");
    while(t--){
        scanf("%d", &val);
        root = insertNode(root, val);
    }
    printf("Inorder Traversal : ");
    inOrderTraversal(root);
    printf("\n");
    freeTree(root);
    return 0;
}