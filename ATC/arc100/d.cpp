#include <bits/stdc++.h>

using namespace std;
#define BUF (200005)
#define ll long long 
#define INF (100000000000000)

ll n;
ll a[BUF];
ll s[BUF];


ll minmax4(ll a,ll b,ll c,ll d){
	ll mn,mx;
	mn = min(a,b);
	mn = min(mn,c);
	mn = min(mn,d);

	mx = max(a,b);
	mx = max(mx,c);
	mx = max(mx,d);

	return mx-mn;
}

void print4(ll a, ll b, ll c, ll d){
	cout << a << " " << b << " " << c << " " << d << "\n";
}

int main(void){
	cin >> n;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}

	ll L,R;
	ll l=1,r=3;
	ll ans = INF;
	for(ll i=2;i<n-1;i++){
		L=s[i];
		R=s[n]-s[i];

		while(abs(2*s[l]-L) > abs(2*s[l+1]-L)){
			if( (l+1)==i) break;
			l++;
		}

		if(r<i+1)r=i+1;
		while(abs(2*(s[r]-L)-R) > abs(2*(s[r+1]-L)-R)){
			if( (r+1)==n) break;
			r++;
		}
		ans = min(ans, minmax4(s[l], L-s[l], s[r]-L, s[n]-s[r]) );	
	}

	cout << ans << endl;
	return 0;
}
