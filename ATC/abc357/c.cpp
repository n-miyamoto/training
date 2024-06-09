#include <iostream>
#include <vector>
#include <cmath> // for std::pow

using namespace std;

int calc_width(int n) {
    return static_cast<int>(std::pow(3, n));
}

void solve(int level, vector<vector<char>>& mat, int x, int y) {
    if (level == 0) {
        mat[y][x] = '#';
        return;
    }

    int w = calc_width(level);
    int sub_w = w / 3;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!(i == 1 && j == 1)) {
                solve(level - 1, mat, x + sub_w * i, y + sub_w * j);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int w = calc_width(n);
    vector<vector<char>> mat(w, vector<char>(w, '.')); // Initialize with '.'

    solve(n, mat, 0, 0);

    for (const auto& row : mat) {
        for (const auto& c : row) {
            cout << c;
        }
        cout << '\n';
    }

    return 0;
}