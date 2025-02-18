#include <iostream>
#include <cstring> // For memmove
using namespace std;

// Function to remove all spaces from a character array (in-place)
void removeSpaces(char* expression) {
    int write_ptr = 0, read_ptr = 0;

    while (expression[read_ptr] != '\0') {
        if (expression[read_ptr] != ' ') { // Copy non-spaces
            expression[write_ptr++] = expression[read_ptr];
        }
        read_ptr++;
    }

    // Null-terminate the resulting string
    expression[write_ptr] = '\0';
}

int main() {
    // char expression[] = "( 5 - 2 ) * 7";
    // removeSpaces(expression);

    // std::cout << "Expression without spaces: " << expression << std::endl;
    int a = 3;
    int b = 5;
    cout<<a/b;

    // (Optional) Further processing or evaluation of the expression

    return 0;
}
