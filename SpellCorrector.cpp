#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

struct node
{
    string data;
    int weight_of_word;
    struct node *right;
    struct node *left;
};
// Creation of node
struct node *node_creation(int w, string d)
{
    struct node *temp = new node;
    temp->data = d;
    temp->right = nullptr;
    temp->left = nullptr;
    temp->weight_of_word = w;
    return temp;
}
int calculateWeight(const string &word)
{
    int weight = 0;
    for (char c : word)
    {
        weight += static_cast<int>(c); // Add ASCII value of each character
    }
    return weight;
}
struct node *insert(struct node *&root, int key, string word)
{
    if (root == NULL)
    {
        root = node_creation(key, word);
        return root;
    }
    if (root->data==word)
    {
        return root;
    }
    
    else if (key < root->weight_of_word)
    {
        root->left = insert(root->left, key, word);
    }
    else if (key > root->weight_of_word)
    {
        root->right = insert(root->right, key, word);
    }
    
    return root;
}

void inorderTraversal(struct node *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        // cout << root->data << " ";
        cout << endl;
        inorderTraversal(root->right);
    }
}
bool search(struct node *root, const string &word)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == word)
    {
        return true;
    }
    else if (calculateWeight(word) * calculateWeight(word) < root->weight_of_word)
    {
        return search(root->left, word);
    }
    else
    {
        return search(root->right, word);
    }
}

void loadDictionary(struct node *&root, const string &filename)
{
    ifstream inDict(filename);
    if (!inDict)
    {
        cerr << "Error opening " << filename << endl;
        return;
    }
    string word;
    while (getline(inDict, word))
    {
        int weight = calculateWeight(word);
        weight = weight * weight;
        // Convert characters to lowercase
        // cout<<"Inserting\n";
        insert(root, weight, word);
    }
    inDict.close();
}

void getUserWords(const string &filename)
{
    ofstream out(filename);
    if (!out)
    {
        cerr << "Error opening " << filename << endl;
        return;
    }
    string word;
    cout << "Enter words (type 'exit' to stop):" << endl;
    while (true)
    {
        cout << "> ";
        getline(cin, word); // Read entire line
        if (word == "exit")
        {
            break;
        }
        out << word << endl;
    }
    out.close();
}


void searchUserWords(struct node *root, const string &filename)
{
    ifstream inUser(filename);
    if (!inUser)
    {
        cerr << "Error opening " << filename << endl;
        return;
    }
    string word;
    while (getline(inUser, word))
    {
        cout << "Reading word: " << word << endl;
        if (search(root, word))
        {
            cout << "Word '" << word << "' exists in the dictionary." << endl;
        }
        else
        {
            cout << "Word '" << word << "' does not exist in the dictionary. Do you want suggestions? (y/n)" << endl;
            char response;
            cin >> response;

            if (response == 'y')
            {
                // Placeholder for suggestion logic
                cout << "Suggestions for '" << word << "': ..." << endl;
            }
        }
    }
    inUser.close();
}

int main()
{
    struct node *root = nullptr;
    // Load words from dictionary file
    loadDictionary(root, "dict.txt");

    // Prompt user to enter words

    // getUserWords("user_words.txt");
    // // Ask the user if they want to continue (replace with your logic)

    // // Read user words and search in BST
    // searchUserWords(root, "user_words.txt");

    // Display the BST using inorder traversal
    cout << "Inorder Traversal of BST (based on weight):" << endl;
    inorderTraversal(root);
    cout << endl;

    return 0;
}