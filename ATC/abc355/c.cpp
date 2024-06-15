#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> row(n + 1, n);
    vector<int> col(n + 1, n);
    int upper_left_to_lower_right = n;
    int lower_left_to_upper_right = n;

    for (int k = 0; k < t; ++k) {
        int x;
        cin >> x;

        int i = (x - 1) / n + 1;
        int j = (x - 1) % n + 1;

        row[i]--;
        col[j]--;

        if (i == j) upper_left_to_lower_right--;
        if (i + j == n + 1) lower_left_to_upper_right--;

        if (row[i] == 0 || col[j] == 0 || upper_left_to_lower_right == 0 || lower_left_to_upper_right == 0) {
            cout << k + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}