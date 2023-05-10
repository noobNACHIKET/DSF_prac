#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
    char data;
    struct node* left;
    struct node* right;
};

struct node* createNode(char data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* constructExpressionTree(char prefixExp[]) {
    int i;
    struct node* tempStack[100];
    int top = -1; 
    for (i = strlen(prefixExp) - 1; i >= 0; i--) {

        if (isdigit(prefixExp[i])) {
            struct node* newNode = createNode(prefixExp[i]);
            tempStack[++top] = newNode;
        }
    
        else if (prefixExp[i] == '+' || prefixExp[i] == '-' || prefixExp[i] == '*' || prefixExp[i] == '/') {
            struct node* newNode = createNode(prefixExp[i]);
            newNode->left = tempStack[top--];
            newNode->right = tempStack[top--];
            tempStack[++top] = newNode;
        }
    }
    
    return tempStack[top--];
}
void preOrder(struct node* root){
    if(root!=NULL){
        printf("%c ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%c ", root->data);
    }
}
void inorder(struct node* root){
    if(root!= NULL){
        inorder(root->left);
        printf("%c ",root->data);
        inorder(root->right);
    }
}

void iterativePreorder(struct node* root) {
    struct node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top != -1) {
        struct node* temp = stack[top--];
        printf("%c ", temp->data);
        if (temp->right != NULL) {
            stack[++top] = temp->right;
        }
        if (temp->left != NULL) {
            stack[++top] = temp->left;
        }
    }
}

void iterativeInorder(struct node* root) {
    struct node* stack[100];
    int top = -1;
    struct node* current = root;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%c ", current->data);
        current = current->right;
    }
}

void iterativePostorder(struct node* root) {
    struct node* stack1[100];
    struct node* stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1 != -1) {
        struct node* temp = stack1[top1--];
        stack2[++top2] = temp;
        if (temp->left != NULL) {
            stack1[++top1] = temp->left;
        }
        if (temp->right != NULL) {
            stack1[++top1] = temp->right;
        }
    }
    while (top2 != -1) {
        struct node* temp = stack2[top2--];
        printf("%c ", temp->data);
    }
}

int main() {
    char prefixExp[100];
    printf("Enter the prefix expression: ");
    scanf("%s", prefixExp);
    struct node* root = constructExpressionTree(prefixExp);
    printf("Recursive Preorder expression is: ");
    preOrder(root);
    printf("\nRecursive Inorder expression is: ");
    inorder(root);
    printf("\nRecursive Postorder expression is: ");
    postOrder(root);
    printf("\nIterative Preorder expression is: ");
    iterativePreorder(root);
    printf("\nIterative Inorder expression is: ");
    iterativeInorder(root);
    printf("\nIterative Postorder expression is: ");
    iterativePostorder(root);
    return 0;
}
