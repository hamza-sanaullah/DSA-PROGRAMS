#include <iostream>
using namespace std;

void printarray(int Arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << " \n";
}
void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[50];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
            
        }
        else
        {
            B[k++] = A[j++];
            
        }
    }
    while (i <= mid)
    {
        B[k++] = A[i++];
        
    }
    while (j <= high)
    {
        B[k++] = A[j++];
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high)
{
    int mid;

    if (low <high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}
int main()
{
    int A[] = {3, 9, 4, 1, 2, 17, 20, 5, 7};
    int n = 9;
    cout << "The Original Array is" << endl;
    printarray(A, n);
    mergeSort(A, 0, n - 1);
    cout << "The Sorted Array is" << endl;
    printarray(A, n);
    return 0;
}