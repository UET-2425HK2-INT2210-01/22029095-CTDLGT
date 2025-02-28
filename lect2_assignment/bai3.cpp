#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertEnd(int x) {
    Node* newNode = new Node{x, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

int countTriplets() {
    if (!head || !head->next || !head->next->next)
        return 0;
    
    int count = 0;
    Node* prev = head, *curr = head->next, *next = head->next->next;

    while (next) {
        if (prev->data + curr->data + next->data == 0)
            count++;
        prev = curr;
        curr = next;
        next = next->next;
    }
    return count;
}

int main() {
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        insertEnd(x);
    }
    cout << countTriplets() << endl;
    return 0;
}

