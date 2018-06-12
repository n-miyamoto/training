#include <bits/stdc++.h>

using namespace std;
#define BUF (200005)
#define ll long long 

ll n;
ll s[BUF];
ll ans = 0;

int main(void){
	cin >> n;
	for(ll i=1;i<=n;++i){
		ll tmp;
		cin >> tmp;
		s[i] = s[i-1]+tmp;
	//	if(tmp==0)ans++;
	}
	sort(s,s+n+1);

	ll j = 0;
	while(j<=n){
		ll num = s[j];
		ll cnt = 0;
		while(num==s[j] && j <= n){
			j++;
			cnt++;
		}
		ans+=cnt*(cnt-1)/2;
	}	

	cout << ans << endl;


	return 0;
}
