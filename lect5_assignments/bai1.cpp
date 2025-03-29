#include <iostream>
using namespace std;

// Cấu trúc một nút trong cây
struct Node {
    int data;           // Giá trị của nút
    Node* left;         // Con trỏ đến con trái
    Node* right;        // Con trỏ đến con phải
    
    // Hàm khởi tạo một nút mới với giá trị data, ban đầu không có con
    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

// Danh sách liên kết để lưu các nút của cây
struct NodeList {
    struct NodeItem {
        Node* node;    // Con trỏ đến nút trong cây
        NodeItem* next;  // Con trỏ đến phần tử tiếp theo trong danh sách

        // Hàm khởi tạo phần tử mới với con trỏ đến nút trong cây
        NodeItem(Node* n) : node(n), next(nullptr) {}
    };

    NodeItem* head; // Con trỏ đầu danh sách
    NodeList() : head(nullptr) {} // Khởi tạo danh sách rỗng

    // Hàm thêm một nút vào danh sách liên kết
    void insert(Node* node) {
        NodeItem* newItem = new NodeItem(node); // Tạo phần tử mới
        newItem->next = head; // Chèn vào đầu danh sách
        head = newItem; // Cập nhật head
    }

    // Tìm nút có giá trị data bằng value
    Node* find(int value) {
        NodeItem* temp = head; // Bắt đầu từ phần tử đầu danh sách
        while (temp) {
            if (temp->node->data == value) return temp->node; // Nếu tìm thấy, trả về nút
            temp = temp->next; // Chuyển sang phần tử tiếp theo
        }
        return nullptr; // Không tìm thấy, trả về nullptr
    }
};

// Cấu trúc cây
struct Tree {
    NodeList nodeList; // Danh sách các nút trong cây
    int parent[100] = {0}; // Mảng lưu cha của từng nút (giá trị 0 nghĩa là không có cha)
    bool isBinary = true; // Biến kiểm tra cây có phải nhị phân không

    // Hàm lấy hoặc tạo một nút mới
    Node* getNode(int data) {
        Node* node = nodeList.find(data); // Tìm nút trong danh sách
        if (!node) { // Nếu chưa có, tạo mới
            node = new Node(data);
            nodeList.insert(node); // Thêm vào danh sách
        }
        return node;
    }

    // Thêm cạnh u -> v vào cây
    void addEdge(int u, int v) {
        Node* parent = getNode(u); // Lấy nút cha
        Node* child = getNode(v);  // Lấy nút con

        // Kiểm tra nếu nút cha đã có 2 con thì đây không phải cây nhị phân
        if (!parent->left) parent->left = child; // Nếu chưa có con trái, thêm vào trái
        else if (!parent->right) parent->right = child; // Nếu chưa có con phải, thêm vào phải
        else isBinary = false; // Có hơn 2 con, vậy không phải cây nhị phân

        this->parent[v] = u; // Ghi nhớ cha của v
    }

    // Tìm gốc của cây (nút không có cha)
    Node* findRoot(int n) {
        for (int i = 1; i <= n; i++) // Duyệt từ 1 đến N
            if (!parent[i]) return getNode(i); // Nếu không có cha, đây là gốc
        return nullptr; // Không tìm thấy gốc
    }

    // Tính chiều cao của cây
    int getHeight(Node* root) {
        if (!root) return 0; // Cây rỗng → Chiều cao 0
        return max(getHeight(root->left), getHeight(root->right)) + 1; // Đệ quy tính chiều cao
    }

    // Duyệt cây theo Preorder (NLR)
    void preorder(Node* root) {
        if (!root) return; // Nếu cây rỗng, thoát
        cout << root->data << " "; // In giá trị của nút hiện tại
        preorder(root->left); // Đệ quy sang cây con trái
        preorder(root->right); // Đệ quy sang cây con phải
    }

    // Duyệt cây theo Postorder (LRN)
    void postorder(Node* root) {
        if (!root) return; // Nếu cây rỗng, thoát
        postorder(root->left); // Đệ quy sang cây con trái
        postorder(root->right); // Đệ quy sang cây con phải
        cout << root->data << " "; // In giá trị của nút sau khi duyệt hết con
    }

    // Duyệt cây theo Inorder (LNR)
    void inorder(Node* root) {
        if (!root) return; // Nếu cây rỗng, thoát
        inorder(root->left); // Đệ quy sang cây con trái
        cout << root->data << " "; // In giá trị của nút sau khi duyệt trái
        inorder(root->right); // Đệ quy sang cây con phải
    }
};

int main() {
    int N, M; // Số nút và số cạnh
    cin >> N >> M; // Nhập số nút và số cạnh

    Tree tree; // Khởi tạo cây

    // Nhập các cạnh của cây
    for (int i = 0; i < M; i++) {
        int u, v; // Cạnh từ u đến v
        cin >> u >> v;
        tree.addEdge(u, v); // Thêm cạnh vào cây
    }

    Node* root = tree.findRoot(N); // Xác định gốc cây

    // In chiều cao của cây (trừ 1 để tính số cạnh)
    cout << tree.getHeight(root) - 1 << endl;
    
    tree.preorder(root); cout << endl; // In Preorder
    tree.postorder(root); cout << endl; // In Postorder

    if (tree.isBinary) {
        tree.inorder(root); // Nếu là cây nhị phân, in Inorder
        cout << endl;
    } else {
        cout << "NOT BINARY TREE" << endl; // Không phải cây nhị phân thì in NOT BINARY TREE
    }

    return 0;
}
