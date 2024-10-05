#include <bits/stdc++.h>

using namespace std;
using ll=long long;

void solve(
	const vector<vector<pair<ll, ll>>> &g, 
	vector<bool> &fixed,
	vector<ll> &ans,
	ll node
){
	for(const auto& [node_to, weight]: g[node]){
		if(fixed[node_to]) continue;
		ans[node_to] = weight + ans[node];
		fixed[node_to] = true;
		solve(g, fixed, ans, node_to);
	}
	return;
}

int main(void){
	ll n, m;
	cin >> n >> m;

	vector<vector<pair<ll, ll>>> g(n+1), g_rev(n+1);
	for(ll i=0;i<m;i++){
		ll u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(make_pair(v, w));
		g[v].emplace_back(make_pair(u, -w));
	}


	vector<bool> fixed(n+1, false);
	vector<ll> ans(n+1, 0);

	for(ll i=1;i<=n;i++){
		if(fixed[i]) continue;

		fixed[i] = true;
		ans[i] = 0;
		solve(g, fixed, ans, i);
		solve(g_rev, fixed, ans, i);
	}

	for(ll i=1;i<=n;i++) cout << ans[i] << " ";
	cout << endl;
	
	return 0;
}
