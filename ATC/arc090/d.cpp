#include <bits/stdc++.h>

using namespace std;
#define BUF (200005)
#define ll long long 

int n,m;
vector<pair<int,int>> e[BUF];

int used[BUF];
int pos[BUF];

int dfs(int nd){
	
	vector<int> next;
	for(auto x:e[nd]){
		if(used[x.first]==0){
			used[x.first]=1;
			pos[x.first]=pos[nd]+x.second;
			next.push_back(x.first);
		}else{
			if(pos[x.first]!=pos[nd]+x.second) return -1;
		}
	}
	int ret=0;
	for(auto x:next){
		if(dfs(x)<0)ret = -1;
	}
	return ret;

}

int main(void){
	cin >> n >> m;

	for(int i=1;i<=m;i++){
		pair<int,int> p;
		int l,r,d;
		cin >> l >> r >> d;
		p.first=r;
		p.second=d;
		e[l].push_back(p);
		p.first=l;
		p.second=-d;
		e[r].push_back(p);
	}

	for(int i=1;i<=n;i++){
		if(used[i]==0){
			if(dfs(i)<0){
				cout << "No\n";
				return 0;
			}
		}
	}

	cout << "Yes\n";
	
	return 0;
}
