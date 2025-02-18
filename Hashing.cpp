#include <iostream>
#include <cstring>
using namespace std;
int HFQUAD1(const string &key, int tableSize)
{
    int hashValue = 0;
    for (char ch : key)
    {
        hashValue += static_cast<int>(ch);
    }
    cout << hashValue << endl;
    return hashValue % tableSize;
}
int HFQUAD2(const string &key, int tableSize)
{
    int hashValue = 0;
    for (int i = 1; i < key.length(); i += 2)
    {
        hashValue += static_cast<int>(key[i]);
    }
    cout << hashValue << endl;

    return hashValue % tableSize;
}
int linearProbing(const string &key, int tableSize, int probe)
{
    int hashValue = HFQUAD1(key, tableSize);
    return (hashValue + probe) % tableSize;
}

int QuadraticProbing(const string &key, int tableSize, int probe)
{
    int hashValue = HFQUAD1(key, tableSize);
    return (hashValue + probe * probe) % tableSize;
}
int DoubbleHashing(const string &key, int tableSize, int probe)
{
    int hasValue = HFQUAD1(key, tableSize);
    int hashValue = 0;
    for (char ch : key)
    {
        hashValue += static_cast<int>(ch);
    }
    int hashValue2 = 7 - (hashValue % 7);
    int final_hashvalue = (hasValue + (probe * hashValue2)) % tableSize;
    return final_hashvalue;
}

double calculateloadfactor(int elements, int totalsize)
{
    return static_cast<double>(elements) / totalsize;
}

void insert(const string &key, int tablesize, string A[], int &elements, int hashfunctionchoice, int probingchoice)
{
    double loadFactor = calculateloadfactor(elements, tablesize);
    if (loadFactor >= 0.8) 
    {
        cout << "Hash table is already filled up to 30%. Further insertions are not allowed." << endl;
        return;
    }
    int probe = 1;

    int hasvalue;
    if (hashfunctionchoice == 1)
        hasvalue = HFQUAD1(key, tablesize);
    else if (hashfunctionchoice == 2)
        hasvalue = HFQUAD2(key, tablesize);

    while (A[hasvalue].empty() == false)
    {
        if (probingchoice == 1)
            hasvalue = linearProbing(key, tablesize, probe);
        else if (probingchoice == 2)
            hasvalue = QuadraticProbing(key, tablesize, probe);
        else if (probingchoice == 3)
        {
            hasvalue = DoubbleHashing(key, tablesize, probe);
        }

        probe++;
    }

    A[hasvalue] = key;
    elements++;

    cout << "It get its position in"
         << " " << probe << " "
         << " probes\n";

}

void search(const string &key, int tablesize, string A[], int hashfunctionchoice, int probingchoice)
{
    int probe = 1;
    int hasvalue;
    if (hashfunctionchoice == 1)
        hasvalue = HFQUAD1(key, tablesize);
    else if (hashfunctionchoice == 2)
        hasvalue = HFQUAD2(key, tablesize);
    while (A[hasvalue] != key)
    {
        if (probingchoice == 1)
            hasvalue = linearProbing(key, tablesize, probe);
        else if (probingchoice == 2)
            hasvalue = QuadraticProbing(key, tablesize, probe);
        else if (probingchoice == 3)
        {
            hasvalue = DoubbleHashing(key, tablesize, probe);
        }

        probe++;
    }

    cout << "The Entered key is Found at the index"
         << "  " << hasvalue << " "
         << "of the Hashtable" << endl;
    cout << "The Element finds its position in"
         << " " << probe << " "
         << " probes\n";
}

int main()
{
    int tablesize;m,
    int elements = 0;
    cout << "Enter the Size of the Table\n";
    cin >> tablesize;
    string *hashtable = new string[tablesize];
    int choice;
    int hashFunctionChoice;
    int probingChoice;
    cout << "Choose the hash function for the experiment:\n";
    cout << "1. HFQUAD1\n2. HFQUAD2\n";
    cin >> hashFunctionChoice;

    cout << "Choose the probing method for the experiment:\n";
    cout << "1. Linear Probing\n2. Quadratic Probing\n3.Double Hashing\n";
    cin >> probingChoice;
    while (choice != 3)
    {
        cout << "1.Insertion in HashTable\n2.Search A Value in HashTable\n3.Exit\n";
        cout << "Enter the Choice\n";
        cin >> choice;
        if (choice == 1)
        {

            string key;
            
            cout << "Enter the String to be added in HashTable\n";
            cin >> key;
            insert(key, tablesize, hashtable, elements, hashFunctionChoice, probingChoice);
            

            cout << "Hashtable after insertion:" << endl;
            for (int i = 0; i < tablesize; ++i)
            {
                cout << "Bucket " << i << ": " << hashtable[i] << endl;
            }
            double load = calculateloadfactor(elements, tablesize);
            cout << "The Load Factor is"
                 << " " << load << " " << endl;
        }
        else if (choice == 2)
        {
            string key;
            cout << "Enter the key to be Search\n";
            cin >> key;
            search(key, tablesize, hashtable, hashFunctionChoice, probingChoice);
        }

        else
        {
            cout << "Invalid Input\n";
        }
    }

    delete hashtable;
    return 0;
}