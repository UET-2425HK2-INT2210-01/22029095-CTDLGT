#include <iostream>
using namespace std;

// Hàm đệ quy để tính x mũ n
double luyThua(int coSo, int mu) {
    if (mu == 0) return 1;

    double phanMu = luyThua(coSo, mu / 2);

    if (mu % 2 == 0)
        return phanMu * phanMu;
    else
        return coSo * phanMu * phanMu;
}

int main() {
    int coSo, mu;
    cin >> coSo >> mu;

    // Tính trị tuyệt đối của số mũ bằng tay (không dùng abs)
    int muDuong = (mu < 0) ? -mu : mu;

    double ketQua = luyThua(coSo, muDuong);

    if (mu < 0)
        cout << 1.0 / ketQua << endl;
    else
        cout << ketQua << endl;

    return 0;
}
