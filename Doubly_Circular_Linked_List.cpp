#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void insertatStart(struct node *&Head)
{
    if (Head == NULL)
    {
        Head = new node;
        cout << "Enter the Data :\n";
        cin >> Head->data;
        Head->prev = Head;
        Head->next = Head;
    }
    else
    {
        struct node *pt = Head->prev;
        struct node *ptr = new node;
        cout << "Enter the Data :\n";
        cin >> ptr->data;
        ptr->prev = pt;
        ptr->next = Head;
        Head->prev = ptr;
        pt->next = ptr;
        Head = ptr;
    }
}

void insertatend(struct node *&Head)
{
    struct node *ptr = new node;
    cout << "Enter the Data :\n";
    cin >> ptr->data;
    struct node *temp = Head->prev;
    ptr->prev = temp;
    ptr->next = Head;
    Head->prev = ptr;
    temp->next = ptr;
}
void insertatindex(struct node *&Head, int index)
{
    if (Head == NULL)
    {
        cout << "Linked List is Empty\n";
    }
    else
    {
        int countindex = 0;
        struct node *current = Head;
        struct node *nnode = new node;
        cout << "Enter the Data ; \n";
        cin >> nnode->data;
        while (current->next != Head && countindex < index - 1)
        {
            current = current->next;
            countindex++;
        }
        nnode->prev = current;
        nnode->next = current->next;
        current->next->prev = nnode;
        current->next = nnode;
    }
}
void delatstart(struct node *&Head)
{
    if (Head == NULL)
    {
        cout << "Linked List is Empty\n";
        return;
    }
    struct node *pt = Head->prev;
    struct node *temp = Head;
    pt->next = temp->next;
    temp->next->prev = pt;
    Head = temp->next;
    delete temp;
}
void delatlast(struct node *Head)
{
    struct node *ptr = Head->prev;
    Head->prev = ptr->prev;
    ptr->prev->next = Head;
    delete ptr;
}
void delatindex(struct node *Head, int index)
{
    if (Head == NULL)
    {
        cout << "Linked List is Empty\n";
    }
    else
    {
        int countindex = 0;
        struct node *current = Head;

        while (current->next != Head && countindex < index - 1)
        {
            current = current->next;
            countindex++;
        }
        struct node *temp = current->next;
        current->next = temp->next;
        temp->next->prev = current;
        delete temp;
    }
}
void Searching(struct node *Head)
{
    struct node *temp = Head;
    int data;
    int count = 0;
    cout << "Enter the Number You want to search in the Linked List\n";
    cin >> data;

    if (Head == NULL)
    {
        cout << "Linked List is Empty";
    }
    else
    {
        do
        {
            if (temp->data == data)
            {
                cout << "Your Desired Number is at the index " << count << endl;
                return;
            }
            temp = temp->next;
            count++;
        } while (temp != Head);

        cout << "The Number is not Found\n";
    }
}
void display(struct node *&Head)
{
    if (Head == NULL)
    {
        cout << "Linked List is Empty\n";
    }
    else
    {
        struct node *temp = Head;
        do
        {
            cout << temp->data << endl;
            temp = temp->next;

        } while (temp != Head);
    }
}

int main()
{
    int a = 0;
    struct node *headd = NULL;
    while (a != 3)
    {
        int choice;
        cout << "1.Insert At Start\n2.Insert At End\n3.Traverse\n4.Insert At Specific Index\n5.Delete At Start\n6.Delete At Last\n7.Delete At index\n8.Searching\n9.Exit\n";
        cout << "Enter the choice\n";
        cin >> choice;
        if (choice == 1)
        {
            insertatStart(headd);
        }
        else if (choice == 2)
        {
            insertatend(headd);
        }
        else if (choice == 3)
        {
            display(headd);
        }
        else if (choice == 4)
        {
            int index;
            cout << "Enter the Desired Position\n";
            cin >> index;
            insertatindex(headd, index);
        }
        else if (choice == 5)
        {
            delatstart(headd);
        }
        else if (choice == 6)
        {
            delatlast(headd);
        }
        else if (choice == 7)
        {
            int index;
            cout << "Enter the Desired Position\n";
            cin >> index;
            delatindex(headd, index);
        }
        else if (choice == 8)
        {
            Searching(headd);
        }
        else if (choice == 9)
        {
            a = 3;
        }
        else
        {
            cout << "Invalid Input\n";
        }
    }

    return 0;
}