#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

class UnionFind {
private:
    vector<int> parent;
    vector<int> depth;
    int size;

public:
    UnionFind(int n) : parent(n), depth(n, 0), size(n) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (depth[x] < depth[y]) {
                parent[x] = y;
            } else {
                parent[y] = x;
                if (depth[x] == depth[y]) depth[x]++;
            }
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    UnionFind uf(n + 1); // Using n+1 for 1-based index

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        uf.unite(a, b);
    }

    vector<ll> groupCount(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        groupCount[uf.find(i)]++;
    }

    ll answer = 0;
    for (int i = 1; i <= n; i++) {
        if (groupCount[i] > 1) {
            answer += groupCount[i] * (groupCount[i] - 1) / 2;
        }
    }
    answer -= m;

    cout << answer << endl;

    return 0;
}
