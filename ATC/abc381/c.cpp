#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> v;
    s.push_back('0'); // Sentinel character to ensure processing the last segment
    char current_char = s[0];
    int count = 1;

    // Group consecutive characters and populate vector `v`
    for (int i = 1; i <= n; ++i) {
        if (s[i] == current_char) {
            ++count;
        } else {
            if (current_char == '1') {
                v.push_back(count);
            } else if (current_char == '2') {
                v.push_back(-count);
            } else if (current_char == '/') {
                v.insert(v.end(), count, 0); // Add `count` zeros to vector `v`
            }
            current_char = s[i];
            count = 1;
        }
    }

    // Compute the maximum length for the pattern "11/22"
    int max_length = 1;
    for (size_t i = 1; i + 1 < v.size(); ++i) {
        if (v[i - 1] > 0 && v[i] == 0 && v[i + 1] < 0) {
            max_length = max(max_length, 2 * min(v[i - 1], -v[i + 1]) + 1);
        }
    }

    cout << max_length << endl;
    return 0;
}
