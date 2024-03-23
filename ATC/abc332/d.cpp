#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;

int h, w;

void show(const vector<vector<int>>& m) {
    for (const auto& v : m) {
        for (int x : v) {
            cout << x << "\t";
        }
        cout << endl;
    }
}

vector<vector<int>> createMat(const vector<vector<int>>& a, const vector<int>& row, const vector<int>& col) {
    vector<vector<int>> temp(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            temp[i][j] = a[row[i]][col[j]];
        }
    }
    return temp;
}

bool compareMat(const vector<vector<int>>& m1, const vector<vector<int>>& m2) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (m1[i][j] != m2[i][j]) return false;
        }
    }
    return true;
}

int countSwap(const vector<int> a) {
	vector<int> v = a;
    int swapCount = 0;
    for (int i = 0; i < v.size(); i++) {
        while (v[i] != i) {
            auto ite = find(v.begin(), v.end(), i);
            swap(*(ite-1), *ite);
            swapCount++;
        }
    }
    return swapCount;
}

int main() {
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<int>> b(h, vector<int>(w));

    for (auto& v : a) for (auto& x : v) cin >> x;
    for (auto& v : b) for (auto& x : v) cin >> x;

    vector<int> v_row(h), v_col(w);
    iota(v_row.begin(), v_row.end(), 0);
    iota(v_col.begin(), v_col.end(), 0);

    int ans = INT_MAX;
    do {
        do {
            auto m = createMat(a, v_row, v_col);
            if (compareMat(b, m)) {
                int tmp = countSwap(v_row) + countSwap(v_col);
                ans = min(ans, tmp);
            }
        } while (next_permutation(v_col.begin(), v_col.end()));
    } while (next_permutation(v_row.begin(), v_row.end()));

    if (ans == INT_MAX) ans = -1;
    cout << ans << endl;

    return 0;
}