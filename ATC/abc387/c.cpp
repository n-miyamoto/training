#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll power(ll a, ll t) {
    ll res = 1;
    for (int i = 0; i < t; i++) res *= a;
    return res;
}

vector<ll> convert_to_array(ll num){
	std::vector<ll> digits;

	while (num > 0) {
		digits.push_back(num % 10);
		num /= 10;
	}

	return digits;
}

ll convertToBaseN(const vector<ll>& a) {
	ll n = a.size()-1;
	ll base = a[n];

	ll ret = 0;

	ll k = 1;
	for (ll i = 0; i<n;i++, k*=base) {
		ret += a[i]*k;
	}

	return ret;
}

vector<ll> convert(vector<ll> a){
	auto n = a.size();
	auto base = a[n-1];

	bool flag = false;
	for(ll i=n-2; i>=0; i--){
		if(a[i]>=base) flag = true;
		if(flag) a[i] = base-1;
	}
	return a;
}

ll count(const ll n){
	if(n<10) return 0;
	ll ret = 0;

	const auto t = convert_to_array(n);
	const auto v = convert(t);

	for(ll i = 1;i<v.size()-1; i++){
		for(ll j=1;j<10;j++) ret += power(j, i);
	}

	for(ll j=1; j<v[v.size()-1];j++) ret += power(j,v.size()-1);

	ret += convertToBaseN(v)+1;

	return ret;
}

int main(void){
	ll l, r;
	cin >> l >> r;
	cout << count(r) - count(l-1) << endl;
	return 0;
}
