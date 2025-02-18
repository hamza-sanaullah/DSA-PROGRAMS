#include <iostream>
using namespace std;

int maxnumber(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int MaxSubArray(int Arr[], int size)
{
    int currentMax = Arr[0];
    int Wholesum = Arr[0];
    for (int i = 1; i < size; i++)
    {
        currentMax = maxnumber(Arr[i], currentMax + Arr[i]);
        Wholesum = maxnumber(Wholesum, currentMax);
    }
    cout << Wholesum;
    return Wholesum;
}

int main()
{
    int Array[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(Array) / sizeof(Array[0]);
    MaxSubArray(Array, size);
}