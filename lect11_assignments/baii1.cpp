#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include <algorithm>
using namespace std;

const int INF = 1e9;

bool bellman(int n, int s, int t, const vector<tuple<int, int, int>>& edges, vector<int>& dist, vector<int>& trace) {
    dist.assign(n + 1, INF);
    vector<int> pre(n + 1, -1);
    dist[s] = 0;

    for (int i = 0; i < n - 1; ++i)
        for (auto [u, v, w] : edges)
            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w, pre[v] = u;

    for (int v = t; v != -1; v = pre[v])
        trace.push_back(v);
    reverse(trace.begin(), trace.end());

    return dist[t] != INF;
}

void floyd(int n, vector<vector<int>>& a) {
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (a[i][k] < INF && a[k][j] < INF)
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}

int main() {
    ifstream in("dirty.txt");
    ofstream out("dirty.out");

    int n, m, s, t;
    in >> n >> m >> s >> t;

    vector<tuple<int, int, int>> edge;
    vector<vector<int>> mat(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        in >> u >> v >> w;
        edge.emplace_back(u, v, w);
        mat[u][v] = w;
    }
    for (int i = 1; i <= n; ++i) mat[i][i] = 0;

    vector<int> d, p;
    if (bellman(n, s, t, edge, d, p)) {
        out << d[t] << "\n";
        for (int i = 0; i < p.size(); ++i)
            out << p[i] << (i + 1 < p.size() ? " " : "\n");
    } else {
        out << "INF\nNo path\n";
    }

    floyd(n, mat);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            out << (mat[i][j] == INF ? "INF" : to_string(mat[i][j])) << (j < n ? " " : "\n");
    }

    return 0;
}
