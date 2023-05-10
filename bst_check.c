#include<stdio.h>
#include<malloc.h>
#include<math.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n; 
    n = (struct node *) malloc(sizeof(struct node)); 
    n->data = data; 
    n->left = NULL; 
    n->right = NULL; 
    return n; 
}

void preOrder(struct node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
void inorder(struct node* root){
    if(root!= NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int isBST(struct node* root){
    static struct node* prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return(isBST(root->right));
    }
    else{
        return 1;
    }

}
struct node * binary_search(struct node* root, int key){
   if(root==NULL){
    return NULL;
   }
   if(key==root->data){
    return root;
   } 
   else if( key <root->data ){
    return binary_search(root->left,key);
   }
   else{
    return binary_search(root->right, key);
   }
}
struct node * iter_search(struct node* root,int key){
    
   while(root!= NULL){
   if(key==root->data){
    return root;
   } 
   else if( key <root->data ){
    root = root->left;
   }
   else{
    root= root->right;
   }
   }
   
    return NULL;
}
void insert(struct node *root, int key){
   struct node *prev = NULL;
   while(root!=NULL){
       prev = root;
       if(key==root->data){
           printf("Cannot insert %d, already in BST", key);
           return;
       }
       else if(key<root->data){     
           root = root->left;
       }
       else{
           root = root->right;
       }
   }
   
   struct node* newnode = createNode(key);
   if(key<prev->data){
       prev->left = newnode;
   }
   else{
       prev->right = newnode;
   }

}
int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printGivenLevel(root, i);
}
struct node *inOrderPredecessor(struct node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value){

    struct node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }

    if (value < root->data){
        root-> left = deleteNode(root->left,value);
    }
    else if (value > root->data){
        root-> right = deleteNode(root->right,value);
    }
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

 

void mirror(struct node* node) {
    if (node == NULL) {
        return;
    } else {
        struct node* temp;

        temp = node->left;
        node->left = node->right;
        node->right = temp;

        mirror(node->left);
        mirror(node->right);
    }
}




int main(){
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    preOrder(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    insert(p,7);

    inorder(p);
    printf("\n");
    deleteNode(p,7);
    inorder(p);
    printf("\n");
    printf("%d",isBST(p));  
    printf("\n");
    printLevelOrder(p);
    printf("\n");
    printf("%d", height(p));
    printf("\n");
    inorder(p);
    printf("\n");
    struct node* n = iter_search(p, 6);
    if(n!=NULL){
    printf("Found: %d", n->data);
    }
    else{
        printf("Element not found");
    }
    printf("\n");
    inorder(p);
    printf("\n");
    mirror(p);
    inorder(p);
    printf("\n");
    return 0;
}
