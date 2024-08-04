#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	ll n, m;
	cin >> n >> m;

	vector<ll> a(n);
	for(auto &x: a) cin >> x;

	sort(a.begin(), a.end());

	vector<ll> psum(n+1, 0);
	for(int i=1;i<=n;i++){
		psum[i] = psum[i-1] + a[i-1];
	}

	if(psum[n] <= m){
		cout << "infinite" << endl;
		return 0;
	}

    ll ans = 0;
    for(ll i=0;i<n;i++){
        ll x = (m - psum[i])/(n-i);
        x = min(x, a[i]);
        ans = max(ans, x);
    }

	cout << ans << '\n';

	return 0;
}
