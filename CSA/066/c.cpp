#include <bits/stdc++.h>
using namespace std;

#define BUF (1000005)
#define INF (1000000005)
#define ll long long 

int n,t;
map<int,int> m;
int d[BUF];

int main(void){
	cin >> n >> t;
	for(int i=0;i<n;i++){
		int tmp;
		cin >> tmp;
		m[tmp]++;
	}


	for(auto x:m){
		for(int i=x.first;i<=t;i+=x.first){
			d[i]+=x.second;
		}
	}

	int ans=0;
	for(int i=1;i<=t;i++) ans = max(d[i],ans);

	int cnt=0;
	for(int i=1;i<=t;i++) if(d[i]==ans) cnt++;

	cout << ans << " " << cnt << endl;	
	

	return 0;
}
