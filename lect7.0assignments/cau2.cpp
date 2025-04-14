#include <iostream>
using namespace std;

// Hàm đệ quy để tính giai thừa
long tinhGiaiThua(int so) {
    // Trường hợp cơ sở: nếu so bằng 1 thì trả về 1
    if (so == 1) return 1;

    // Gọi đệ quy để tính: so! = so * (so - 1)!
    return so * tinhGiaiThua(so - 1);
}

int main() {
    // Đọc dữ liệu từ tập tin "ex2.txt"
    freopen("ex2.txt", "r", stdin);

    // Biến để lưu số nguyên đầu vào
    int soNguyen;

    // Nhập giá trị từ file
    cin >> soNguyen;

    // Xuất kết quả ra màn hình
    cout << "Giai thua cua so vua nhap la: " << tinhGiaiThua(soNguyen) << endl;

    return 0;
}
