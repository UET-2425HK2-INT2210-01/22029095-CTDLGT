#include <iostream>

using namespace std;

struct Node {
    int value, priority;
    Node* prev;
    Node* next;
    
    Node(int v, int p) {
        value = v;
        priority = p;
        prev = nullptr;
        next = nullptr;
    }
};

class PriorityQueue {
private:
    Node* head;

public:
    PriorityQueue() {
        head = nullptr;
    }

    //  (a) Th�m phan tu theo do uu ti�n 
    void push(int v, int p) {
        Node* newNode = new Node(v, p);
        
        if (!head || p > head->priority) { 
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->priority >= p) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next) temp->next->prev = newNode;
            temp->next = newNode;
        }
    }

    // (b) X�a phan tu c� do uu ti�n cao nhat 
    void pop() {
        if (head) {
            Node* temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
        }
    }

    // In danh s�ch
    void printQueue() {
        Node* temp = head;
        bool first = true;
        while (temp) {
            if (!first) cout << ", "; 
            cout << "(" << temp->value << ", " << temp->priority << ")";
            first = false;
            temp = temp->next;
        }
        cout << endl; 
    }
};

int main() {
    int n;
    cin >> n;
    PriorityQueue pq;

    while (n--) {
        string command;
        cin >> command;
        if (command == "enqueue") {
            int v, p;
            cin >> v >> p;
            pq.push(v, p);
        } else if (command == "dequeue") {
            pq.pop();
        }
    }

    pq.printQueue();
    return 0;
}

