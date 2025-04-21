#include <iostream>
#include <bitset>
#include <string>
#include <cmath>
using namespace std;

// Hàm chuyển số thập phân sang nhị phân dạng chuỗi có length bit
string toBinary(int num, int totalBits) {
    string binary = bitset<64>(num).to_string();  // Tối đa 64 bit
    // Lấy phần bên phải có totalBits độ dài
    return binary.substr(64 - totalBits);
}

// Hàm nhóm chuỗi nhị phân theo sizePerGroup (vd 8, 4, 16...)
string formatBinaryGroup(const string& bin, int sizePerGroup) {
    string result;
    int len = bin.length();
    for (int i = 0; i < len; i++) {
        result += bin[i];
        // Nếu đến cuối một nhóm và chưa hết chuỗi, thêm khoảng trắng
        if ((i + 1) % sizePerGroup == 0 && i + 1 < len) {
            result += ' ';
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n; // Nhập vào số lượng bit

    // Tính giá trị tối đa của số nhị phân có n bit
    int maxbinary = (1 << n) - 1; // maxbinary = 2^n - 1

    // Duyệt qua tất cả các giá trị từ 0 đến maxbinary
    for (int i = 0; i <= maxbinary; i++) {
        string binary = toBinary(i, n); // Chuyển đổi số thập phân thành nhị phân
        string formattedBinary = formatBinaryGroup(binary, 4); // Định dạng nhị phân theo nhóm 4 bit
        cout << formattedBinary << endl; // In ra chuỗi nhị phân đã được định dạng
    }

    return 0;
}
