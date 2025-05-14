#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Hàm tìm số bước đi ít nhất từ start đến end
int bfsShortestPath(int n, int start, int end, const vector<vector<int>>& graph) {
    vector<int> dist(n + 1, -1); // Lưu khoảng cách từ start đến các đỉnh
    queue<int> q;

    dist[start] = 0; // Khoảng cách từ start đến chính nó là 0
    q.push(start);   // Bắt đầu BFS từ đỉnh start

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Duyệt qua các đỉnh kề với u
        for (int v : graph[u]) {
            if (dist[v] == -1) { // Nếu đỉnh v chưa được thăm
                dist[v] = dist[u] + 1; // Cập nhật khoảng cách
                q.push(v);
            }
        }
    }

    return dist[end]; // Trả về kết quả tìm được (hoặc -1 nếu không tới được)
}

int main() {
    int n, m, x, y;
    cout << "Nhap so dinh, so canh va hai dinh X, Y: ";
    cin >> n >> m >> x >> y;

    vector<vector<int>> graph(n + 1); // Danh sách kề

    // Nhập m cạnh có hướng
    for (int i = 0; i < m; ++i) {
        int a, b;
        cout << "Nhap canh noi tu a den b: ";
        cin >> a >> b;
        graph[a].push_back(b); // Chỉ thêm 1 chiều vì là đồ thị có hướng
    }

    int shortest = bfsShortestPath(n, x, y, graph);

    if (shortest != -1) {
        cout << "So buoc di ngan nhat tu " << x << " den " << y << " la: " << shortest << '\n';
    } else {
        cout << "Khong co duong di tu " << x << " den " << y << '\n';
    }

    return 0;
}
