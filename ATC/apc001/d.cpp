#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 
#define INF (1000000005)
int n,m;
int used[BUF];
int cnt;
ll ans;
ll cost[BUF];

vector<int> v[BUF];

ll m1cost;
int m1node;
ll m2cost;

ll treec1[BUF];
ll treen1[BUF];

vector<ll> cost2;

void dfs(int node){
	used[node]=1;
	if(m1cost>cost[node]){
		m1cost=cost[node];
		m1node = node;
	}
	for(auto x: v[node]){
		if(used[x]==0) dfs(x);
	}

	return;
}

int main(void){
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> cost[i];
	for(int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for(int i=0;i<n;i++){
		if(used[i]==0){
			m1cost=INF;
			dfs(i);
			treec1[cnt]=m1cost;
			treen1[cnt]=m1node;
			cnt++;
		}
	}

	if(cnt==1){
		cout << "0\n";
		return 0;
	}

	for(int i=0;i<cnt;i++){
		ans+=treec1[i];
	}

	for(int i=0;i<cnt;i++){
		cost[treen1[i]]=INF;
	}
	sort(cost,cost+n);
	for(int i=0;i<cnt-2;i++){
		if(cost[i]==INF){
			cout << "Impossible\n";
			return 0;
		}
		ans+=cost[i];
	}
	
	cout << ans << "\n";
	return 0;
}
