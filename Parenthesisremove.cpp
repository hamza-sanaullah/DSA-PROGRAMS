#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string removeParentheses(const string& infix) {
    string withoutParentheses = infix;
    withoutParentheses.erase(remove_if(withoutParentheses.begin(), withoutParentheses.end(),
                                       [](char c) { return c == '(' || c == ')'; }),
                             withoutParentheses.end());
    return withoutParentheses;
}

int main() {
    string infixExpression = "(a + b) * c";
    string withoutParentheses = removeParentheses(infixExpression);
    cout << "Original Infix Expression: " << infixExpression << endl;
    cout << "Infix Expression without Parentheses: " << withoutParentheses << endl;

    return 0;
}
