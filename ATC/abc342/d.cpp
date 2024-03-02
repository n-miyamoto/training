#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

constexpr auto MAX=200001;


ll f(ll x){
	ll k=1;
	ll ans = x;
	while(k*k<=x){
		if(x%(k*k)==0){
			ans = min(ans, x/(k*k));
		}
		k++;
	}
	return ans;
}

int main(void){
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(auto& x: a){
		cin >> x;
	}

	vector<ll> s(n);
	for(ll i=0;i<n;i++){
		s[i] = f(a[i]);
	}


	//for(const auto& x: s) cout << x << " ";
	sort(s.begin(), s.end());
	//for(const auto& x: s) cout << x << " ";

	ll ans = 0;
	for(ll i=0, cnt=0;i<n;i++){
		if(s[i]==0) ans += n-i-1;
		else{
			cnt++;
			if (i == n - 1 || s[i + 1] != s[i])
			{
				ans += cnt*(cnt-1)/2;
				cnt = 0;
			}
		}
	}

	cout << ans << endl;
	
	return 0;
}
