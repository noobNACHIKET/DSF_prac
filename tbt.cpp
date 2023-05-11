#include <bits/stdc++.h>
using namespace std;

class TBT
{
public:
    int data;
    TBT *left;
    TBT *right;
    bool leftthread;
    bool rightthread;
};

TBT *create_Tree(int data)
{
    TBT *n = new TBT;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->leftthread = true;
    n->rightthread = true;
    return n;
}

TBT *insert(TBT *root, int value)
{
    if (root == nullptr)
    {
        root = create_Tree(value);
    }
    else if (value <= root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

TBT *Left_most(TBT *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

void Create_TBT(TBT *root)
{
    if (root == NULL)
    {
        return;
    }
    Create_TBT(root->left);
    Create_TBT(root->right);
    if (root->left == NULL)
    {
        root->left = Left_most(root->right);
        root->leftthread = true;
    }
    if (root->right == NULL)
    {
        root->right = root->left;
        root->rightthread = true;
    }
}

void Inorder(TBT *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}


int main() {
    TBT* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 13);
    root = insert(root, 17);

    Create_TBT(root);
    
    cout << "Inorder traversal of the threaded BST: ";
    Inorder(root);

    return 0;
}
