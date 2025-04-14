#include <iostream> 
using namespace std; 
int demChuSo(int so) { // Hàm đếm số chữ số của một số nguyên dương
    int dem = 0;       // Khởi tạo biến đếm ban đầu là 0
    while (so > 0) {   // Lặp cho đến khi số không còn chữ số
        dem++;         // Tăng biến đếm lên 1
        so /= 10;      // Loại bỏ chữ số cuối cùng (chia cho 10)
    }
    return dem;        // Trả về số chữ số đã đếm được
}

int main() {
    int so;            // Khai báo biến để lưu số nguyên nhập vào
    cin >> so;         // Nhập số từ bàn phím

    if (so == 0) {     // Trường hợp đặc biệt: nếu số là 0
        cout << 1;     // Số 0 có 1 chữ số
    } else {
        cout << demChuSo(so); // Gọi hàm đếm và in kết quả
    }

    return 0;          // Kết thúc chương trình
}
