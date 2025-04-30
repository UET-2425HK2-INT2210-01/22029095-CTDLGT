#include <iostream>
using namespace std;

int main() {
    int n, x; // n: số đồ vật, x: trọng lượng tối đa có thể mang
    cin >> n >> x;

    // Tạo mảng 2 chiều để lưu trọng lượng và giá trị từng đồ vật
    int** vat = new int*[n + 1]; // vat[i][0]: trọng lượng, vat[i][1]: giá trị

    for (int i = 1; i <= n; ++i) {
        vat[i] = new int[2];
        cin >> vat[i][0] >> vat[i][1]; // Nhập trọng lượng và giá trị của đồ vật thứ i
    }

    // Tạo bảng động để tính giá trị tối ưu
    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; ++i) {
        dp[i] = new int[x + 1];
        for (int j = 0; j <= x; ++j)
            dp[i][j] = 0; // Khởi tạo giá trị ban đầu là 0
    }

    // Bắt đầu tính toán
    for (int i = 1; i <= n; ++i) {           // Xét từng đồ vật
        for (int j = 1; j <= x; ++j) {       // Với từng mức trọng lượng từ 1 đến x
            if (vat[i][0] > j) {
                dp[i][j] = dp[i - 1][j];     // Không thể chọn đồ vật i (vì quá nặng)
            } else {
                // Chọn giá trị tốt nhất: mang hoặc không mang đồ vật i
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vat[i][0]] + vat[i][1]);
            }
        }
    }

    // Xuất kết quả là giá trị lớn nhất có thể đạt được
    cout << dp[n][x] << "\n";

    // Giải phóng bộ nhớ
    for (int i = 1; i <= n; ++i)
        delete[] vat[i];
    delete[] vat;

    for (int i = 0; i <= n; ++i)
        delete[] dp[i];
    delete[] dp;

    return 0;
}
