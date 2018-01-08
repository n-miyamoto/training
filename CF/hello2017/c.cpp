#include <bits/stdc++.h>
using namespace std;

#define BUF (32)
#define INF (1000000000000000005)
#define ll long long 

ll n,L;
ll c[32];
ll l[32];

int main(void){
	int ltmp=1;
	cin >> n >> L;
	for(int i=0;i<n;i++){
		cin >> c[i];
		if(i>0 && c[i]>2*c[i-1]) c[i] = 2*c[i-1];
		l[i] =ltmp;
		ltmp*=2;
		//cout << c[i]; 
	}

	ll ans = INF;
	ll tmp=0;
	for(int i=n-1;i>=0;i--){
		ll k=L/l[i]*c[i];
		L-=L/l[i]*l[i];
		if(L%l[i]==0){
			ans = min(ans,tmp+k);
		}
		else if(ans>tmp+k+c[i]){
			ans = tmp+k+c[i];
		}
		//cout << ans << tmp << k <<"\n";
		tmp+=k;
	}

	cout << ans << endl;

	return 0;

}
