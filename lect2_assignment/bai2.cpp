#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insert(int pos, int x) {
    Node* newNode = new Node{x, nullptr};
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    for (int i = 0; temp && i < pos - 1; i++)
        temp = temp->next;
    if (!temp) return; 
    newNode->next = temp->next;
    temp->next = newNode;
}

void del(int pos) {
    if (!head) return;
    Node* temp = head;
    if (pos == 0) {
        head = head->next;
        delete temp;
        return;
    }
    Node* prev = nullptr;
    for (int i = 0; temp && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) return;
    prev->next = temp->next;
    delete temp;
}

void printList() {
    Node* temp = head;
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
        if (op == "insert") {
            int p, x;
            cin >> p >> x;
            insert(p, x);
        } else if (op == "delete") {
            int p;
            cin >> p;
            del(p);
        }
    }
    printList();
    return 0;
}


