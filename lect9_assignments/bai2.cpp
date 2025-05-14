#include <iostream>      // Thư viện hỗ trợ nhập xuất
#include <vector>        // Thư viện làm việc với mảng động (vector)

using namespace std;

// Hàm sử dụng quy hoạch động để kiểm tra xem có tồn tại tập con có tổng bằng X không
bool checkSubsetSum(const vector<int>& arr, int n, int target) {
    // Tạo bảng dp, dp[i][j] cho biết có thể tạo tổng j với i phần tử đầu tiên hay không
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Tổng bằng 0 thì luôn đúng (bằng cách không chọn phần tử nào)
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Duyệt qua các phần tử và giá trị tổng
    for (int i = 1; i <= n; ++i) {
        for (int sum = 1; sum <= target; ++sum) {
            if (sum >= arr[i - 1]) {
                // Có thể chọn hoặc không chọn phần tử arr[i-1]
                dp[i][sum] = dp[i - 1][sum] || dp[i - 1][sum - arr[i - 1]];
            } else {
                // Không đủ để chọn arr[i-1], giữ nguyên giá trị từ dòng trên
                dp[i][sum] = dp[i - 1][sum];
            }
        }
    }

    return dp[n][target];
}

int main() {
    int n, targetSum;
    cin >> n >> targetSum; // Nhập số phần tử và tổng cần kiểm tra

    vector<int> ages(n); // Mảng lưu độ tuổi hoặc giá trị cần xét
    for (int i = 0; i < n; ++i) {
        cin >> ages[i];
    }

    // Kiểm tra và in kết quả
    if (checkSubsetSum(ages, n, targetSum)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
