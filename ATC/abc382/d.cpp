#include <bits/stdc++.h>

using namespace std;
using ll=long long;


ll n, m;

ll solve(ll d, bool debug, vector<ll>&a ){
	if(d == n-1){
		ll tmp = a[n-2] + 10;

		for(ll i=tmp;i<=m;i++){
			a[n-1] = i;
			if(debug){
				for(auto&& x: a) cout << x << " ";
				cout << endl;
			}
		}
		return max(0LL, m-tmp+1);
	}

	ll tmp = d==0? 1: a[d-1]+10; 
	ll ans = 0;
	while(tmp<=m){
		a[d] = tmp;
		ll p = solve(d+1, debug, a);
		if(p == 0) break;
		ans += p;
		tmp++;
	}

	return ans;
}

int main(void){
	cin >> n >> m;

	vector<ll> a(n);
	cout << solve(0, false, a) << endl;
	solve(0, true, a);
	
	return 0;
}


