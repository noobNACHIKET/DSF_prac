#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int data;
    Tree *right;
    Tree *left;
};

Tree *Create_node(int data)
{
    Tree *n = new Tree;
    n->data = data;
    n->right = NULL;
    n->left = NULL;
    return n;
}

Tree *insert(Tree *root, int value)
{
    if (root == NULL)
    {
        return Create_node(value);
    }
    else if (root->data > value)
    {
        root->left = insert(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

void Inorder(Tree *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

Tree *Search(Tree *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == value)
    {
        return root;
    }
    else if (root->data > value)
    {
        Search(root->left, value);
    }
    else if (root->data < value)
    {
        Search(root->right, value);
    }
    else{
        cout<<"Not found";
        return NULL;
    }
}

int Tree_Height(Tree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int left_height = Tree_Height(root->left);
        int right_height = Tree_Height(root->right);
        return 1 + max(left_height, right_height);
    }
}

void level_order_traversal(Tree *root)
{
    if (!root)
        return;

    queue<Tree *> q;
    q.push(root);

    while (!q.empty())
    {
        Tree *node = q.front();
        q.pop();
        cout << node->data << " ";

        if (node->left)
        {
            q.push(node->left);
        }

        if (node->right)
        {
            q.push(node->right);
        }
    }
}

Tree *inOrderPredecessor(Tree *root)
{
    if (root->left == NULL)
    {
        return NULL;
    }
    
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
Tree *Deletnode(Tree *root, int value)
{
    Tree *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    // Search for the node to be deleted
    if (root->data > value)
    {
        root->left = Deletnode(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = Deletnode(root->right, value);
    }
    // Deletion strategy when the node is found
    else
    {
        ipre = inOrderPredecessor(root);
        root->data = ipre->data;
        root->left = Deletnode(root->left, ipre->data);
    }
    return root;
}

void mirror(Tree *root)
{
    if (!root)
    {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

int main()
{
    Tree *root = NULL;

    int choice, value;

    do
    {
        cout << "\n1. Insert\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Search\n";
        cout << "4. Tree Height\n";
        cout << "5. Level Order Traversal\n";
        cout << "6. Mirror\n";
        cout << "7. Delete\n";
        cout << "8. Exit\n\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to be inserted: ";
            cin >> value;
            root = insert(root, value);
            break;
        case 2:
            cout << "Inorder Traversal: ";
            Inorder(root);
            cout << endl;
            break;
        case 3:
            cout << "Enter value to be searched: ";
            cin >> value;
            if (Search(root, value) == NULL)
            {
                cout << "Value not found!\n";
            }
            else
            {
                cout << "Value found!\n";
            }
            break;
        case 4:
            cout << "Tree Height: " << Tree_Height(root) << endl;
            break;
        case 5:
            cout << "Level Order Traversal: ";
            level_order_traversal(root);
            cout << endl;
            break;
        case 6:
            mirror(root);
            cout << "Tree mirrored!\n";
            break;
        case 7:
            cout << "Enter value to be deleted: ";
            cin >> value;
            root = Deletnode(root, value);
            break;
        case 8:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}
