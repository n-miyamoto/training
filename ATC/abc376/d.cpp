#include <iostream>
#include <vector>
#include <queue>
#include <optional>

using namespace std;
using ll = long long;

struct Status {
    int node;
    int depth;
};

constexpr int START_NODE = 0;

optional<int> bfs(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    visited[START_NODE] = true;

    queue<Status> q;
    q.push({START_NODE, 1});

    while (!q.empty()) {
        auto [node, depth] = q.front();
        q.pop();

        for (const auto& neighbor : graph[node]) {
            if (neighbor == START_NODE) {
                return depth; // Found a path back to the start
            }
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, depth + 1});
            }
        }
    }

    return nullopt; // No path found
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }

    if (auto result = bfs(graph)) {
        cout << *result << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}