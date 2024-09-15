#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	ll n;
	cin >> n;
	vector<ll> x(n);
	for(auto& a: x) cin >> a;
	vector<ll> p(n);
	for(auto& a: p) cin >> a;

	vector<ll> psum(n+1, 0);
	for(int i=0;i<n;i++) psum[i+1] = psum[i] + p[i];

	ll q;
	cin >> q;
	for(ll i=0;i<q;i++){
		ll l, r;
		cin >> l >> r;
		auto it_l = lower_bound(x.begin(), x.end(), l);
		auto index_l = distance(x.begin(), it_l);

		auto it_r = upper_bound(x.begin(), x.end(), r);
		auto index_r = distance(x.begin(), it_r)-1;

		//cout << index_l << index_r << endl;
		cout << psum[index_r+1] - psum[index_l]<< endl;

	}

	
	return 0;
}
