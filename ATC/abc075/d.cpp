#include <bits/stdc++.h>

using namespace std;
#define INF  (2000000005)
#define BUF (1000)
#define ll long long 

int n,k;
vector<int> x,y;
vector<pair<int,int>> pv;

int main(void){
	cin >> n >> k;

	for(int i=0;i<n;i++){
		int tx,ty;
		cin>>tx>>ty;
		x.push_back(tx);
		y.push_back(ty);
	}	

	ll ans=INF;
	ans*=INF;
	for(auto u1:x) for(auto u2:x){
		for(auto v1:y) for(auto v2:y){
			
			int cnt = 0;
			for(int i=0;i<n;i++){
				if(x[i]>u1&&x[i]>u2) continue;
				if(x[i]<u1&&x[i]<u2) continue;
				if(y[i]<v1&&y[i]<v2) continue;
				if(y[i]>v1&&y[i]>v2) continue;

				cnt++;
			}
			if(cnt>=k){
				ll tmp=(ll)abs(v1-v2)*(ll)abs(u1-u2);
				if(tmp<ans) ans = tmp;
			}				
		}
	}

	cout << ans << endl;
	return 0;
}
