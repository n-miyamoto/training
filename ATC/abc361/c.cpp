#include <bits/stdc++.h>

#define ll long long 

int main(void){
	ll n, k;
	cin >> n >> k;

	vector<ll> a(n);
	for(auto &x : a) cin >> x;

	sort(a.begin(), a.end());

	ll ans = 1000000005;
	for(int i=0;i<=k;i++ ){
		ans = min(ans, a[i+n-k-1] - a[i]);
	}

	cout << ans << endl;

	return 0;
}

