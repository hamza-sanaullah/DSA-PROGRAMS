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
        Head->next = Head;
        return Head;
    }
    else
    {
        struct node *temp = Head;
        struct node *nnode = new node;
        cout << "Enter the Data";
        cin >> nnode->data;
        nnode->next = Head;
        while (temp->next!=Head)
        {
            temp = temp->next;
        }
        temp->next = nnode;
        Head = nnode;
        
        
        return Head;
    }
}
struct node *insertatend(struct node *Head)
{
    struct node * temp = Head;
    while (temp->next!=Head)
    {
        temp = temp->next;
    }
        struct node* nnode = new node;
    
        
        
        cout << "Enter the Data";
        cin >> nnode->data;
        nnode->next = temp->next;
        temp->next = nnode;
        
        return Head;
    
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

    while (current->next != Head && countindex < index - 1)
    {

        current = current->next;
        countindex++;
    }

    struct node *temp = new node;
    
    cout << "Enter the Data";
    cin >> temp->data;
    temp->next = current->next;
    current->next = temp;

    return Head;
}

struct node *delatstart(struct node *Head)
{
    
        struct node *temp = Head;
        while(temp->next!=Head){
            temp = temp->next;
        }
        temp->next = Head->next;
        Head = temp->next;
        delete Head;
        return temp;
    
}

struct node *delatend(struct node *Head)
{

    struct node *p = Head;
    struct node *q = Head->next;
    while (q->next != Head)
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

    while (current->next != Head && countindex < index - 1)
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
        struct node*jk = jj;
        while (jk->next != jj)
        {
            cout << jk->data << endl;
            jk = jk->next;
        }
        cout << jk->data << endl;
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
        // else if (choice == 8)

        // {
        //     head = searchvalue(head);
        // }
        else if (choice == 9)

        {
            a = 3;
        }
        else
        {
            cout << "Invalid Input, Try again";
        }
    }

    return 0;
}