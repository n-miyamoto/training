#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = unsigned long long;
constexpr ll MOD = 100000000;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    
    vector<ll> psum(n + 1, 0);
    partial_sum(a.begin(), a.end(), psum.begin() + 1);

    ll ans = 0;
    for (ll i = 0; i < n - 1; i++) {
        auto it = upper_bound(a.begin(), a.end(), MOD - a[i] - 1);
        ll index = distance(a.begin(), it);
        ans += psum[n] - psum[i + 1] + a[i] * (n - i - 1) - MOD * (n - max(index, i + 1));
    }

    cout << ans << endl;
    return 0;
}
