#include <bits/stdc++.h>

using namespace std;
using ll=unsigned long long;
constexpr ll MOD = 998244353;


int main(void){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(auto& x : a) cin >> x;

	vector<ll> k(n);
	for(int i=0;i<n;i++){
		k[i] = 1;
		for(size_t j=0;j<std::to_string(a[i]).length(); j++) k[i] *= 10;
	}

    ll sum_lower = std::accumulate(a.begin(), a.end(), 0ULL);
    ll sum_upper = std::accumulate(k.begin(), k.end(), 0ULL);


	ll ans = 0;
	for(int i=0;i<n;i++){
		sum_lower -= a[i];
		sum_upper -= k[i];

		ll tmp = (a[i]%MOD) * (sum_upper%MOD);
		ans += tmp%MOD;
		ans %= MOD;
		ans += (sum_lower % MOD);
		ans %= MOD;
	}

	cout << ans %MOD << endl;


	return 0;
}
