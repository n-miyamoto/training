#include <bits/stdc++.h>
using namespace std;

#define BUF (100005)
#define INF (1000000005)
#define ll long long 


ll n,k,A,B;

int main(void){
	ll ans = 0;
	cin >> n >> k >> A >> B;
	ll  x=n;

	if(k==1){
		cout << (x-1)*A;
		return 0;
	}

	while(x!=1){
		if(x/k==0){
			ans+=(x%k-1)*A;
			x=1;
			break;	
		}
		else if(x%k==0){
			ans += min(B,(x-x/k)*A);
			x=x/k;
		}else{
			ans+=(x%k)*A;
			x=x/k*k;
		}

	}

	cout << ans << endl;
	return 0;
}
