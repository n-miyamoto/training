#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void){
	ll n, m;
	cin >> n >> m;

	vector<ll> a(n);
	vector<ll> b(m);

	for(auto &x: a) cin >> x;
	for(auto &x: b) cin >> x;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ll i= 0;
	ll ans=0;
	for(const auto x: b){
		//cout << i << a[i] << x << endl;
		while(a[i]<x && i<n) i++;

		if(i>=n) {
			cout << -1 << endl;
			return 0;
		}

		ans += a[i]; 
		i++;
	}

	cout << ans << endl;
	
	return 0;
}
