#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::string;
using std::vector;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (string &row : grid) {
        cin >> row;
    }

    vector<ll> horizontalCounts(n), verticalCounts(n);

    // Calculate horizontal counts
    for (int i = 0; i < n; ++i) {
        ll count = std::count(grid[i].begin(), grid[i].end(), 'o');
        horizontalCounts[i] = max(count - 1, 0LL);
        //cout << horizontalCounts[i];
    }
    //cout << endl;

    // Calculate vertical counts
    for (int i = 0; i < n; ++i) {
        ll count = 0;
        for (int j = 0; j < n; ++j) {
            if (grid[j][i] == 'o') {
                count++;
            }
        }
        verticalCounts[i] = max(count - 1, 0LL);
        //cout << verticalCounts[i];
    }
    //cout << endl;

    // Calculate final result
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[j][i] == 'o') {
                result += verticalCounts[i] * horizontalCounts[j];
            }
        }
    }

    cout << result << endl;
    return 0;
}