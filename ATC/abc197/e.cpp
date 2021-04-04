#include <bits/stdc++.h>

using namespace std;
#define BUF (200005)
#define ll long long 

ll n;
vector<ll> x;
vector<ll> c;

vector<ll> vc[BUF];

vector<pair<ll,ll> > p;

int main(void){
	cin >> n;
	x.resize(n+1);
	c.resize(n+1);

	for(ll i=1;i<=n;i++){
		cin >> x[i] >> c[i];
		vc[c[i]].push_back(x[i]);
	}

	for(ll i=1;i<BUF;i++){
		if(vc[i].empty()) continue;
		auto res = minmax_element(vc[i].begin(), vc[i].end());
		p.push_back(make_pair(*res.first, *res.second));	
	}
	p.push_back(make_pair(0,0));	

	ll N = p.size();
	vector<ll> dp_min(N);
	vector<ll> dp_max(N);
	dp_min[0] = abs(p[0].second) + p[0].second - p[0].first;
	dp_max[0] = abs(p[0].first) + p[0].second - p[0].first;
	for(ll i=1;i<N;i++){
		dp_min[i] = min(
			dp_min[i-1] + abs(p[i].second-p[i-1].first ) + p[i].second-p[i].first,
			dp_max[i-1] + abs(p[i].second-p[i-1].second) + p[i].second-p[i].first
			);
		dp_max[i] = min(
			dp_min[i-1] + abs(p[i].first-p[i-1].first) + p[i].second-p[i].first,
			dp_max[i-1] + abs(p[i].first-p[i-1].second) + p[i].second-p[i].first
			);
	}

	cout << dp_max[N-1] << endl;

	return 0;
}
