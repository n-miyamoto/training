#include <bits/stdc++.h>

using namespace std;
using ll=long long;


ll count(const multiset<ll>& ms, ll k){
	//cout <<  "\n multiset ";
	//for(const auto x : ms ) cout << x << " ";
	//cout << endl;
	// Find the first element greater than k (logarithmic time complexity)
    auto it = ms.lower_bound(k);

    // Count numbers greater than k
    return distance(it, ms.end());
}

int main(void){
	ll n;
	cin >> n;

	vector<ll> a(n);
	for(auto&& x : a) cin >> x;

	vector<ll> b(n+1, 0);


	ll cnt = 0;
	for(ll i = 0; i<n;i++){
		cout << max(0LL, a[i] + cnt - n + i + 1) << " ";
		b[min(i+a[i]+cnt, n)]++;
		cnt += 1 - b[i];
	}

	cout << endl;

	return 0;
}
