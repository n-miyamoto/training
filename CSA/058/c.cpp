#include <bits/stdc++.h>
using namespace std;
#define BUF (200005)
#define ll long long 

int n,m;
vector<int> dif[BUF];

int main(void){
	cin >> n >> m;

	for(int i=0;i<m;i++){
		int a,b;
		cin >> a>> b;
		if(a>b) dif[a-b].push_back(b);
		else 	dif[b-a].push_back(a);
	}
	int ans=0;

	//odd
	int cnt = 0;
	for(auto x: dif[1]){
		cnt = 1;
		while(1){
			int f=0;
			for(auto y:dif[2*cnt+1]){
				if(y==x-cnt) f=1;
			}
			if(f==0) break;
			cnt++;
		}
		cout << cnt;
		if(2*cnt>ans) ans = 2*cnt;
	}

	//even
	for(auto x: dif[2]){
		int cnt=1;
		while(1){
			int f=0;
			for(auto y:dif[2*cnt+2]){
				if(y==x-cnt) f=1;
			}
			if(f==0) break;
			cnt++;
		}
		cout << cnt;
		if(2*cnt+1>ans) ans = 2*cnt+1;
	}

	if(ans == 0)ans = 1;
	cout << ans << endl;
	
	return 0;
}
