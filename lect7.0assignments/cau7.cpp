#include <iostream> 
using namespace std; 

// Hàm đảo ngược chữ số của một số nguyên và lưu vào mảng
void daoNguoc(int so, int mang[], int &viTri) {
    if (so == 0) return; // Điều kiện dừng đệ quy
    mang[viTri++] = so % 10; // Lưu chữ số hàng đơn vị vào mảng rồi tăng vị trí
    daoNguoc(so / 10, mang, viTri); // Gọi đệ quy với phần còn lại
}

// Hàm in mảng ra màn hình
void inMang(int mang[], int kichThuoc) {
    for (int i = 0; i < kichThuoc; ++i) {
        cout << mang[i]; // In từng phần tử của mảng
    }
}

// Hàm tính số lượng chữ số của một số nguyên
int demSoLuongChuSo(int so) {
    if (so == 0) return 0; // Điều kiện dừng
    return 1 + demSoLuongChuSo(so / 10); // Mỗi lần chia cho 10 là thêm 1 chữ số
}

int main() {
    int so, viTri = 0; // Khai báo biến nhập số và biến chỉ vị trí trong mảng
    cin >> so; // Nhập số nguyên từ bàn phím

    int* mangChuSo = new int[demSoLuongChuSo(so)]; // Cấp phát động mảng với kích thước vừa đủ

    daoNguoc(so, mangChuSo, viTri); // Gọi hàm để lưu các chữ số đảo ngược vào mảng

    inMang(mangChuSo, demSoLuongChuSo(so)); // In các chữ số sau khi đã đảo ngược

    delete[] mangChuSo; 

    return 0; 
}
