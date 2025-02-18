#include <iostream>
using namespace std;
struct node
{
    int key;
    node *right;
    node *left;
    int height;
};

int getHeight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

struct node *createNode(int key)
{
    struct node *Node = new node();
    Node->key = key;
    Node->left = NULL;
    Node->right = NULL;
    Node->height = 1;
    return Node;
}

int getBalanceFactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return y;
}

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x;
}
struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return createNode(key);
    }

    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    // Left Left Case
    if (bf > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    // Right Right Case
    if (bf < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    // Left Right Case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void InorderTraverse(struct node *root)
{

    if (root == NULL)
    {
        return;
    }

    InorderTraverse(root->left);
    cout << root->key << endl;
    InorderTraverse(root->right);
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
node *Delnode(node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->key)
    {
        root->left = Delnode(root->left, key);
    }
    else if (key > root->key)
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
        root->key = temp->key;
        root->right = Delnode(root->right, temp->key);
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalanceFactor(root);

    // Left Left Case
    if (bf > 1 && key < root->left->key)
    {
        return rightRotate(root);
    }
    // Right Right Case
    if (bf < -1 && key > root->right->key)
    {
        return leftRotate(root);
    }
    // Left Right Case
    if (bf > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Left Case
    if (bf < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

int main()
{
    struct node *root = NULL;
    int choice;
    while (choice != 6)
    {
        cout << "1.Insertion\n2.Deletion\n3.Traversal\n4.Height\n5.Balance Factor\n6.Exit\n";
        cin >> choice;
        if (choice == 1)
        {
            int key;
            cout << "Enter the key you want to insert\n";
            cin >> key;
            root = insert(root, key);
        }
        else if (choice == 3)
        {
            InorderTraverse(root);
        }
        else if (choice == 2)
        {
            int key;
            cout << "Enter the key you want to insert\n";
            cin >> key;
            root = Delnode(root, key);
        }
        else if (choice == 4)
        {

            cout << "Height of the Tree is\n";
            cout << getHeight(root) << endl;
        }
        else if (choice == 5)
        {

            cout << "Balance factor of the tree is\n";
            cout << getBalanceFactor(root) << endl;
        }
        
    }
    return 0;
}
