#include <iostream>
using namespace std;

// Hàm đệ quy để tính tổng các số từ 1 đến x
int tinhTong(int x) {
    if (x == 0) return 0; // Trường hợp cơ bản: tổng từ 1 đến 0 là 0
    return x + tinhTong(x - 1); // Gọi lại chính hàm với (x - 1)
}

int main() {
    int soNhap;
    cin >> soNhap;

    // Xuất tổng từ 1 đến số đã nhập
    cout << "Tong tu 1 den " << soNhap << " la: " << tinhTong(soNhap) << endl;

    return 0;
}
