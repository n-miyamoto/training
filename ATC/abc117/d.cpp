#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 


ll N, K;
ll A[BUF];
ll b[50];
ll k[50];
ll a[50];

vector<ll> v;

int main(void){
	cin >> N >> K;
	for(int i=1;i<=N;i++) cin >> A[i];

	for(int i=1;i<=N;i++){
		for(int j=0;j<50;j++){
			if((A[i]>>j)&1) b[j]++;
		}
	}


	ll ans = 0;
	for(int j=50;j>=0;j--){
		if((ans|(1LL<<j))<=K && (b[j]<N-b[j])) {
			ans+=(1LL<<j);
			//cout << j << " ";
		}
	}
	//cout << ans;
	ll ret = 0;
	for(int i=1;i<=N;i++){
		ret += A[i]^ans;
	}

	cout << ret << endl;
	return 0;
}
