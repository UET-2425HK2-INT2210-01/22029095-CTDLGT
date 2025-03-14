#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;

    Node(int v) : value(v), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;  
    
public:
    LinkedList() : head(nullptr) {}

    //  (a) append x 
    void append(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    //  (b) search x 
    void search(int x) {
        Node* temp = head;
        int index = 1;
        while (temp) {
            if (temp->value == x) {
                cout << index << endl;
                return;
            }
            temp = temp->next;
            index++;
        }
        cout << "NO" << endl;
    }

    //  (c) reverse 
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Hàm in danh sách liên ket
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList list;

    string command;
    int x;

    for (int i = 0; i < n; ++i) {
        cin >> command;
        if (command == "append") {
            cin >> x;
            list.append(x);  
        } else if (command == "search") {
            cin >> x;
            list.search(x); 
        } else if (command == "reverse") {
            list.reverse();  
        }
    }
    list.printList(); 
    return 0;
}

