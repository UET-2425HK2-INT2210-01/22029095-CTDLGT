#include <iostream> // Thư viện nhập xuất cơ bản
using namespace std;

int main() {
    int n, tongTuoi; // n: số học sinh, tongTuoi: tổng tuổi cần kiểm tra
    cin >> n >> tongTuoi;

    // Tạo mảng đánh dấu tuổi có thể tạo thành từ tổng các tuổi đã nhập
    bool* coTheTao = new bool[tongTuoi + 1];
    for (int i = 0; i <= tongTuoi; ++i)
        coTheTao[i] = false; // Khởi tạo tất cả là false

    coTheTao[0] = true; // Luôn có thể tạo ra tổng bằng 0 (không chọn ai)

    int* tuoi = new int[n]; // Mảng lưu tuổi từng học sinh
    for (int i = 0; i < n; ++i) {
        cin >> tuoi[i]; // Nhập tuổi

        // Nếu tuổi học sinh nhỏ hơn hoặc bằng tổng cần tìm, đánh dấu là có thể tạo
        if (tuoi[i] <= tongTuoi)
            coTheTao[tuoi[i]] = true;
    }

    // Xét từng tuổi và cập nhật các giá trị tổng có thể tạo ra
    for (int i = 0; i < n; ++i) {
        for (int j = tongTuoi; j >= tuoi[i]; --j) {
            // Nếu j - tuổi hiện tại đã có thể tạo ra => j cũng có thể tạo ra
            if (coTheTao[j - tuoi[i]])
                coTheTao[j] = true;
        }
    }

    // Nếu có thể tạo ra tổng đúng bằng tongTuoi thì in YES
    if (coTheTao[tongTuoi])
        cout << "YES";
    else
        cout << "NO";

    // Giải phóng bộ nhớ
    delete[] coTheTao;
    delete[] tuoi;

    return 0; // Kết thúc chương trình
}
