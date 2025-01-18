#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll countGreaterThan(const std::vector<ll>& a, ll b) {
    // 二分探索で b より大きい最初の位置を取得
    auto it = std::lower_bound(a.begin(), a.end(), b);

    // b より大きい要素の個数を計算
    return std::distance(it, a.end());
}

int main(void){
	ll n;
	cin >> n;

	vector<ll> a(n);

	for(auto&& x : a) cin >> x;

	ll ans = 0;
	for(const auto x: a){
		ans += countGreaterThan(a, 2*x);
	}

	cout << ans << endl;

	return 0;
}
