
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string input;
    cout << "Enter a line of code: ";
    getline(cin, input);  // Read a whole line from the user

    string lexeme = "";

    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];

        // Skip spaces
        if (isspace(ch)) {
            continue;
        }

        // Identifier
        if (isalpha(ch) || ch == '_') {
            lexeme = ch;
            i++;
            while (i < input.length() && (isalnum(input[i]) || input[i] == '_')) {
                lexeme += input[i];
                i++;
            }
            i--;
            cout << "IDENTIFIER: " << lexeme << endl;
        }

        // Number
        else if (isdigit(ch)) {
            lexeme = ch;
            i++;
            while (i < input.length() && isdigit(input[i])) {
                lexeme += input[i];
                i++;
            }
            i--;
            cout << "NUMBER: " << lexeme << endl;
        }

        // Operator or Symbol
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' ||
                 ch == '(' || ch == ')') {
            cout << "OPERATOR or SYMBOL: " << ch << endl;
        }

        // Unknown character
        else {
            cout << "UNKNOWN: " << ch << endl;
        }
    }

    return 0;
}
 


