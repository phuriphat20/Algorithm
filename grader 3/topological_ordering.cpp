#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100001];
vector<int> in_degree(100001, 0);

bool topologicalSort(int n) {
    vector<int> result;
    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < adj[i].size(); ++j) {
            in_degree[adj[i][j]]++;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (result.size() != n) {
        return false; // ไม่มี Topological Ordering
    }

    // แสดงผลลัพธ์ (Topological Ordering)
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (!topologicalSort(n)) {
        cout << "NO" << endl;
    }

    return 0;
}
