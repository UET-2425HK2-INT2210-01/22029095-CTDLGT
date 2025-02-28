#include <iostream>
using namespace std;
int main() {
    int n;
   cin >> n;

    int queue[1000]; 
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;

        if (op == "enqueue") {
            int x;
          cin >> x;
            queue[rear++] = x; 
        } 
        else if (op == "dequeue") {
            if (front < rear) {
                front++; 
            }
        }
    }

  
    for (int i = front; i < rear; i++) {
        cout << queue[i] << " ";
    }
   cout << endl;

    return 0;
}

