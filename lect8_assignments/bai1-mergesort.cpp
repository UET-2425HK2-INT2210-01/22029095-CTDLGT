#include <iostream> // Thư viện hỗ trợ nhập xuất dữ liệu
using namespace std;

// Hàm trộn hai phần mảng con đã sắp xếp lại thành một mảng sắp xếp hoàn chỉnh
void tron(int a[], int l, int m, int r) {
    int n1 = m - l + 1;       // Số phần tử mảng trái
    int n2 = r - m;           // Số phần tử mảng phải

    int* trai = new int[n1];  // Cấp phát mảng trái
    int* phai = new int[n2];  // Cấp phát mảng phải

    // Sao chép dữ liệu vào mảng trái
    for (int i = 0; i < n1; ++i)
        trai[i] = a[l + i];

    // Sao chép dữ liệu vào mảng phải
    for (int i = 0; i < n2; ++i)
        phai[i] = a[m + 1 + i];

    // i, j là chỉ số của mảng con; k là chỉ số của mảng gốc
    int i = 0, j = 0, k = l;

    // Trộn từng phần tử từ hai mảng con vào mảng gốc theo thứ tự tăng dần
    while (i < n1 && j < n2)
        a[k++] = (trai[i] <= phai[j]) ? trai[i++] : phai[j++];

    // Thêm các phần tử còn lại nếu mảng trái còn phần tử
    while (i < n1)
        a[k++] = trai[i++];

    // Thêm các phần tử còn lại nếu mảng phải còn phần tử
    while (j < n2)
        a[k++] = phai[j++];

    // Giải phóng bộ nhớ động đã cấp phát
    delete[] trai;
    delete[] phai;
}

// Hàm merge sort chia nhỏ mảng rồi trộn lại (sắp xếp tăng dần)
void mergeSort(int a[], int l, int r) {
    if (l >= r) return;            // Điều kiện dừng: mảng chỉ còn 1 phần tử
    int m = (l + r) / 2;           // Tính chỉ số giữa mảng
    mergeSort(a, l, m);            // Gọi đệ quy sắp xếp nửa trái
    mergeSort(a, m + 1, r);        // Gọi đệ quy sắp xếp nửa phải
    tron(a, l, m, r);              // Trộn hai nửa đã sắp xếp
}

int main() {
    int n;
    cin >> n;                      // Nhập số lượng phần tử

    int* a = new int[n];           // Cấp phát mảng động

    for (int i = 0; i < n; ++i)
        cin >> a[i];               // Nhập từng phần tử của mảng

    mergeSort(a, 0, n - 1);        // Gọi hàm sắp xếp merge sort

    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";       // In mảng sau khi sắp xếp

    delete[] a;                    // Giải phóng bộ nhớ động

    return 0;                      // Kết thúc chương trình
}
