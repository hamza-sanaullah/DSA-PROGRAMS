#include <iostream>
using namespace std;
struct queue
{
    int f;
    int r;
    int size;
    int *Arr;
};

bool Isempty(struct queue *q)
{
    if (q->f == -1 && q->r == -1)
    {
        cout << "The Queue is Empty\n";
        return true;
    }
    else
    {
        cout << "The Queue is Not Empty\n";
        return false;
    }
}
bool Isfull(struct queue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        cout << "The Queue is Full\n";
        return true;
    }
    else
    {
        cout << "The Queue is Not Full\n";
        return false;
    }
}
void Enqueue(struct queue *q, int val)
{
    if ((q->r + 1) % q->size == q->f)
    {
        cout << "The Queue is Full\n";
    }
    else
    {
        if (q->f == -1)
            q->f = 0;
        q->r = (q->r + 1) % q->size;
        q->Arr[q->r] = val;
    }
}

int Dequeue(struct queue *q)
{
    if (q->f == -1 && q->r == -1)
    {
        cout << "The Queue is Empty";
    }
    else
    {
        int val = q->Arr[q->f];
        if (q->f == q->r)
            q->f = q->r = -1;
        else
            q->f = (q->f + 1) % q->size;

        return val;
    }
}

int FirstElement(struct queue *q)
{
    if (q->f != -1)
    {

        return q->Arr[q->f];
    }
    return -1;
}
int LastElement(struct queue *q)
{
    if (q->r != -1)
    {

        return q->Arr[q->r];
    }
    return -1;
}

void Display(struct queue *q)
{
    if (q->f == -1 && q->r == -1)
    {
        cout << "The Queue is Empty\n";
    }
    else
    {
        for (int i = 0; i < q->size; i++)
        {
            cout << q->Arr[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    struct queue *q = new queue;
    q->f = -1; // Initialize front
    q->r = -1; // Initialize rear
    cout << "Enter size of the queue: ";
    cin >> q->size;
    q->Arr = new int[q->size];

    int choice, val;
    do
    {
        cout << "1. Enqueue\n2. Dequeue\n3. First Element\n4. Last Element\n5. Display\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value to enqueue: ";
            cin >> val;
            Enqueue(q, val);
        }
        else if (choice == 2)
        {
            cout << "Dequeued element: " << Dequeue(q) << endl;
        }
        else if (choice == 3)
        {
            cout << "First element: " << FirstElement(q) << endl;
        }
        else if (choice == 4)
        {
            cout << "Last element: " << LastElement(q) << endl;
        }
        else if (choice == 5)
        {
            cout << "Queue elements: ";
            Display(q);
        }
        else if (choice == 6)
        {
            cout << "Exiting...\n";
        }
        else
        {
            cout << "Invalid choice\n";
        }
    } while (choice != 6);

    delete[] q->Arr; // Free allocated memory
    delete q;
    return 0;
}