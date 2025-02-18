#include <iostream>
using namespace std;

struct stack
{
    int size;
    char *Arr;
    int top;
};

int precedencecheck(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

bool Isoperator(char opr)
{
    if (opr == '+' || opr == '-' || opr == '*' || opr == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsEmpty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsFull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(struct stack *sp, char val)
{
    if (!IsFull(sp))
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
    if (!IsEmpty(sp))
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

string infixToPostfix(const string& infix)
{
    struct stack sp;
    sp.size = infix.length();
    sp.Arr = new char[sp.size];
    sp.top = -1;
    string postfix;
    
    for (char c : infix)
    {
        if (!Isoperator(c))
        {
            postfix.push_back(c);
        }
        else
        {
            while (!IsEmpty(&sp) && precedencecheck(sp.Arr[sp.top]) >= precedencecheck(c))
            {
                postfix.push_back(pop(&sp));
            }
            push(&sp, c);
        }
    }

    while (!IsEmpty(&sp))
    {
        postfix.push_back(pop(&sp));
    }

    delete[] sp.Arr;

    return postfix;
}

int main()
{
    string infix = "2+(5/3)*9";
    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression (Without Parentheses): " << postfix << endl;
    return 0;
}
