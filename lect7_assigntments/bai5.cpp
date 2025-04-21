#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), c(n, 0); // Mảng a là hoán vị, mảng c là bộ đếm (control array)
    for (int i = 0; i < n; ++i) { // Gán phần tử của hoán vị đầu tiên
        a[i] = i + 1;
    }

    // In hoán vị đầu tiên
    for (int x : a) cout << x << " ";
    cout << endl;

    int i = 0; // Gán i = 0
    while (i < n) {
        if (c[i] < i) { // Trường hợp c[i] < i
            if (i % 2 == 0) { // Nếu số chẵn
                swap(a[0], a[i]); // Đổi chỗ
            } else { // Nếu số lẻ
                swap(a[c[i]], a[i]); // Đổi chỗ
            }

            // In hoán vị tiếp theo
            for (int x : a) cout << x << " ";
            cout << endl;

            c[i]++; // Tăng giá trị của c[i]
            i = 0; // Quay lại đầu để xử lý hoán vị tiếp theo
        } else { // Trường hợp c[i] >= i
            c[i] = 0; // Reset lại bộ đếm c[i]
            i++; // Tiến tới phần tử tiếp theo
        }
    }

    return 0;
}
