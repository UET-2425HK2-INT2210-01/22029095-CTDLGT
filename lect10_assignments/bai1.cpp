#include <iostream>
#include <vector>

using namespace std;

// Hàm duyệt theo chiều sâu (Depth-First Search)
void dfs(int u, const vector<vector<int>>& graph, vector<bool>& visited) {
    visited[u] = true; // Đánh dấu đã thăm đỉnh u

    for (int neighbor : graph[u]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited); // Đệ quy sang các đỉnh kề chưa thăm
        }
    }
}

int main() {
    int nodes, edges;
    cout << "Nhap so dinh va so canh: ";
    cin >> nodes >> edges;

    // Tạo danh sách kề cho đồ thị
    vector<vector<int>> graph(nodes + 1);

    // Nhập các cạnh của đồ thị
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cout << "Nhap canh noi giua hai dinh: ";
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Đồ thị vô hướng
    }

    vector<bool> visited(nodes + 1, false); // Đánh dấu các đỉnh đã thăm
    int connectedComponents = 0; // Đếm số thành phần liên thông

    // Kiểm tra từng đỉnh
    for (int i = 1; i <= nodes; ++i) {
        if (!visited[i]) {
            dfs(i, graph, visited); // Bắt đầu DFS từ đỉnh chưa thăm
            connectedComponents++;  // Mỗi lần DFS là một thành phần liên thông mới
        }
    }

    cout << "So luong thanh phan lien thong: " << connectedComponents << '\n';

    return 0;
}
