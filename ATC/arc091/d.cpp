#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

ll n,k;
ll ans = 0;

int main(void){
	cin >> n >> k;

	for(int b=k+1;b<=n;b++){
		ans+=(b-k)*(n/b);
		if(k==0) ans--;
		ll tmp = n%b-k+1;
		if(tmp>0){
			ans+=tmp;
		}
	}

	cout << ans << endl;	
	return 0;
}
