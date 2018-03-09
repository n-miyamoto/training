#include <bits/stdc++.h>

using namespace std;
#define BUF (200005)
#define ll long long 
#define INF 1000000000000000005

int n;
int m;
int s;
int t;
 
struct edge
{
	int to;
	ll cost;
};
typedef pair<ll,ll> P; 
vector<edge> edges[100010];
 ll dp_t[BUF]; 
 ll dp_s[BUF];
	
int main()
{
	cin >> n >> m;
	cin >> s >> t;
	for(int i = 0;i < m;i++)
	{
		int u,v;
		ll d;
		cin >> u >> v >> d;
		edges[u].push_back({v,d});
		edges[v].push_back({u,d});
	}
 
	ll dist[BUF];	
	for(int i=0;i<=n;i++)dist[i]=INF;
 
	{
		priority_queue<P,vector<P>,greater<P>> que;
		dist[s] = 0;
		que.push({dist[s],s});
 
		while(!que.empty())
		{
			int v = que.top().second;
			ll d = que.top().first;
			que.pop();
 
			if(dist[v] < d) continue;
 
			for(auto& e : edges[v])
			{
				if(dist[e.to] > d + e.cost)
				{
					dist[e.to] = d + e.cost;
					que.push({dist[e.to],e.to});
				}
			}
		}
	}
 
	dp_t[s] = 1;
	dp_s[t] = 1;
 
 
	vector<P> vec;
	for(int i = 1;i <= n;i++) vec.push_back({dist[i],i});
	sort(vec.begin(),vec.end());
	ll MOD = 1e9 + 7;
 
	// --> t
	for(int i = 0;i < n;i++)
	{
		for(auto & e : edges[vec[i].second])
		{
			if(dist[e.to] == dist[vec[i].second] + e.cost)
				(dp_t[e.to] += dp_t[vec[i].second]) %= MOD;
		}
	}
	for(int i = n - 1;i >= 0;i--)
	{
		for(auto & e : edges[vec[i].second])
		{
			if(dist[vec[i].second] == dist[e.to] + e.cost)
				(dp_s[e.to] += dp_s[vec[i].second]) %= MOD;
		}
	}
 
	ll result = dp_t[t] * dp_t[t];
	result %= MOD;
 
	auto mod = [MOD](ll num){
		return num % MOD;
	};
 
	for(int i = 1;i <= n;i++)
	{
		if(dist[i] * 2 == dist[t])
		{
			 (result += MOD - mod(mod(dp_t[i] * dp_t[i]) * mod(dp_s[i] * dp_s[i]))) %= MOD;
		}
	}
 
	for(int i = 1;i <= n;i++)
	{
		for(auto & e : edges[i])
		{
			int u = i;
			int v = e.to;
			if(dist[u] > dist[v]) continue;
			if(2 * dist[u] < dist[t] && 2 * dist[v] > dist[t] && dist[u] + e.cost == dist[v])
			{
				(result += MOD - mod(mod(dp_t[u] * dp_t[u]) * mod(dp_s[v] * dp_s[v]))) %= MOD;
			}
 
		}
	}
 
	cout << result << endl;
 
 
 
}
 