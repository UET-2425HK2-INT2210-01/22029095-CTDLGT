#include <iostream>
using namespace std;

// Hàm tính ước chung lớn nhất (GCD) của hai số
int findGCD(int a, int b) {
    // Sử dụng thuật toán Euclid để tính GCD
    while (b != 0) {
        int remainder = a % b; // Tính số dư
        a = b; // Gán a = b
        b = remainder; // Gán b = số dư
    }
    return a; // Trả về GCD
}

int main() {
    int num1, num2;
    cin >> num1 >> num2; // Nhập hai số
    cout << "GCD of " << num1 << " and " << num2 << " is " << findGCD(num1, num2) << endl; // In kết quả GCD
    return 0;
}
