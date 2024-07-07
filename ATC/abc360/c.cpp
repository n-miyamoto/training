#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main(void){
	ll n;
	cin >> n;
	
	vector<ll> a(n+1);
	vector<ll> w(n+1);

	for (ll i = 1; i <= n; i++) cin >> a[i];
	for (ll i = 1; i <= n; i++) cin >> w[i];

	vector<vector<ll> > v(n+1);

	for(ll i = 1;i<=n;i++) v[a[i]].push_back(w[i]);

	ll ans = 0;

	for(ll i = 1;i<=n;i++){
		if(v[i].size() <= 1) continue;
		sort(v[i].begin(), v[i].end());
		ans += accumulate(v[i].begin(), v[i].end()-1, 0LL);
	}

	cout << ans << endl;

	return 0;
}
