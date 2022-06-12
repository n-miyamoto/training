#include <bits/stdc++.h>

using namespace std;
#define BUF (200005)
#define ll long long 
#define INF (200000000000005)

ll N, M;

typedef struct Edge{
	ll id;
	ll to;
	ll cost;
} Edge;

vector<Edge> edges[BUF];

int main(void){
	cin >> N >> M;
	for(ll i=0;i<M;i++){
		ll a, b, c;
		cin >> a >> b >> c;
		Edge e;
		e.id = i+1;
		e.to = b;
		e.cost = c;
		edges[a].push_back(e);

		e.to = a;
		edges[b].push_back(e);
	}

	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	vector<ll> d(N+1, INF);
	Edge e = {0,0,0};
	vector<Edge> es(N+1, e);

	d[1] = 0;
	pq.push(make_pair(d[1], 1)); 
	
    while( !pq.empty() ){
        pair<ll, ll> f = pq.top(); 
		pq.pop();
        ll u = f.second;

        if( d[u] < f.first) continue;

		for(auto x : edges[u]){
			if(d[x.to] > x.cost + d[u]){
				d[x.to] = x.cost + d[u];
				es[x.to] = x;
				pq.push(make_pair(d[x.to], x.to));
				//cout << u << x.to << endl;
			}
		}
    }

	for(int i=2; i<=N; i++){
		cout << es[i].id << " ";
	}
	cout << endl;


	return 0;
}
