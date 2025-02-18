#include <iostream>
#include <ctime> // For clock
#include <cstdlib> // For rand
#include <iomanip>
using namespace std;

void printarray(int Arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << " \n";
}

void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (A[i] < A[j])
            {
                swap(A[i], A[j]);
                i = j;
            }
            else
            {
                break;
            }
        }
    }
}
int main()
{
    int A[] = {4,5,6,91,1};
    int n = 5;
    // cout << "The Original Array is" << endl;
    clock_t start = clock();
    InsertionSort(A, n);
    clock_t end = clock();
    double  time_taken = double (end - start) / CLOCKS_PER_SEC;
    // printarray(A, n);
    // InsertionSort(A, n);
    // cout << "The Sorted Array is" << endl;
    printarray(A, n);
    cout << "Execution Time: " << fixed << time_taken <<setprecision(5)<< " seconds" << endl;
    return 0;
}