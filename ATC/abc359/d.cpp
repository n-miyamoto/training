#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long ;
constexpr ll MOD = 998244353;

bool is_palindrome(ll b, ll k){
	for(ll i=0;i<k;i++){
		if( ((b>>i)&1) != ((b>>(k-i-1))&1)) return false; 
	}
	return true;
}

bool consistency_check(ll b, const string &str, ll k, ll start){
	bool check = true;
	for(ll i=0; i<k;i++){
		if(str[i+start]=='A' && (((b>>i)&1)==1)){
			check = false;
		} else if(str[i + start]=='B' && (((b>>i)&1)==0)){
			check = false;
		}
	}

	return check;
}

int main(void){
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	vector<std::vector<ll>> dp(n, std::vector<ll>(1 << k, 0));

	//initialize dp[k-1]
	for(ll i=0;i<(1<<k); i++){ //try all pattern A, B. A->0, b->1
		ll tmp;

		if(is_palindrome(i, k)) continue; 
		if(consistency_check(i, s, k, 0)){
			dp[k-1][i] = 1;
		}
	}

	//main dp loop
	for(ll i=k;i<n;i++){
		for(ll j=0;j<(1<<k);j++){
			if(is_palindrome(j, k)) continue; 
			if(consistency_check(j, s, k, i-k+1)){
				dp[i][j] = dp[i-1][(j<<1)&((1<<k)-1)] + 
						   dp[i-1][((j<<1)&((1<<k)-1)) + 1];
				dp[i][j] %= MOD;
			}
		}
	}


	ll ans = 0;
	for(const auto & x : dp[n-1]){
		ans += x;
		ans %= MOD;
	}

	cout << ans << endl;

	return 0;
}
