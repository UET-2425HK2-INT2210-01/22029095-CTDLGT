#include <iostream>
using namespace std;

// Hàm đệ quy để tính giai thừa của một số nguyên dương
int tinhGiaiThua(int so) {
    if (so == 1) return 1; // Trường hợp cơ bản: 1! = 1
    return so * tinhGiaiThua(so - 1); // Gọi đệ quy
}

int main() {
    int giaTriNhap;
    cin >> giaTriNhap;

    // In kết quả ra màn hình
    cout << "Giai thua cua " << giaTriNhap << " la: " << tinhGiaiThua(giaTriNhap) << endl;

    return 0;
}
