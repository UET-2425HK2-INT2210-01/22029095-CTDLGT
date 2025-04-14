#include <iostream> 
using namespace std; 

int tongChuSo(int so) { // Hàm tính tổng các chữ số của một số nguyên
    if (so == 0) return 0; // Điều kiện dừng: nếu số bằng 0 thì trả về 0
    return so % 10 + tongChuSo(so / 10); // Lấy chữ số hàng đơn vị + đệ quy phần còn lại
}

int main() { 
    int so; // Khai báo biến lưu số nguyên đầu vào
    cin >> so; // Nhập giá trị từ bàn phím
    cout << tongChuSo(so); // Gọi hàm tính tổng chữ số và in ra kết quả
    return 0; 
}
