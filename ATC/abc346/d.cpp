#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 


int main(void){

	ll n;
	cin >> n;

	string s;
	cin >> s;

	vector<ll> costs(n);
	for(auto& c: costs){ cin >> c;}
	
	vector<ll> prefix_sum0(n, 0);
	vector<ll> prefix_sum1(n, 0);

	//initialize first elem
	if(s[0]=='0'){
		prefix_sum0[0] = 0;
		prefix_sum1[0] = costs[0];
	}else{
		prefix_sum0[0] = costs[0];
		prefix_sum1[0] = 0;
	}

	for(ll i=1;i<n;i++){
		if(i%2==0){ //even
			if(s[i]=='0'){
				prefix_sum0[i] = prefix_sum0[i-1];
				prefix_sum1[i] = prefix_sum1[i-1] + costs[i];
			}else{
				prefix_sum0[i] = prefix_sum0[i-1] + costs[i];
				prefix_sum1[i] = prefix_sum1[i-1];
			}
		}else{ //odd
			if(s[i]=='1'){
				prefix_sum0[i] = prefix_sum0[i-1];
				prefix_sum1[i] = prefix_sum1[i-1] + costs[i];
			}else{
				prefix_sum0[i] = prefix_sum0[i-1] + costs[i];
				prefix_sum1[i] = prefix_sum1[i-1];
			}
		}
	}

	const ll max = (ll)1000000001 * 200000;
	ll ans = max;
	for(ll i=0;i<n-1;i++){
		ll tmp0 = prefix_sum0[i] + prefix_sum1[n-1] - prefix_sum1[i];
		ll tmp1 = prefix_sum1[i] + prefix_sum0[n-1] - prefix_sum0[i];

		ans = min(ans, min(tmp0, tmp1));
	}

	cout << ans << endl;

	return 0;
}
