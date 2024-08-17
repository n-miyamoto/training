#include <bits/stdc++.h>

using namespace std;
using ll=long long;
constexpr ll INF = (1LL << 60);

struct Edge
{
	ll to;
	ll cost;
};

using Graph = vector<vector<Edge>>;

using Pair = pair<ll, ll>;

void Dijkstra(const Graph& graph, vector<ll>& distances, vector<ll> nodes, ll startIndex)
{
	priority_queue<Pair, vector<Pair>, greater<Pair>> q;
	q.emplace((distances[startIndex] = nodes[startIndex]), startIndex);

	while (!q.empty())
	{
		const long long distance = q.top().first;
		const int from = q.top().second;
		q.pop();

		if (distances[from] < distance)
		{
			continue;
		}

		for (const auto& edge : graph[from])
		{
			// to までの新しい距離
			const ll d = (distances[from] + edge.cost + nodes[edge.to]);

			if (d < distances[edge.to])
			{
				q.emplace((distances[edge.to] = d), edge.to);
			}
		}
	}
}

int main(void){
	ll n, m;
	cin >> n >> m;
	vector<ll> nodes(n+1);
	for(ll i=1;i<=n;i++) cin >> nodes[i];

	Graph graph(n+1);
	for(ll i=0;i<m;i++){
		ll u, v, b;
		cin >> u >> v >> b;
		graph[u].push_back(Edge{v, b});
		graph[v].push_back(Edge{u, b});
	}

	vector<ll> distances(n+1, INF);
	Dijkstra(graph, distances, nodes, 1);

	for(ll i=2;i<=n;i++) cout << distances[i] << " ";
	cout << endl;
	
	return 0;
}
