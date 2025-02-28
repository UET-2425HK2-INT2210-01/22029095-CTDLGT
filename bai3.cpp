#include <iostream>
using namespace std;
int count_triplets(int arr[], int n) {
    if (n < 3) return 0; 

    int count = 0;
    for (int i = 1; i < n - 1; i++) {
        if (arr[i - 1] + arr[i] + arr[i + 1] == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    
    int arr[n]; 

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }

   cout << count_triplets(arr, n) << endl;

    return 0;
}

