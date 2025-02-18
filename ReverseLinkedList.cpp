#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

struct node *insertatend(struct node *Head)
{
    if (Head == NULL)
    {
        cout << "Linked List Is Empty";
        return Head;
    }

    struct node *temp = Head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    struct node *nnode = new node;
    cout << "Enter the data :\n";
    cin >> nnode->data;
    nnode->next = NULL;
    temp->next = nnode;
    return Head;
}

void display(struct node *Head)
{
    struct node *temp = Head->next;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void reverse(struct node *Head)
{
    int A[10];
    struct node *temp = Head->next;
    int i = 0;
    while (temp != NULL)
    {

        A[i] = temp->data;
        temp = temp->next;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        cout << A[j] << " ";
    }
    cout << "\n";
}

int main()
{
    struct node *head = new node;
    head->next = NULL;
    int a;
    while (a != 4)
    {
        int option;

        cout << "1.Insert at end\n2.Traverse\n3.Traverse In reverse\n4.Exit\n";
        cout << "Enter your choice\n";
        cin >> option;

        if (option == 1)
        {
            head = insertatend(head);
        }
        else if (option == 2)
        {
            display(head);
        }
        else if (option == 3)
        {
            reverse(head);
        }
        else if (option == 4)
        {
            a = 4;
        }
    }

    return 0;
}
