#include <bits/stdc++.h>

using namespace std;
using ll=long long;
const ll MOD = 998244353;

int main(void){
	ll n, m;
	cin >> n >> m;

	ll ans = 0;
	for(ll i=0;i<=60;i++){
		if(m&(1LL<<i)){
			ans += (n+1)/(1LL<<(i+1))*(1LL<<i)%MOD;
			ans %= MOD;
			ans += max(0LL, (n+1)%(1LL<<(i+1)) - (1LL<<i))%MOD;
			ans %= MOD;
		}
	}

	cout << ans << endl; 
	
	return 0;
}
