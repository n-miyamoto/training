#include <bits/stdc++.h>

using namespace std;
#define BUF (1002)
#define MOD (1000000007)
#define ll long long 

ll n;
ll is_prime[BUF];
ll primes[BUF];
ll b_prime[BUF];
set<ll> big_primes;
vector<ll> a;
vector<ll> b;

void init_prime(void){
	for(ll i=2;i<BUF;i++) is_prime[i] = 1;
	for(ll i=2;i<BUF;i++){
		if(is_prime[i]==1){
			for(ll j=2*i;j<BUF;j+=i) is_prime[j] = 0;
		}
	}
}

int main(void){
	cin >> n;
	a.resize(n);
	for(ll i=0;i<n;i++) cin >> a[i];
	
	init_prime();
	//for (auto x : is_prime) cout << x << endl;

	for(auto x : a){
		ll A = x;
		for(ll i=2;i<BUF;i++){
			if(is_prime[i]){
				ll m = 0;
				while(A%i==0){
					m++;
					A/=i;
				}
				primes[i] = max(m, primes[i]);
			}
		}

		if(A!=1){
			big_primes.insert(A);
		}
	}

	//for (auto x : primes) cout << x << endl;
	//for (auto x : big_primes) cout << x << endl;

	ll ans = 0;
	for(auto x : a){
		for(ll i=2;i<BUF;i++) b_prime[i] = primes[i]; //init primes
		
		ll A = x;
		for(ll i=2;i<BUF;i++){
			if(is_prime[i]){
				while(A%i==0){
					b_prime[i]--;
					A/=i;
				}
			}
		}
		
		ll b = 1;
		for(ll i=2;i<BUF;i++){
			if(is_prime[i]){
				for(ll j=0;j<b_prime[i];j++) {
					b*=i;
					b%=MOD;
				}
			}
		}

		for(auto y : big_primes){
			if(y==A) continue;
			b*=y;
			b%=MOD;
		}
		
		ans += b;
		ans %=MOD;
	}
	
	cout << ans << endl;
	return 0;
}

