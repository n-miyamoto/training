#include <bits/stdc++.h>

using namespace std;
using ll = long long;

unordered_map<ll, ll> cache; 

ll solve(ll n){
	if(n==1) return 0;

	if(cache.contains(n)){
		return cache[n];
	}

	ll ans;
	if(n%2==0){
		ans = n + 2*solve(n/2);
	}else{
		ans = n + solve(n/2) + solve(n/2+1);
	}

	cache[n] = ans;
	return ans;
}

int main(void){
	ll n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}

