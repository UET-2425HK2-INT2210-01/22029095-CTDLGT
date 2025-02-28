#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int x) {
    Node* newNode = new Node{x, top};
    top = newNode;
}

void pop() {
    if (!top) return;
    Node* temp = top;
    top = top->next;
    delete temp;
}

void printStack() {
    Node* temp = top;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string op;
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            push(x);
        } else if (op == "pop") {
            pop();
        }
    }
    printStack();
    return 0;
}


