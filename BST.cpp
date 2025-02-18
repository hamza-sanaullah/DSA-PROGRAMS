#include <iostream>
using namespace std;
struct node
{
    int data;
    node *right;
    node *left;
};

void Search(struct node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return;
        }
        else if (root->data > key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
}
struct node *Insert(struct node *root, int key)
{
    if (root == NULL)
    {
        node *newNode = new node;
        newNode->data = key;
        newNode->right = NULL;
        newNode->left = NULL;
        return newNode;
    }
    else
    {
        if (root->data == key)
        {
            cout << "Insertion for this element not possible\n";
        }
        else if (root->data < key)
        {
            root->right = Insert(root->right, key);
        }
        else
        {
            root->left = Insert(root->left, key);
        }
    }
    return root;
}

void InorderTraverse(struct node *root)
{

    if (root == NULL)
    {
        return;
    }

    InorderTraverse(root->left);
    cout << root->data << endl;
    InorderTraverse(root->right);
}

void preorderTraverse(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}

void PostOrderTraverse(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrderTraverse(root->left);
    PostOrderTraverse(root->right);
    cout << root->data << " ";
}

void MaxTree(struct node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    cout << "The Maximum Tree is"
         << " " << root->data << endl;
}

void MinTree(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    cout << "The Minimum Tree is"
         << " " << root->data << endl;
}

node *inorderSucc(node *root)
{
    node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
struct node *successor(struct node *root, int data)
{
    struct node *current = root;
    struct node *successor = nullptr;
    while (current != nullptr && current->data != data)
    {
        if (current->data > data)
        {
            successor = current;
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    if (current == nullptr)
    {
        return nullptr;
    }
    if (current->right != nullptr)
    {
        current = current->right;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }
    return successor;
}

struct node *predecessor(struct node *root, int data)
{
    struct node *current = root;
    struct node *predecessor = nullptr;
    while (current != nullptr && current->data != data)
    {
        if (current->data < data)
        {
            predecessor = current;
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
    if (current == nullptr)
    {
        return nullptr;
    }
    if (current->left != nullptr)
    {
        current = current->left;
        while (current->right != nullptr)
        {
            current = current->right;
        }
        return current;
    }
    return predecessor;
}

node *Delnode(node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = Delnode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = Delnode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = Delnode(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct node *BST = NULL;
    int choice;

    while (choice != 4)
    {
        cout << "1.Insertion\n2.Deletion\n3.Max Tree\n4.Min Tree\n5.Traversal\n6.Precedessor\n7.Successor\n";
        cin >> choice;
        if (choice == 1)
        {
            int key;
            cout << "Enter the key you want to insert\n";
            cin >> key;
            BST = Insert(BST, key);
        }
        else if (choice == 5)
        {
            int traverse;
            cout << "You have Following Traversals\n1.PreOrderTraversal\n2.PostorderTraversal\n3.InorderTraversal\n";
            cin >> traverse;
            if (traverse == 1)
            {
                preorderTraverse(BST);
            }
            else if (traverse == 2)
            {
                PostOrderTraverse(BST);
            }
            else if (traverse == 3)
            {
                InorderTraverse(BST);
            }
        }
        else if (choice == 3)
        {
            MaxTree(BST);
        }
        else if (choice == 4)
        {
            MinTree(BST);
        }
        else if (choice == 2)
        {
            int key;
            cout << "Enter the Key you want to delete\n";
            cin >> key;
            BST = Delnode(BST, key);
        }
        else if (choice == 6)
        {
            int key;
            cout << "Enter the Key you want to delete\n";
            cin >> key;
            cout << predecessor(BST, key)->data << endl;
        }
        else if (choice == 7)
        {
            int key;
            cout << "Enter the Key you want to delete\n";
            cin >> key;
            cout << successor(BST, key)->data;
        }
    }

    return 0;
}