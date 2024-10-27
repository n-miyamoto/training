#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(auto&& x: a) cin >> x;

	vector<ll> psum(n);
	psum[0] = a[0];
	for(int i=1;i<n;i++) psum[i] = psum[i-1] + a[i];

	auto mn = min_element(psum.begin(), psum.end());
	cout << psum[n-1] + max(0LL, -1LL* (*mn)) << endl;

	return 0;
}
