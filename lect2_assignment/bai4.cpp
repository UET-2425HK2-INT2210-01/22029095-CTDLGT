#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr, *rear = nullptr;

void enqueue(int x) {
    Node* newNode = new Node{x, nullptr};
    if (!rear) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void dequeue() {
    if (!front) return;
    Node* temp = front;
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
}

void printQueue() {
    Node* temp = front;
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
        if (op == "enqueue") {
            int x;
            cin >> x;
            enqueue(x);
        } else if (op == "dequeue") {
            dequeue();
        }
    }
    printQueue();
    return 0;
}

