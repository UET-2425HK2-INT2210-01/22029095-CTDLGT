#include <iostream>
using namespace std;

// Hàm đệ quy để tính số Fibonacci tại vị trí k
int fibonacci(int k) {
    if (k == 0) return 0; // Trường hợp cơ bản
    if (k == 1) return 1; // Trường hợp cơ bản
    return fibonacci(k - 1) + fibonacci(k - 2); // Gọi đệ quy
}

int main() {
    int viTri;
    cin >> viTri;

    // In ra kết quả số Fibonacci tương ứng
    cout << "So Fibonacci tai vi tri " << viTri << " la: " << fibonacci(viTri) << endl;

    return 0;
}
