#include <iostream>
using namespace std;

struct MyArray
{
    int Total_size;
    int used_size;
    int *ptr;
    int count = 0;
};
void CreateArray(struct MyArray *Arr)
{
    cout << "Enter the Total size of the array you want to create\n";
    cin >> Arr->Total_size;
    cout << "Enter Number of Elements You want ot insert\n";
    cin >> Arr->used_size;
    Arr->ptr = new int[Arr->Total_size];
    // cout << Arr->Total_size << endl;
}

void insert(struct MyArray *Arr)
{
    for (int i = 0; i < Arr->used_size; i++)
    {

        if (Arr->count >= int(0.7 * Arr->Total_size))
        {
            int *ptr2;
            ptr2 = new int[Arr->Total_size * 2];
            for (int i = 0; i < Arr->used_size; i++)
            {
                ptr2[i] = Arr->ptr[i];
            }
            delete[] Arr->ptr;
            Arr->ptr = ptr2;
            Arr->Total_size *= 2;
        }

        cout << "Enter the"
             << " " << i << " "
             << "Element of the Array\n";
        cin >> Arr->ptr[i];
        Arr->count++;
        // cout<<Arr->count;
    }
}

void getElement(struct MyArray *Arr)
{
    int index;
    cout << "Enter the Index of the Element You Want\n";
    cin >> index;
    cout << Arr->ptr[index] << endl;
}
void display(struct MyArray *Arr)
{
    if (Arr->used_size > 0)
    {
        int limit = (Arr->count >= 0.7 * Arr->Total_size ? Arr->Total_size : Arr->used_size);
        for (int i = 0; i < limit; i++)
        {
            cout << Arr->ptr[i] << endl;
        }
    }
    else
    {
        cout << "The Array is Empty\n";
    }
}
void setelement(struct MyArray *Arr)
{
    cout << Arr->Total_size << endl;
    int index;
    int number;
    cout << "Enter the index of the element you want to Set in the array\n";
    cin >> index;
    cout << "Enter the Number you want to Set in the array at a specific Index\n";
    cin >> number;
    if (index >= 0 && index <= Arr->used_size)
    {
        for (int i = Arr->used_size; i > index; i--)
        {
            Arr->ptr[i] = Arr->ptr[i - 1];
        }
        Arr->ptr[index] = number;
        Arr->used_size++;
        display(Arr);
    }
    else if (index >= Arr->used_size && index < Arr->Total_size)
    {
        Arr->ptr[index] = number;
        Arr->used_size++;
        for (int i = 0; i < Arr->Total_size; i++)
        {
            cout << Arr->ptr[i] << endl;
        }
    }
    else
    {
        cout << "There is no spcae in the Array to insert Elements";
    }
}
void delelement(struct MyArray *Arr)
{
    int del;
    cout << "Enter the index of the Element Where you want to delete the Element\n";
    cin >> del;
    if (del >= 0 && del <= Arr->used_size)
    {

        for (int i = del; i < Arr->used_size; i++)
        {
            Arr->ptr[i] = Arr->ptr[i + 1];
        }
        Arr->used_size--;
        display(Arr);
    }
    else if (del >= Arr->used_size && del < Arr->Total_size)
    {
        for (int i = del; i < Arr->Total_size; i++)
        {
            Arr->ptr[i] = Arr->ptr[i + 1];
        }
        Arr->used_size--;
        for (int i = 0; i < Arr->Total_size; i++)
        {
            cout << Arr->ptr[i] << endl;
        }
    }
}
void Max(struct MyArray *Arr)
{
    if (Arr->used_size > 0)
    {
        int max = Arr->ptr[0];

        for (int i = 1; i < Arr->Total_size; i++)
        {
            if (max < Arr->ptr[i])
            {
                max = Arr->ptr[i];
            }
        }

        cout << "The Maximum Element of the Array is"
             << " " << max << " ";
    }
}

int main()
{
    struct MyArray a;
    CreateArray(&a);
    insert(&a);
    int opt;
    cout << "You Have the Following options to do\n1.GetTheElement\n2.DisplayElements\n3.DelElement\n4.SetElement\n5.MaxElement\n";
    cin >> opt;
    if (opt = 1)
    {
        getElement(&a);
    }
    else if (opt = 2)
    {
        display(&a);
    }
    else if (opt = 3)
    {
        setelement(&a);
    }
    else if (opt = 4)
    {
        delelement(&a);
    }
    else if (opt = 5)
    {
        Max(&a);
    }

    delete[] a.ptr;

    return 0;
}