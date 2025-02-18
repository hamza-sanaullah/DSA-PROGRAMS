#include <iostream>
#include <conio.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
    //	Self Refrencing Pointer Node having Node Pointer
};
struct node *insertatstart(struct node *Head)
{
    if (Head == NULL)
    {
        Head = new node;
        cout << "Enter the Data";
        cin >> Head->data;
        Head->next = NULL;
        return Head;
    }
    else
    {
        struct node *temp;
        temp = new node;
        cout << "Enter the Data";
        cin >> temp->data;
        temp->next = Head;
        return temp;
    }
}
struct node *insertatend(struct node *Head)
{
    if (Head->next == NULL)
    {
        struct node *temp;
        temp = new node;
        cout << "Enter the Data";
        cin >> temp->data;
        Head->next = temp;
        temp->next = NULL;
        return Head;
    }
}

struct node *insertinbet(struct node *Head, int index)
{
    if (Head == NULL)
    {
        cout << "Linked List is Empty\n";
        return NULL;
    }
    int countindex = 0;
    struct node *current = Head;

    while (current->next != NULL && countindex < index - 1)
    {

        current = current->next;
        countindex++;
    }

    struct node *temp;
    temp = new node;
    cout << "Enter the Data";
    cin >> temp->data;
    temp->next = current->next;
    current->next = temp;

    return Head;
}
struct node *delatstart(struct node *Head)
{
    if (Head == NULL)
    {
        cout << "Linked List is Empty\n";
    }
    else
    {
        struct node *temp = Head;
        Head = Head->next;

        delete temp;
        return Head;
    }
}
struct node *delatend(struct node *Head)
{

    struct node *p = Head;
    struct node *q = Head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    delete q;
    return Head;
}
struct node *delinbet(struct node *Head, int index)
{
    if (Head == NULL)
    {
        cout << "Linked List is Empty\n";
        return NULL;
    }
    int countindex = 0;
    struct node *current = Head;

    while (current->next != NULL && countindex < index - 1)
    {

        current = current->next;
        countindex++;
    }

    struct node *temp;

    temp = current->next;
    current->next = temp->next;
    delete temp;

    return Head;
}

void display(struct node *jj)
{
    if (jj == NULL)
    {
        cout << "Linked List is Empty";
    }
    else
    {
        while (jj->next != NULL)
        {
            cout << jj->data << endl;
            jj = jj->next;
        }
        cout << jj->data << endl;
    }
}
struct node *searchvalue(struct node *Head)
{
    int Number, count;
    cout << "Enter the Number You want to search in the Linked List\n";
    cin >> Number;

    if (Head == NULL)
    {
        cout << "Linked List is Empty";
    }
    else
    {
        while (Head->next != NULL)
        {

            Head = Head->next;
            count++;
        }
        if (Head->data == Number)
        {
            cout << "Your Desired Number is Found At the index"
                 << " " << count << endl;
        }
        else
        {
            cout << "The Number is Not Found\n";
        }
    }
}

int main()
{
    int a = 0;
    struct node *head = NULL;
    while (a != 3)
    {
        int choice;
        cout << "1.Insert at start\n2.Traverse\n3.Insert At End\n4.Insert In Between\n5.Del At Start\n6.Del at End\n7.Del In Between\n8.SearchValue\n9.Exit\n";
        cout << "Enter Choice: \n";
        cin >> choice;
        if (choice == 1)
        {
            head = insertatstart(head);
        }
        else if (choice == 2)
        {
            display(head);
        }
        else if (choice == 3)

        {
            head = insertatend(head);
        }
        else if (choice == 4)

        {
            int index;
            cout << "Enter the Desired Position\n";
            cin >> index;
            head = insertinbet(head, index);
        }
        else if (choice == 5)

        {

            head = delatstart(head);
        }
        else if (choice == 6)

        {

            head = delatend(head);
        }
        else if (choice == 7)

        {
            int index;
            cout << "Enter the desired Position\n";
            cin >> index;

            head = delinbet(head, index);
        }
        else if (choice == 8)

        {
            head = searchvalue(head);
        }
        else if (choice == 9)

        {
            a = 3;
        }
        else
        {
            cout << "Invalid Input, Try again";
        }
    }

    getch();
    return 0;
}