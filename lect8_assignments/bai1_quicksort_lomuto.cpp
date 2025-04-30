#include <iostream> // Thư viện hỗ trợ nhập xuất dữ liệu
using namespace std;

// Hàm phân chia theo cách Lomuto
int lomutoPartition(float a[], int l, int r) {
    float pivot = a[r]; // Chọn phần tử cuối cùng làm pivot (chốt)
    int i = l - 1;       // i là chỉ số của phần tử cuối cùng nhỏ hơn pivot

    // Duyệt qua các phần tử từ l đến r-1
    for (int j = l; j < r; ++j) {
        if (a[j] <= pivot) { // Nếu phần tử nhỏ hơn hoặc bằng pivot
            ++i;             // Tăng i và đổi chỗ a[i] với a[j]
            swap(a[i], a[j]);
        }
    }

    // Đưa pivot vào đúng vị trí giữa phần nhỏ hơn và lớn hơn
    swap(a[i + 1], a[r]);
    return i + 1; // Trả về vị trí của pivot sau khi phân chia
}

// Hàm quicksort sử dụng Lomuto
void quickSort_Lomuto(float a[], int l, int r) {
    if (l < r) { // Nếu mảng có ít nhất 2 phần tử
        int pi = lomutoPartition(a, l, r); // Chia mảng và lấy chỉ số pivot
        quickSort_Lomuto(a, l, pi - 1);    // Sắp xếp đệ quy nửa trái
        quickSort_Lomuto(a, pi + 1, r);    // Sắp xếp đệ quy nửa phải
    }
}

int main() {
    int n;
    cin >> n; // Nhập số lượng phần tử

    float* a = new float[n]; // Cấp phát mảng động kiểu float (số thực)

    for (int i = 0; i < n; ++i)
        cin >> a[i]; // Nhập từng phần tử của mảng

    quickSort_Lomuto(a, 0, n - 1); // Gọi hàm quicksort

    for (int i = 0; i < n; ++i)
        cout << a[i] << " "; // In ra mảng đã sắp xếp

    delete[] a; // Giải phóng bộ nhớ

    return 0; // Kết thúc chương trình
}
