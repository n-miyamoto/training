#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

ll n,c;

ll dp_r[BUF];
ll dp_l[BUF];

ll x[BUF];
ll v[BUF];

ll ans = 0;

int main(void){
	cin >> n >> c;
	int i;
	//rotate tokei
	ll sum=0;
	for(i=1; i<=n;++i){
		cin >> x[i] >> v[i];
		sum+=v[i];
		dp_r[i] = max( dp_r[i-1] , sum - x[i]);
	}

	//rotate han-tokei
	sum=0;
	for(i=n;i>0;--i){
		sum+=v[i];
		dp_l[i] = max(dp_l[i+1], sum - (c-x[i]));
	}
	ans = max(dp_r[n], dp_l[1]);

	//rotate tokei to i and reverse.
	sum = 0;
	ll tmp = 0;
	for(i=1;i<n;++i){
		sum+=v[i];
		tmp = sum-2*x[i] + dp_l[i+1];
		ans = max(tmp,ans);
	}

	//rotate han-tokei to i and reverse.
	sum = 0;
	for(i=n;i>1;--i){
		sum+=v[i];
		tmp = sum-2*(c-x[i]) + dp_r[i - 1];
		ans = max(tmp,ans);
	}

	cout << ans << endl;

	return 0;
}
