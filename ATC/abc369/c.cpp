#include <bits/stdc++.h>

using namespace std;
using ll=long long;


int main(void){
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(auto& x : a )cin >> x ;

	if(n==1){
		cout << 1 << endl;
		return 0;
	}

	vector<ll> d(n-1);
	for(ll i=0;i<n-1;i++) d[i] = a[i+1] - a[i];

	vector<ll> seq_count;
	ll prev = d[0];
	ll count = 0;
	for(ll i=1;i<n-1;i++) {
		if(prev==d[i]) count++;
		else {
			seq_count.push_back(count+1);
			prev = d[i];
			count = 0;
		}
	}
	seq_count.push_back(count+1);
	
	ll ans = n;
	for(const auto x: seq_count) ans += (x+1)*(x)/2;
	cout << ans << endl;
	
	return 0;
}
