#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

ll n;

int main(void){
	cin >> n;
	vector<ll> w(n), x(n);
	for(ll i = 0;i<n; i++){
		cin >> w[i] >> x[i];
	}

	ll ans = 0;
	for(ll i=0;i<24;i++){
		ll temp = 0;
		for(ll j=0;j<n;j++){
			auto t = (i+x[j])%24;
			if (t>=9 && t<18) temp+= w[j];
		}
		ans = max(ans, temp);
	}

	cout << ans << endl; 
	
	return 0;
}
