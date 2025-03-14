#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    char data[1000]; 
    int index;       

public:
    Stack() {
        index = -1;
    }

    void push(char c) {
        if (index < 999) { 
            data[++index] = c; 
        }
    }

    char pop() {
        if (index >= 0) {
            return data[index--];
        }
        return '\0'; 
    }

    bool empty() {
        return index == -1;
    }
};

bool checkBrackets(const string& str) {
    Stack stack;
    
    for (char ch : str) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        } else {
            char last = stack.pop();
            if ((ch == ')' && last != '(') ||
                (ch == ']' && last != '[') ||
                (ch == '}' && last != '{')) {
                return false;
            }
        }
    }
    
    return stack.empty();
}

int main() {
    string input;
    cin >> input;
    
    if (checkBrackets(input)) {
        cout << "Valid\n";
    } else {
        cout << "Invalid\n";
    }
    
    return 0;
}

