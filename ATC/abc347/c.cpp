#include <bits/stdc++.h>

using namespace std;
using ll=long long;

int main(void){
	ll n, a, b;
	cin >> n >> a >> b;
	ll t = a+b;

	vector<ll> d(n);
	for(auto &x: d){
		cin >> x;
		x%=t;
	}

	sort(d.begin(), d.end());
	d.push_back(d[0] + t);

	auto ans = false;
	for(ll i=0;i<n;i++){
		if( d[i+1] - d[i] > b) ans = true; 
	}

	cout << (ans?"Yes":"No") << endl;

	return 0;
}
