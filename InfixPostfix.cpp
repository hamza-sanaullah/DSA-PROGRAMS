#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct stack
{
    int size;
    char *Arr;
    int top;
};

void removeSpaces(char *expression)
{
    int write_ptr = 0, read_ptr = 0;

    while (expression[read_ptr] != '\0')
    {
        if (expression[read_ptr] != ' ')
        { // Copy non-spaces
            expression[write_ptr++] = expression[read_ptr];
        }
        read_ptr++;
    }

    // Null-terminate the resulting string
    expression[write_ptr] = '\0';
}

char *removeParentheses(const char *infix)
{
    char *withoutParentheses = new char[strlen(infix) + 1];
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] != '(' && infix[i] != ')')
        {
            withoutParentheses[j++] = infix[i];
        }
    }
    withoutParentheses[j] = '\0';
    return withoutParentheses;
}

int PerformOperation(int a, int b, char op)
{
    if (op == '+')
    {
        return a + b;
    }
    else if (op == '-')
    {
        return a - b;
    }
    else if (op == '*')
    {
        return a * b;
    }
    else if (op == '/')
    {
        return a / b;
    }
    else
    {
        cout << "Invalid Operator\n";
        return 0;
    }
}

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
        // cout << "Inavlid Operator\n";
        return -1;
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
bool IsOperand(char ch)
{
    return (ch >= '0' && ch <= '9');
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

// Function to reverse a string with swapped parentheses
void reverseString(char *str)
{
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            str[i] = ')';
        }
        else if (str[i] == ')')
        {
            str[i] = '(';
        }
    }
}

void infixtopostfix(char *exp, char *postfix)
{
    struct stack sp;
    sp.size = 100;
    sp.Arr = new char[sp.size];
    sp.top = -1;
    postfix[sp.size];
    int j = 0;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (!Isoperator(exp[i]) && exp[i] != '(' && exp[i] != ')')
        {
            postfix[j] = exp[i];
            j++;
        }
        else if (IsEmpty(&sp))
        {
            push(&sp, exp[i]);
        }

        else if (exp[i] == '(')
        {
            push(&sp, exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (!IsEmpty(&sp) && sp.Arr[sp.top] != '(')
            {
                postfix[j] = pop(&sp);
                j++;
            }
            if (!IsEmpty(&sp) && sp.Arr[sp.top] == '(')
            {
                pop(&sp); // Remove '(' from stack
            }
        }
        else
        {
            while (!IsEmpty(&sp) && precedencecheck(sp.Arr[sp.top]) >= precedencecheck(exp[i]))
            {
                postfix[j] = pop(&sp);
                j++;
            }
            push(&sp, exp[i]);
        }
    }
    while (!IsEmpty(&sp))
    {
        postfix[j] = pop(&sp);
        j++;
    }
    postfix[j] = '\0';
    cout << "The Postfix Expression is "
         << " " << postfix << endl;
    delete sp.Arr;
}

int postfixevaluate(char *postfix)
{

    struct stack sp;
    sp.size = 100;
    sp.Arr = new char[sp.size];
    sp.top = -1;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (!Isoperator(postfix[i]))
        { // Use lowercase 'is' for function names
            push(&sp, postfix[i]);
        }
        else if (Isoperator(postfix[i]))
        {
            int op2 = pop(&sp) - '0';
            int op1 = pop(&sp) - '0';
            int result = PerformOperation(op1, op2, postfix[i]); // Convert operands to digits before operation
            push(&sp, result + '0');                                         // Convert result back to character before pushing
        }
    }

    int fresult = pop(&sp);
    return fresult - '0';
}
int prefixevaluate(char *prefix)
{

    struct stack sp;
    sp.size = 100;
    sp.Arr = new char[sp.size];
    sp.top = -1;
    int n = strlen(prefix);

    for (int i = n - 1; i >= 0; i--)
    {
        if (!Isoperator(prefix[i]))
        { // Use lowercase 'is' for function names
            push(&sp, prefix[i]);
        }
        else if (Isoperator(prefix[i]))
        {
            int op1 = pop(&sp);
            int op2 = pop(&sp);
            int result = PerformOperation(op1 - '0', op2 - '0', prefix[i]); // Convert operands to digits before operation
            push(&sp, result + '0');                                        // Convert result back to character before pushing
        }
    }

    int fresult = pop(&sp);
    return fresult - '0';
}

void infixToPrefix(char *infix)
{
    struct stack sp;
    sp.size = 100;
    sp.Arr = new char[sp.size];

    sp.top = -1;
    int k = 0;

    char *infixCopy = new char[strlen(infix) + 1];
    strcpy(infixCopy, infix);

    // Reverse the infix expression with parentheses intact
    reverse(infixCopy, infixCopy + strlen(infixCopy));
    reverseString(infixCopy);
    cout << "Reversed Infix Expression: " << infixCopy << endl;

    // Convert reverse infix expression to postfix using existing code
    char postfix[100];
    infixtopostfix(infixCopy, postfix);

    // Reverse the resulting postfix expression
    reverse(postfix, postfix + strlen(postfix));

    cout << "Prefix Expression without Parentheses: " << postfix << endl;
    int result = prefixevaluate(postfix); // Evaluate postfix expression

    cout << "The result of the prefix expression is: " << result << endl;

    // Free dynamically allocated memory
    delete[] infixCopy;
    delete[] sp.Arr;
}

int main()
{
    char expression[100];
    char postfix[100];

    int choice;
    int a = 0;
    while (a != 3)
    {
        cout << "1.Infix to Postfix\n2.Infix to Prefix\n3.Result of Postfix\n4.Exit\n";
        cin >> choice;
        cin.ignore();
        if (choice == 1)
        {
            cout << "Enter the Infix Expression\n";
            cin.getline(expression, sizeof(expression));
            removeSpaces(expression);

            infixtopostfix(expression, postfix);
        }
        else if (choice == 2)
        {
            cout << "Enter the Infix Expression\n";
            cin.getline(expression, sizeof(expression));
            removeSpaces(expression);

            infixToPrefix(expression);
        }
        else if (choice == 3)
        {
            infixtopostfix(expression, postfix);   // Convert infix to postfix and print
            int result = postfixevaluate(postfix); // Evaluate postfix expression

            cout << "The result of the postfix expression is: " << result << endl;
        }
        else if (choice == 4)
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