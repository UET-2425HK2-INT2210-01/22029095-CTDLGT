#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ifstream input("jobs.txt");        // Mở file input
    ofstream output("jobs.out");       // Mở file output

    int n, m; input >> n >> m;         // Đọc số lượng công việc và số ràng buộc

    vector<vector<int>> g(n + 1);      // Danh sách kề biểu diễn đồ thị
    vector<int> indeg(n + 1, 0);       // Mảng lưu bậc vào (số đỉnh trỏ vào mỗi đỉnh)
    vector<int> res;                   // Mảng kết quả sắp xếp topo
    queue<int> q;                      // Hàng đợi cho thuật toán Kahn

    // Đọc m ràng buộc: u phải làm trước v
    while (m--) {
        int u, v;
        input >> u >> v;
        g[u].push_back(v);             // Tạo cạnh u → v
        indeg[v]++;                    // Tăng bậc vào của v
    }

    // Đưa các đỉnh có bậc vào bằng 0 vào hàng đợi
    for (int i = 1; i <= n; ++i)
        if (indeg[i] == 0) q.push(i);

    // Thuật toán Kahn - sắp xếp topo
    while (!q.empty()) {
        int u = q.front(); q.pop();
        res.push_back(u);              // Ghi vào kết quả

        for (int v : g[u])             // Duyệt các đỉnh kề
            if (--indeg[v] == 0)       // Giảm bậc vào, nếu còn 0 thì cho vào hàng đợi
                q.push(v);
    }

    // Nếu số đỉnh trong kết quả < n → có chu trình → không sắp xếp được
    if (res.size() < n)
        output << "Graph has a cycle. Topological sort not possible.";
    else
        for (int i = 0; i < n; ++i)
            output << res[i] << (i < n - 1 ? " " : ""); // Ghi kết quả cách nhau bởi khoảng trắng

    return 0;
}
