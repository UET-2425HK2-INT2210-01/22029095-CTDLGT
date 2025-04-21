#include <iostream>
using namespace std;

int main() {
    int a[100], num, n = 0; // Khai báo mảng tĩnh và biến đếm số lượng phần tử

    // Đọc các số từ đầu vào
    while (cin >> num) {
        a[n++] = num; // Đọc số và thêm vào mảng
    }

    // Sắp xếp mảng bằng thuật toán Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) {
                minIdx = j; // Cập nhật chỉ số của phần tử nhỏ nhất
            }
        }
        // Hoán đổi phần tử nhỏ nhất với phần tử tại vị trí i
        if (minIdx != i) {
            swap(a[i], a[minIdx]);
        }
    }

    // In kết quả đã sắp xếp ra màn hình
    for (int i = 0; i < n; i++) {
        cout << a[i]; // In ra số tại vị trí i
        if (i != n - 1) {
            cout << " "; // Thêm dấu cách giữa các số
        }
    }

    return 0;
}
