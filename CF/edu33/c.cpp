#include <bits/stdc++.h>
using namespace std;
#define BUF (100005)
#define ll long long 


int n,m;
ll c[BUF];
int used[BUF];
vector<int> v[BUF];

ll dfs(int nd){
	if(used[nd]==1) return c[nd];

	used[nd]=1;
	ll min;
	min = c[nd];	
	if(v[nd].empty()==1) return min;

	for(auto x:v[nd]){
		ll tmp;
		tmp = dfs(x);
		if(min>tmp) min = tmp;
	}
	
	return min;
}

int main(void){
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> c[i];
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}


	ll ans;
	ans = 0;
	for(int i=1;i<=n;i++){
		if(used[i]==1)continue;
		ll min = dfs(i);	
	//	cout << min << " \n";	
		ans+=min;
	}
	cout << ans << endl;
	return 0;

}
