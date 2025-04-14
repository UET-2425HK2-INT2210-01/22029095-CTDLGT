#include <iostream>
#include <cmath> // dùng cho abs
using namespace std;

// Hàm đệ quy để tính x lũy thừa n
double luyThua(int coSo, int soMu) {
    if (soMu == 0) return 1; // Bất kỳ số nào mũ 0 đều bằng 1

    double phanMu = luyThua(coSo, soMu / 2); // Đệ quy tính nửa mũ

    if (soMu % 2 == 0) {
        return phanMu * phanMu; // Nếu số mũ chẵn
    } else {
        return coSo * phanMu * phanMu; // Nếu số mũ lẻ
    }
}

int main() {
    int coSoNhap, muNhap;
    cin >> coSoNhap >> muNhap;

    double ketQua = luyThua(coSoNhap, abs(muNhap)); // Lấy trị tuyệt đối nếu mũ âm

    if (muNhap < 0)
        cout << 1.0 / ketQua << endl; // Nếu mũ âm thì lấy nghịch đảo
    else
        cout << ketQua << endl;

    return 0;
}
