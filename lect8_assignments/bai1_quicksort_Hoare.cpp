#include <iostream> // Thư viện hỗ trợ nhập xuất dữ liệu
using namespace std;

// Hàm phân chia theo cách Hoare
int hoarePartition(float a[], int l, int r) {
    float pivot = a[l];   // Chọn phần tử đầu tiên làm pivot (chốt)
    int i = l - 1;        // Bắt đầu từ trước chỉ số trái
    int j = r + 1;        // Bắt đầu từ sau chỉ số phải

    while (true) {
        do {
            --j;          // Giảm j cho đến khi gặp phần tử <= pivot
        } while (a[j] > pivot);

        do {
            ++i;          // Tăng i cho đến khi gặp phần tử >= pivot
        } while (a[i] < pivot);

        if (i < j)        // Nếu i vẫn nhỏ hơn j thì hoán đổi a[i] và a[j]
            swap(a[i], a[j]);
        else              // Nếu đã giao nhau thì dừng và trả về vị trí j
            return j;
    }
}

// Hàm quicksort sử dụng Hoare
void quickSort_Hoare(float a[], int l, int r) {
    if (l < r) { // Nếu đoạn cần sắp xếp có ít nhất 2 phần tử
        int pi = hoarePartition(a, l, r); // Phân chia và lấy vị trí chia
        quickSort_Hoare(a, l, pi);        // Đệ quy sắp xếp nửa trái (gồm cả pi)
        quickSort_Hoare(a, pi + 1, r);    // Đệ quy sắp xếp nửa phải
    }
}

int main() {
    int n;
    cin >> n; // Nhập số lượng phần tử

    float* a = new float[n]; // Cấp phát mảng động kiểu float

    for (int i = 0; i < n; ++i)
        cin >> a[i]; // Nhập từng phần tử

    quickSort_Hoare(a, 0, n - 1); // Gọi quick sort với phân vùng Hoare

    for (int i = 0; i < n; ++i)
        cout << a[i] << " "; // In mảng sau khi sắp xếp

    delete[] a; // Giải phóng bộ nhớ

    return 0; // Kết thúc chương trình
}
