#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // Encode the string into a vector of counts
    s.push_back('/'); // Sentinel to mark the end
    vector<int> v;
    int count = 1;

    for (int i = 0; i < n; ++i) {
        if (s[i] == s[i + 1]) {
            ++count;
        } else {
            v.push_back(s[i] == '1' ? count : -count);
            count = 1;
        }
    }

    // Swap segments at the kth occurrence of '1'
    for (int cnt = 0, i = 0; i < v.size(); ++i) {
        if (v[i] > 0) ++cnt; // Count the '1' segments
        if (cnt == k) {
            if (i > 0) {
                swap(v[i], v[i - 1]);
            }
            break;
        }
    }

    // Decode the vector back into the string
    string result;
    for (int x : v) {
        if (x > 0) {
            result.append(x, '1'); // Append `x` number of '1's
        } else {
            result.append(-x, '0'); // Append `-x` number of '0's
        }
    }

    cout << result << endl;

    return 0;
}