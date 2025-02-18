#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <string>
#include <algorithm> // for std::min_element
#include <climits> 
#include <windows.h>
#include <thread>
#include <chrono>
using namespace std;

void setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void centerText(const string& text) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;

    // Get the number of columns in the console
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    // Calculate the number of spaces to insert before the text
    int spaces = (columns - text.length()) / 2;

    // Print the spaces and then the text
    for (int i = 0; i < spaces; ++i) {
        cout << " ";
    }
    cout << text << std::endl;
}
void loadingSpinner(int duration) {
    const char spinnerChars[] = {'|', '/', '-', '\\'};
    int spinnerIndex = 0;

    for (int i = 0; i < duration * 10; ++i) {
        cout << "\rProcessing " << spinnerChars[spinnerIndex] << flush;
        spinnerIndex = (spinnerIndex + 1) % 4;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << "\rProcessing complete!   " << std::endl;
}

void typingEffect(const string& text) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    cout << std::endl;
}

struct node
{
    string data;
    int weight_of_word;
    struct node *right;
    struct node *left;
};

int levenshtein_distance(const string &str1, const string &str2)
{
    int m = str1.size();
    int n = str2.size();

    // Create a distance matrix
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Base cases: empty strings have distance equal to their length
    for (int i = 0; i <= m; ++i)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; ++j)
    {
        dp[0][j] = j;
    }

    // Fill the DP table
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int cost;
            if (str1[i - 1] == str2[j - 1])
            {
                cost = 0;
            }
            else
            {
                cost = 1;
            }
            dp[i][j] = min({dp[i - 1][j] + 1,          // deletion
                            dp[i][j - 1] + 1,          // insertion
                            dp[i - 1][j - 1] + cost}); // substitution
        }
    }

    return dp[m][n];
}

bool is_correct_word(const string &word, const vector<string> &dictionary, int max_distance)
{
    // Lowercase the word for case-insensitive comparison
    string lowercase_word = word;
    transform(lowercase_word.begin(), lowercase_word.end(), lowercase_word.begin(), ::tolower);

    // Find the word in the dictionary with the minimum Levenshtein distance
    int min_distance = INT_MAX;
    for (const string &dict_word : dictionary)
    {
        int distance = levenshtein_distance(lowercase_word, dict_word);
        min_distance = min(min_distance, distance);
    }

    // Check if the minimum distance is within the threshold
    return min_distance <= max_distance;
}

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
    if (root == nullptr)
    {
        root = node_creation(key, word);
        return root;
    }
    if (key < root->weight_of_word)
    {
        root->left = insert(root->left, key, word);
    }
    else if (key > root->weight_of_word)
    {
        root->right = insert(root->right, key, word);
    }
    else
    {
        // If the weights are equal, use the word comparison to decide where to insert
        if (word < root->data)
        {
            root->left = insert(root->left, key, word);
        }
        else if (word > root->data)
        {
            root->right = insert(root->right, key, word);
        }
    }
    return root;
}

void inorderTraversal(struct node *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
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
void loaddictionary(struct node *&root)
{
    string word;

    // Load words from dictionary file
    ifstream inDict("dict.txt");
    if (!inDict)
    {
        cerr << "Error opening dict.txt" << endl;
    }
    while (getline(inDict, word))
    {
        int weight = calculateWeight(word);
        weight = weight * weight;
        insert(root, weight, word);
    }
    inDict.close();
    //     cout << "Inorder Traversal of BST (based on weight):" << endl;
    //     inorderTraversal(root);
    //     cout << endl;
}

void spell_corrector(struct node *root, string str22)
{
    static string fin = ""; // Static variable to store the corrected word
    int hit = 0;            // Variable to keep track of matching characters

    // Check if the current node in the BST is not NULL
    if (root != NULL)
    {
        // Assign the data of the current node to 'fin'
        fin = root->data;

        // Check if the length difference is within a certain range
        if ((fin.size() - str22.size()) <= 2)
        {
            for (int o = 0; o < str22.size(); o++)
            {
                // Compare each character of 'str22' with 'fin' to find matching characters
                for (int i = 0; i < fin.size(); i++)
                {
                    if (str22[o] == fin[i])
                    {
                        hit++; // Increment the hit count for each matching character
                        break; // Exit the inner loop after a match is found
                    }
                }
            }
        }
         // Calculate the hit rate as a percentage
        int hitrate = (hit * 100) / (str22.size());

        // If the hit rate is 50% or more, print the corrected word
        if (hitrate >= 50)
        {
            cout << fin << endl;
        }

        // Recursively call 'spell_corrector' for the left and right subtrees
        spell_corrector(root->left, str22);
        spell_corrector(root->right, str22);
    }
}
void usersearchmethod(struct node *&root)
{
    string word;

    // Prompt user to enter words
    ofstream out("user_words.txt");
    if (!out)
    {
        cerr << "Error opening user_words.txt" << endl;
    }
    cout << "Enter words (type 'exit' to stop):" << endl;
    while (true)
    {
        cout << "> ";
        cin >> word;
        if (word == "exit")
            break;
        out << word << endl;
    }
    out.close();

    // Read user words and search in BST
    ifstream inUser("user_words.txt");

    if (!inUser)
    {
        cerr << "Error opening user_words.txt" << endl;
    }
    ofstream Cout("connected.txt", ios::app); // Open in append mode
    if (!Cout)
    {
        cerr << "Error opening Cout.txt" << endl;
    }
    while (getline(inUser, word))
    {
        if (search(root, word))
        {
            cout << "Found: " << word << endl;
            Cout << word << " (found)" << endl;
        }
        else
        {
            cout << "Not found: " << word << endl;
            cout << "Did you mean: " << endl;
            spell_corrector(root, word);
            string corrected_word;
            cout << "Enter the corrected word: ";
            cin >> corrected_word;
            Cout << corrected_word << endl;
        }
    }
    inUser.close();
    Cout.close();
}

void printMenu()
{
    cout << "\n---- SPELL CHECKER MENU ----" << endl;
    cout << "1. Search Words" << endl;
    cout << "2. Inorder Traversal of Dictionary" << endl;
    cout << "3. Exit" << endl;
    cout << "-----------------------------" << endl;
}

int main()
{
    struct node *root = nullptr;
    vector<string> dictionary;
    loaddictionary(root);
    int choice;
    do
    {
        setConsoleColor(10); // Set console text color to green
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        setConsoleColor(15); // Reset console text color to white

        switch (choice)
        {
        case 1:
            loadingSpinner(2); // Display loading spinner for 2 seconds
            usersearchmethod(root);
            break;
        case 2:
            inorderTraversal(root);
            break;
        case 3:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
