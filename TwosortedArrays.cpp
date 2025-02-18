#include <iostream>
using namespace std;

void printarray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << " \n";
}

void merge(int A[], int B[], int n, int m)
{
    int i = 0, j = 0, k = 0;
    int C[m + n];

    while (i < n && j < m)
    {
        if (A[i] <= B[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }
    while (i < n)
    {
        C[k++] = A[i++];
    }
    while (j < m)
    {
        C[k++] = B[j++];
    }
    printarray(C, m + n);
}

int main()
{
    int arr[] = {70, 77, 80, 100};
    int arr1[] = {-5, 0, 3, 6};
    printarray(arr, 4);
    printarray(arr1, 4);
    merge(arr, arr1, 4, 4);

    return 0;
}