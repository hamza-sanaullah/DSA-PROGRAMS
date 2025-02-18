#include <iostream>
using namespace std;

struct stack
{
    int size;
    char *Arr;
    int top;
};

void push(struct stack *sp, char val)
{
    if (sp->top != sp->size - 1)
    {
        sp->top++;
        sp->Arr[sp->top] = val;
    }
    else
    {
        cout << "The Stack is Full\n";
    }
}
char pop(struct stack *sp)
{
    if (sp->top != -1)
    {
        char val = sp->Arr[sp->top];
        sp->top--;
        return val;
    }
    else
    {
        cout << "The Stack is Empty\n";
        return '\0';
    }
}
void Single_parenthesischeck(char *exp)
{

    // int problemindex = -1;
    // char problematicBracket;
    struct stack *sp = new stack;
    sp->size = 100;
    sp->top = -1;
    sp->Arr = new char[sp->size];

    bool openingBracketFound = false;


    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, exp[i]);
            openingBracketFound = true;
        }
        else if (exp[i] == ')')
        {
            if (sp->top == -1)
            {
                cout << "The Parentheses are Not Valid (extra closing)\n";
                // problemindex = i;
                // problematicBracket = ')';
                break; // Exit the loop since error found
            }
            pop(sp);
        }
        else
        {
            continue;
        }
    }

    // Checking the Empty Stack Condition
    if (sp->top == -1 && openingBracketFound)
    {
        cout << "The Parentheses Are Valid\n";
    }
    else
    {
        // if (problemindex == -1)
        // {
            // cout << "The Parentheses Are not Valid (extra opening)\n";
            // problemindex = sp->top;
            // problematicBracket = sp->Arr[sp->top];
        // }
        // else
        // {
            cout << "The Parentheses Are not Valid (mismatched brackets)\n";
        // }
        // cout << "The Problematic Bracket is " << problematicBracket << " at index " << problemindex << endl;
    }
    delete sp->Arr;
    delete sp;
    // if (problemindex != -1)
    // {
    //     char prevChar = exp[problemindex - 1];
    //     char nextChar = exp[problemindex + 1];
    //     if ((prevChar == '(' && nextChar == ')') || (prevChar == ')' && nextChar == '('))
    //     {
    //         cout << "Error Type: Misplaced Bracket\n";
    //     }
    //     else if ((prevChar == '(' && nextChar != ')') || (prevChar != '(' && nextChar == ')'))
    //     {
    //         cout << "Error Type: Missed Bracket\n";
    //     }
    // }
}

void Multiple_parenthesischeck(char *exp)
{
    struct stack *sp = new stack;
    sp->size = 100;
    sp->top = -1;
    sp->Arr = new char[sp->size];
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (sp->top == -1)
            {
                cout << "The Parentheses are not Valid (extra closing)\n";
            }

            char popped = pop(sp);

            if ((popped == '(' && exp[i] != ')') ||
                (popped == '[' && exp[i] != ']') ||
                (popped == '{' && exp[i] != '}'))
            {
                 cout << "The Parentheses are not Valid (mismatched brackets)\n";
                return;
            }
        }
    }
    if (sp->top == -1)
    {
        cout << "The Parenthesis Are Valid\n";
    }
    else
    {
        cout << "The Parentheses are not Valid (extra opening)\n";
    }
    delete sp->Arr;
    delete sp;
}

int main()
{
    struct stack *sp = new stack;
    sp->size = 100;
    sp->top = -1;
    sp->Arr = new char[sp->size];
    int a = 0;
    while (a != 3)
    {
        int choice;
        cout << "1.Single Parenthesis Checker\n2.Multiple Parenthesis Checker\n3.Exit\n";
        cout << "Enter the Choice\n";
        cin >> choice;
        cin.ignore();
        if (choice == 1)
        {
            cout << "Enter the expression: ";

            cin.getline(sp->Arr, 100);
            Single_parenthesischeck(sp->Arr);
        }
        else if (choice == 2)
        {
            cout << "Enter the expression: ";
            cin.getline(sp->Arr, 100);
            Multiple_parenthesischeck(sp->Arr);
        }
        else if (choice == 3)
        {
            a = 3;
        }
        else
        {
            cout << "Invalid Input\n";
        }
    }
    delete sp;
}