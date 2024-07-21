#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

ll powerOfTen(int n) {
    // Use constexpr if the function is evaluated at compile-time
    return static_cast<ll>(pow(10, n));
}

int main() {
    ll n;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    constexpr ll max_digits = 36;  // Maximum number of digits
    vector<ll> v(max_digits);
    v[0] = 1;

    for (ll i = 1; i < max_digits; ++i) {
        ll tmp = 9 * powerOfTen((i + 1) / 2 - 1);
        v[i] = v[i - 1] + tmp;
    }

    ll cnt = 0;
    while (v[cnt] < n) ++cnt;

    auto s = to_string(n - v[cnt] - 1 + powerOfTen((cnt + 1) / 2));
    string reversedStr = s;
    
    // Remove the last character if cnt is odd
    if (cnt % 2 == 1) {
        reversedStr.pop_back();
    }

    // Reverse the string
    reverse(reversedStr.begin(), reversedStr.end());

    cout << s << reversedStr << endl;

    return 0;
}