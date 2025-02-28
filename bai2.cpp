#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;

    int arr[1000]; 
    int size = 0;  

    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;

        if (op == "insert") {
            int p, x;
           cin >> p >> x;

          
            for (int j = size; j > p; j--) {
                arr[j] = arr[j - 1];
            }
            arr[p] = x;
            size++; 
        } 
        else if (op == "delete") {
            int p;
            cin >> p;

            
            for (int j = p; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--; 
        }
    }

 
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
   cout <<endl;

    return 0;
}

