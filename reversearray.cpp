#include <iostream>
using namespace std;

void reversearray(int Arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = Arr[i];

        Arr[i] = Arr[size - 1 - i];
        Arr[size - 1 - i] = temp;
    }

    for (int h = 0; h < size; h++)
    {
        cout << Arr[h] << " ";
    }
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
    reversearray(array, size);

    return 0;
}