#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> // for std::min_element
#include <climits>   // for INT_MAX
using namespace std;

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

int main()
{
    vector<string> dictionary;

    // Read words from dictionary file
    ifstream dictFile("dict.txt");
    if (!dictFile)
    {
        cerr << "Error opening dictionary file." << endl;
        return 1;
    }

    string word;
    while (getline(dictFile, word))
    {
        dictionary.push_back(word);
    }
    dictFile.close();

    string user_word = "Exceptiomal"; // misspelled word

    if (is_correct_word(user_word, dictionary, 2))
    {
        cout << user_word << " is spelled correctly or a close match (within 2 edits)." << endl;
        
    }
    else
    {
        cout << user_word << " is misspelled." << endl;
    }

    return 0;
}
