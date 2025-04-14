#include <iostream>
using namespace std;

// Hàm đệ quy tính giai thừa của một số nguyên dương
long long tinhGiaiThua(int x) {
    // Nếu x bằng 1 thì trả về 1 (trường hợp cơ sở)
    if (x == 1) return 1;

    // Gọi lại hàm để tính x! = x * (x-1)!
    return x * tinhGiaiThua(x - 1);
}

int main() {
    // Đọc dữ liệu đầu vào từ file ex2.txt
    freopen("ex2.txt", "r", stdin);

    int so;

    // Nhập giá trị từ file
    cin >> so;

    // Xuất kết quả ra màn hình
    cout << "Ket qua giai thua la: " << tinhGiaiThua(so) << endl;

    return 0;
}
