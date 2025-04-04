#include <iostream>  // Thư viện để dùng các lệnh nhập xuất như cout
using std::cout, std::endl; // Dùng cout và endl từ thư viện std

// Khai báo cấu trúc một node trong cây nhị phân tìm kiếm
struct Node {
    int data;       // Giá trị dữ liệu lưu trong node
    Node* left;     // Con trỏ trỏ đến node con bên trái
    Node* right;    // Con trỏ trỏ đến node con bên phải

    // Hàm khởi tạo (constructor) cho node
    Node(int value) {
        data = value;           // Gán giá trị cho trường data
        left = right = nullptr; // Khởi tạo cả left và right là nullptr (rỗng)
    }
};

// Lớp BinarySearchTree để xây dựng và thao tác với cây nhị phân tìm kiếm
class BinarySearchTree {
private:
    Node* root; // Con trỏ gốc của cây

    // Hàm đệ quy để chèn giá trị mới vào cây
    Node* insertHelper(Node* node, int value) {
        if (node == nullptr)          // Nếu vị trí hiện tại là rỗng
            return new Node(value);   // Tạo node mới và trả về

        if (value < node->data)       // Nếu giá trị nhỏ hơn node hiện tại
            node->left = insertHelper(node->left, value);   // Đệ quy sang trái
        else                          // Ngược lại
            node->right = insertHelper(node->right, value); // Đệ quy sang phải

        return node; // Trả lại node hiện tại sau khi đã gắn node con mới
    }

    // Hàm đệ quy để duyệt cây theo thứ tự trung tố (In-order)
    void traverseHelper(Node* node) {
        if (node == nullptr) return;     // Nếu node rỗng thì dừng lại

        traverseHelper(node->left);      // Duyệt cây con bên trái
        cout << node->data << " ";       // In giá trị node hiện tại
        traverseHelper(node->right);     // Duyệt cây con bên phải
    }

    // Hàm đệ quy để xóa một giá trị khỏi cây
    Node* deleteHelper(Node* node, int value) {
        if (node == nullptr) return node; // Nếu node rỗng thì không làm gì cả

        if (value < node->data) {         // Nếu giá trị cần xóa nhỏ hơn node hiện tại
            node->left = deleteHelper(node->left, value);   // Tìm trong cây con trái
        } else if (value > node->data) {  // Nếu giá trị cần xóa lớn hơn node hiện tại
            node->right = deleteHelper(node->right, value); // Tìm trong cây con phải
        } else { // Tìm thấy node cần xóa
            // Trường hợp 1 hoặc 2: node chỉ có một con hoặc không có con
            if (node->left == nullptr) {     // Không có con trái
                Node* temp = node->right;    // Lưu con phải
                delete node;                 // Xóa node hiện tại
                return temp;                 // Trả về node con phải
            } else if (node->right == nullptr) { // Không có con phải
                Node* temp = node->left;     // Lưu con trái
                delete node;                 // Xóa node hiện tại
                return temp;                 // Trả về node con trái
            }

            // Trường hợp 3: node có cả hai con
            Node* temp = minValue(node->right); // Tìm node nhỏ nhất ở cây con phải
            node->data = temp->data;            // Gán giá trị nhỏ nhất cho node hiện tại
            node->right = deleteHelper(node->right, temp->data); // Xóa node nhỏ nhất
        }

        return node; // Trả về node sau khi xóa
    }

    // Hàm tìm node có giá trị nhỏ nhất trong cây
    Node* minValue(Node* node) {
        while (node && node->left != nullptr)  // Duyệt về phía trái cho tới node cuối cùng
            node = node->left;
        return node; // Trả về node có giá trị nhỏ nhất
    }

public:
    // Constructor: khởi tạo cây rỗng
    BinarySearchTree() {
        root = nullptr;
    }

    // Gọi hàm chèn đệ quy
    void insert(int value) {
        root = insertHelper(root, value);
    }

    // Gọi hàm duyệt trung tố
    void traverseInOrder() {
        traverseHelper(root);
        cout << endl;
    }

    // Gọi hàm xóa node và in thông báo
    void remove(int value) {
        cout << "Đang xóa node có giá trị: " << value << endl;
        root = deleteHelper(root, value);
    }
};

// Hàm chính để chạy chương trình
int main() {
    BinarySearchTree bst; // Tạo cây nhị phân tìm kiếm

    // Mảng các giá trị ban đầu
    int initial[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};

    // Duyệt qua mảng và thêm từng phần tử vào cây
    for (int val : initial)
        bst.insert(val);

    // In cây sau khi thêm ban đầu
    cout << "Duyệt cây sau khi thêm giá trị ban đầu: ";
    bst.traverseInOrder();

    // Mảng các giá trị muốn thêm tiếp
    int additional[] = {14, 0, 35};

    // Thêm các phần tử mới vào cây
    for (int val : additional)
        bst.insert(val);

    // In cây sau khi thêm mới
    cout << "Duyệt cây sau khi thêm giá trị mới: ";
    bst.traverseInOrder();

    // Xóa một vài giá trị khỏi cây
    bst.remove(6);
    bst.remove(13);
    bst.remove(35);

    // In cây sau khi xóa
    cout << "Cây sau khi đã xóa một vài node: ";
    bst.traverseInOrder();

    return 0; // Kết thúc chương trình
}
