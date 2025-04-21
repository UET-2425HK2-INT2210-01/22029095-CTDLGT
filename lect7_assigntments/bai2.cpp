#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
    int m, n; // Khai báo số hàng và số cột
    cin >> m >> n; // Nhập kích thước ma trận

    vector<vector<int>> A(m, vector<int>(n)); // Ma trận đầu vào
    vector<vector<int>> prefix(m, vector<int>(n, 0)); // Ma trận prefix sum, khởi tạo giá trị ban đầu là 0

    // Nhập ma trận và tính toán prefix sum theo hàng
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j]; // Nhập giá trị vào ma trận A
            prefix[i][j] = A[i][j] + (j > 0 ? prefix[i][j - 1] : 0); // Tính prefix sum cho mỗi hàng
        }
    }

    int maxSum = INT_MIN; // Khởi tạo giá trị tổng lớn nhất ban đầu
    int finalTop = 0, finalLeft = 0, finalBottom = 0, finalRight = 0; // Khởi tạo tọa độ của kết quả

    // Duyệt qua tất cả các cặp cột
    for (int left = 0; left < n; left++) {
        for (int right = left; right < n; right++) {
            vector<int> temp(m, 0); // Tạo một vector tạm để lưu trữ tổng theo chiều dọc

            // Tính tổng dọc cho mỗi hàng giữa hai cột left và right
            for (int i = 0; i < m; i++) {
                temp[i] = prefix[i][right] - (left > 0 ? prefix[i][left - 1] : 0); // Lấy tổng cột con
            }

            // Áp dụng thuật toán Kadane để tìm tổng con lớn nhất trong dãy 1D (temp)
            int currentSum = 0, currentTop = 0;
            for (int i = 0; i < m; i++) {
                currentSum += temp[i];
                if (currentSum > maxSum) {
                    maxSum = currentSum;
                    finalTop = currentTop;
                    finalBottom = i;
                    finalLeft = left;
                    finalRight = right;
                }
                if (currentSum < 0) {
                    currentSum = 0;
                    currentTop = i + 1; // Cập nhật chỉ số đầu của dãy con khi gặp tổng âm
                }
            }
        }
    }

    // In kết quả (đánh số từ 1 như yêu cầu trong đề bài)
    cout << finalTop + 1 << " " << finalLeft + 1 << " "
         << finalBottom + 1 << " " << finalRight + 1 << " "
         << maxSum << endl;

    return 0;
}
