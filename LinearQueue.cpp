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
    if (q->f == q->r)
    {
        cout << "The Queue is Empty\n";
        return true;
    }
    else
    {
        cout << "The Queue is not Empty\n";
        return false;
    }
}
bool Isfull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        cout << "The Queue is Full\n";
        return true;
    }
    else
    {
        cout << "The Queue is not Full\n";
        return false;
    }
}
int Firstelement(struct queue *q)
{
    if (q->f != -1)
    {
        return q->Arr[q->f];
    }
    cout << "The Queue is Empty\n";
    return -1;
}
int Lastelement(struct queue *q)
{
    if (q->r != -1)
    {
        return q->Arr[q->r];
    }
    cout << "The Queue is Empty\n";
    return -1;
}
void Enqueue(struct queue *q, int val)
{
    if (!Isfull(q))
    {
        q->r++;
        q->Arr[q->r] = val;
        if (q->f == -1)
        {
            q->f = 0;
        }
    }
}
int Dequeue(struct queue *q)
{
    int val;
    if (!Isempty(q))
    {
        val = q->Arr[q->f];
        q->f++;

        if (q->f > q->r)
        {
            q->f = -1;
            q->r = -1;
        }
    }
    else
    {
        cout << "The Queue IS Empty\n";
    }
    return val;
}
void Display(struct queue *q)
{
    if (!Isempty(q))
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
    struct queue q;
    q.f = -1; // Initialize front
    q.r = -1; // Initialize rear
    cout << "Enter size of the queue: ";
    cin >> q.size;
    q.Arr = new int[q.size];

    int choice, val;
    do
    {
        cout << "1. Enqueue\n2. Dequeue\n3. First Element\n4. Last Element\n5. Display\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            Enqueue(&q, val);
            break;
        case 2:
            cout << "Dequeued element: " << Dequeue(&q) << endl;
            break;
        case 3:
            cout << "First element: " << Firstelement(&q) << endl;
            break;
        case 4:
            cout << "Last element: " << Lastelement(&q) << endl;
            break;
        case 5:
            cout << "Queue elements: ";
            Display(&q);
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 6);

    delete[] q.Arr; // Free allocated memory
    return 0;
}