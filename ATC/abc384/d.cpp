#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main(void){
	ll n, s;
	cin >> n >> s;
	vector<ll> a(n);
	for(auto&& x: a) cin >> x;

	vector<ll> p(2*n);
	p[0] = a[0];
	for(ll i = 1; i<2*n;i++) p[i] = p[i-1] + a[i%n];

	for(int i=0;i<n;i++){
		ll t = p[i] + s%p[n-1];
		if(binary_search(p.begin(), p.end(), t)){
			cout << "Yes" << endl;
			return 0;
		}
	}
	
	cout << "No" << endl;
	return 0;
}
