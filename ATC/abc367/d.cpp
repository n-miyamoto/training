#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	ll n, m;
	cin >> n >> m;

	vector<ll> a(n);
	for(auto&x : a) cin >> x;

	vector<ll> r(2*n, 0);
	for(ll i=1;i<2*n;i++) r[i] = (r[i-1] + a[(i-1)%n]) %m;

	vector<ll> c(m, 0);
	for(ll i=0;i<n;i++) c[r[i]]++;

	ll ans = 0;
	for(ll i=0;i<n;i++){
		c[r[i]]--;
		ans += c[r[i]];
		c[r[i+n]]++;
	}

	cout << ans << endl;
	
	return 0;
}
