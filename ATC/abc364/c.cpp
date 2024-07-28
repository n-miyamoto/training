#include <bits/stdc++.h>

using namespace std;
#define ll long long 

int main(void){
	ll n, x, y;
	cin >> n >> x >> y;

	vector<ll> a(n);
	for(auto &k: a) cin >> k;

	vector<ll> b(n);
	for(auto &k: b) cin >> k;

	sort(a.rbegin(), a.rend());
	ll min_a = n;
	ll sum = 0;
	for(ll i=0;i<n;i++){
		sum+=a[i];
		if(sum > x) {
			min_a = i+1;
			break;
		}
	}

	sort(b.rbegin(), b.rend());
	ll min_b = n;
	sum = 0;
	for(ll i=0;i<n;i++){
		sum+=b[i];
		if(sum > y) {
			min_b = i+1;
			break;
		}
	}

	ll ans = min(min_a, min_b);
	cout << ans << endl;

	return 0;
}
