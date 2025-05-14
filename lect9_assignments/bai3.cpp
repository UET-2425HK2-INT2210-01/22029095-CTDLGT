#include <iostream>      // Thư viện nhập xuất cơ bản
#include <vector>        // Dùng để khai báo mảng động
#include <algorithm>     // Dùng hàm max

using namespace std;

int main() {
    int itemCount, maxWeight;
    cin >> itemCount >> maxWeight; // Nhập số vật và trọng lượng cho phép

    vector<int> weights(itemCount); // Lưu trọng lượng từng vật
    vector<int> profits(itemCount); // Lưu giá trị (hoặc lợi ích) của từng vật

    // Nhập thông tin từng món đồ
    for (int i = 0; i < itemCount; ++i) {
        cin >> weights[i] >> profits[i];
    }

    // dp[w] sẽ lưu giá trị tối đa có thể đạt được với trọng lượng tối đa là w
    vector<int> dp(maxWeight + 1, 0);

    // Duyệt từng vật phẩm
    for (int i = 0; i < itemCount; ++i) {
        // Duyệt ngược để đảm bảo không chọn một món nhiều lần
        for (int w = maxWeight; w >= weights[i]; --w) {
            dp[w] = max(dp[w], dp[w - weights[i]] + profits[i]);
        }
    }

    // In kết quả cuối cùng: giá trị tối đa có thể đạt được
    cout << dp[maxWeight] << '\n';

    return 0;
}
