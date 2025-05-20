#include <iostream>        
#include <fstream>        
#include <vector>            
#include <algorithm>         
using namespace std;

// Cấu trúc cạnh: gồm 2 đỉnh u, v và trọng số w
struct Edge {
    int u, v, w;
};

// Hàm so sánh 2 cạnh theo đề:
// Ưu tiên trọng số tăng dần, nếu bằng thì u tăng, nếu u bằng thì v tăng
bool cmp(const Edge &a, const Edge &b) {
    if (a.w != b.w) return a.w < b.w; // So sánh trọng số
    if (a.u != b.u) return a.u < b.u; // Nếu bằng, so sánh đỉnh u
    return a.v < b.v;                 // Nếu vẫn bằng, so sánh đỉnh v
}

// Hàm tìm gốc (cha đại diện) của đỉnh u (có nén đường đi)
int find(int u, vector<int> &parent) {
    return parent[u] == u ? u : parent[u] = find(parent[u], parent);
}

// Hàm hợp nhất 2 tập chứa u và v
void unite(int u, int v, vector<int> &parent) {
    parent[find(u, parent)] = find(v, parent);
}

int main() {
    ifstream input("connection.txt");   // Mở file input để đọc
    ofstream output("connection.out");  // Mở file output để ghi

    int n, m; input >> n >> m;          // Đọc số đỉnh n và số cạnh m

    vector<Edge> edges(m);              // Khai báo danh sách cạnh

    // Đọc m dòng cạnh
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        input >> u >> v >> w;           // Đọc cạnh (u, v, w)
        if (u > v) swap(u, v);          // Đảm bảo u < v (giúp chuẩn hóa đầu ra)
        edges[i] = {u, v, w};           // Lưu vào danh sách
    }

    sort(edges.begin(), edges.end(), cmp);  // Sắp xếp các cạnh theo quy tắc

    vector<int> parent(n + 1);              // Khởi tạo mảng cha (DSU)
    for (int i = 1; i <= n; ++i) parent[i] = i; // Ban đầu, mỗi đỉnh là cha chính nó

    int cost = 0;                           // Tổng chi phí cây khung nhỏ nhất
    vector<Edge> mst;                       // Danh sách cạnh thuộc cây khung nhỏ nhất

    // Thuật toán Kruskal: duyệt từng cạnh đã sắp xếp
    for (Edge &e : edges) {
        // Nếu hai đỉnh e.u và e.v chưa cùng tập (chưa nối với nhau)
        if (find(e.u, parent) != find(e.v, parent)) {
            unite(e.u, e.v, parent);       // Nối lại vào cùng tập
            mst.push_back(e);              // Thêm cạnh này vào kết quả
            cost += e.w;                   // Cộng chi phí
        }
    }

    sort(mst.begin(), mst.end(), cmp);     // Sắp lại để in đúng thứ tự yêu cầu đề bài

    output << cost << '\n';                // Ghi tổng chi phí dòng đầu tiên
    for (Edge &e : mst)                    // Ghi từng cạnh còn lại
        output << e.u << " " << e.v << " " << e.w << '\n';

    return 0;
}

