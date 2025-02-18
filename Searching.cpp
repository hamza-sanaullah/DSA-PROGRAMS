#include <iostream>
using namespace std;
void linearseaech(int arr[], int size)
{
    cout << "Enter the Element You want to find in the Array\n";
    int search;
    cin >> search;
    for (int i = 0; i < size; i++)
    {
        if (search == arr[i])
        {
            cout << "Your Desired Element is at the Index\n"
                 << " " << i;
                 break;
        }
        else
        {
            cout << "The Element is not found\n";
        }
    }
}

bool issorted(int Arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (Arr[i] > Arr[i + 1])
        {
            return false;
        }
    }
    return true;
}
void binearysearch(int Arr[], int size)
{
    cout << "Enter the Element You want to find in the Array\n";
    int search;
    cin >> search;

    int low = Arr[0];
    int high = Arr[size - 1];
    for (; low <= high;)
    {

        int mid = (low + high) / 2;
        if (Arr[mid] == search)
        {
            cout << "Your desired Element is at the index"
                 << " " << mid;
                 return;
        }
        else
        {
            if (search > Arr[mid])
            {
                low = mid;
            }
            else if (search < Arr[mid])
            {
                high = mid;
            }
        }
    }
    cout<<"The desired element is not found in the array";
}

int main()
{
    int size;
    cout << "Enter the size of the Array"
         << "  :";
    cin >> size;
    int array[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i << " "
             << "Element of the Array"
             << " :";
        cin >> array[i];
    }
    if (issorted(array,size))
    {
       binearysearch(array, size);
    }else{
        linearseaech(array,size);
    }
    
    
    return 0;
}