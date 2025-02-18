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

int partition(int A[], int low, int high)
{
    int pivotIndex = low + rand() % (high - low + 1);
    // cout<<A[pivotIndex];
    int pivot = A[pivotIndex];
    swap(A[pivotIndex], A[low]);
    int i = low +1;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            
        }
    } while (i <= j);
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
    
}

void quicksort(int A[], int low, int high)
{
    int Partitionindex;
    
    if (low < high)
    {

        Partitionindex = partition(A, low, high);
        
        
        quicksort(A, low, Partitionindex - 1);
        quicksort(A, Partitionindex + 1, high);
        
    }
    
}

int main()
{
    int A[] = {3, -9, 4, -1, 2, 17, 20, 5,-7};
    int n = 9;
    cout << "The Original Array is" << endl;
    printarray(A, n);
    quicksort(A, 0, n - 1);
    cout << "The Sorted Array is" << endl;
    printarray(A, n);

    return 0;
}