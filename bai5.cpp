#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int stack[1000]; 
    int top = -1;   

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;

        if (op == "push") {
            int x;
            cin >> x;
            stack[++top] = x; 
        } 
        else if (op == "pop") {
            if (top >= 0) {
                top--; 
            }
        }
    }

  
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;

    return 0;
}

