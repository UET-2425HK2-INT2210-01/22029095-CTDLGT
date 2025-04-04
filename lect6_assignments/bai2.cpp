#include <iostream>  // Thư viện chuẩn để dùng cout, endl
using namespace std;

// Cấu trúc nút dùng cho cây
struct TreeNode {
    int val;            // Dữ liệu lưu trong nút
    TreeNode* left;     // Con trỏ đến cây con trái
    TreeNode* right;    // Con trỏ đến cây con phải

    // Constructor để khởi tạo node mới
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Lớp Quản lý MinHeap bằng mảng và cây nhị phân
class HeapTree {
private:
    int elements[100];  // Mảng lưu các phần tử heap
    int currentSize;    // Biến theo dõi số phần tử hiện tại trong heap
    TreeNode* rootNode; // Gốc của cây biểu diễn heap

    // Điều chỉnh lại heap từ một vị trí chỉ định (heapify-down)
    void adjustDown(int index) {
        int minIndex = index;
        int l = 2 * index + 1; // chỉ số con trái
        int r = 2 * index + 2; // chỉ số con phải

        if (l < currentSize && elements[l] < elements[minIndex])
            minIndex = l; // Nếu con trái nhỏ hơn

        if (r < currentSize && elements[r] < elements[minIndex])
            minIndex = r; // Nếu con phải nhỏ hơn

        if (minIndex != index) {
            swap(elements[index], elements[minIndex]); // Hoán đổi giá trị
            adjustDown(minIndex); // Đệ quy để tiếp tục điều chỉnh
        }
    }

    // Tạo lại cây từ mảng heap bắt đầu từ index
    TreeNode* generateTree(int index) {
        if (index >= currentSize) return nullptr; // Nếu vượt quá thì trả về null

        TreeNode* newNode = new TreeNode(elements[index]); // Tạo node từ mảng
        newNode->left = generateTree(2 * index + 1); // Đệ quy tạo cây con trái
        newNode->right = generateTree(2 * index + 2); // Đệ quy tạo cây con phải
        return newNode; // Trả về node đã tạo
    }

    // Duyệt cây theo thứ tự trung tố (Inorder Traversal)
    void printInorder(TreeNode* node) {
        if (!node) return; // Nếu node rỗng thì dừng lại
        printInorder(node->left); // Duyệt bên trái
        cout << node->val << " "; // In giá trị node
        printInorder(node->right); // Duyệt bên phải
    }

public:
    // Constructor: khởi tạo heap rỗng
    HeapTree() {
        currentSize = 0;
        rootNode = nullptr;
    }

    // Thêm phần tử vào heap (heapify-up)
    void push(int value) {
        elements[currentSize] = value; // Gán vào cuối mảng
        int pos = currentSize;         // Lưu lại chỉ số hiện tại
        currentSize++;                 // Tăng size

        // Đảm bảo tính chất heap (điều chỉnh lên trên)
        while (pos > 0 && elements[(pos - 1) / 2] > elements[pos]) {
            swap(elements[pos], elements[(pos - 1) / 2]); // Hoán đổi nếu cần
            pos = (pos - 1) / 2; // Cập nhật vị trí lên cha
        }
    }

    // Xây dựng heap từ mảng hiện tại (heapify-down toàn bộ)
    void organizeHeap() {
        for (int i = currentSize / 2 - 1; i >= 0; i--) {
            adjustDown(i); // Điều chỉnh từng node từ dưới lên
        }
        rootNode = generateTree(0); // Tạo lại cây từ mảng
    }

    // In cây theo thứ tự trung tố
    void displayTree() {
        printInorder(rootNode); // Gọi hàm đệ quy
        cout << endl;
    }

    // Xóa phần tử có giá trị cụ thể khỏi heap
    void remove(int target) {
        int idx = -1;

        // Tìm vị trí của phần tử cần xóa
        for (int i = 0; i < currentSize; i++) {
            if (elements[i] == target) {
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            cout << "Không tìm thấy phần tử " << target << " để xóa." << endl;
            return;
        }

        // Ghi đè phần tử bị xóa bằng phần tử cuối cùng
        elements[idx] = elements[currentSize - 1];
        currentSize--; // Giảm kích thước mảng
        adjustDown(idx); // Điều chỉnh lại từ vị trí vừa thay

        // Cập nhật lại cây sau khi xóa
        organizeHeap();
    }
};

// Hàm chính
int main() {
    HeapTree myHeap; // Tạo đối tượng quản lý heap

    int input[] = {2, 1, 10, 6, 3, 8, 7, 13, 20}; // Dữ liệu ban đầu

    // Thêm các phần tử vào heap
    for (int val : input)
        myHeap.push(val);

    myHeap.organizeHeap(); // Xây dựng heap sau khi thêm
    cout << "Min Heap ban đầu (Inorder): ";
    myHeap.displayTree(); // Hiển thị cây

    // Thêm phần tử mới
    myHeap.push(14);
    myHeap.push(0);
    myHeap.push(35);
    myHeap.organizeHeap(); // Cập nhật lại sau khi thêm

    cout << "Sau khi thêm 14, 0, 35 (Inorder): ";
    myHeap.displayTree();

    // Xóa các phần tử
    myHeap.remove(6);
    myHeap.remove(13);
    myHeap.remove(35);

    cout << "Sau khi xóa 6, 13, 35 (Inorder): ";
    myHeap.displayTree();

    return 0; // Kết thúc chương trình
}
