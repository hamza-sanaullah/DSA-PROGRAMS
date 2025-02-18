#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string word;
    int count = 0; // Counter to track the number of words read

    ifstream in("dict.txt"); // Open the file

    if (!in) {
        cerr << "Error opening file!" << endl;
        return 1; // Return with an error code
    }

    while (getline(in, word)) {
        
        cout << word << endl; // Print the line
        count++;
    }

    in.close(); // Close the file after reading the entire dictionary

    cout << "Total words read: " << count << endl; // Print the total number of words read

    return 0;
}
