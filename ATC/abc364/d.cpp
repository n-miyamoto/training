#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void){

	ll n, q;

	cin >> n >> q;
	vector<ll> a(n);
	for(auto &x : a) cin >> x;
	sort(a.begin(), a.end());

	while (q--) {
        int b, k;
        cin >> b >> k;
        auto f = [&](int x) -> bool {
            // (# of points in [b-x, b+x]) >= k
            auto lb = lower_bound(a.begin(), a.end(), b - x);
            auto ub = upper_bound(a.begin(), a.end(), b + x);
            return ub - lb >= k;
        };
        int ng = -1, ok = (int) 2e8 + 10;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;
            if (f(mid)) ok = mid;
            else ng = mid;
        }
        cout << ok << '\n';
    }
	return 0;
}
