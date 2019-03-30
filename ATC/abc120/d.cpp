#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

ll n;
ll m;
static ll N;
ll p[BUF]; //parentp
ll d[BUF]; //depth
ll g[BUF]; //number of node
ll ans[BUF];

void uf_init(ll n){
	N=n;
	for(ll i=1;i<=n;i++) p[i]=i,d[i]=0, g[i]=1;
}

ll find(ll x){
	if(p[x]==x) return x;
	else{
		p[x] = find(p[x]);
		return p[x];
	}
}

ll get_group_num(ll x){
	x = find(x);
	return g[x];
}

void unite(ll x, ll y){
	x=find(x);
	y=find(y);

	if(x==y)return;

	if(d[x]<d[y]){
		p[x]=y;
		g[y] += g[x];
	}else if(d[x]>d[y]){
		p[y]=x;
		g[x] += g[y];
	}else{
		p[y]=x;
		g[x] += g[y];
		d[x]++;
	}
}

bool same(ll x, ll y){
	return find(x)==find(y);
}

pair<ll,ll> v[BUF];

int main(void){
	//input
	cin >> n >> m;
	for(ll i=1;i<=m;i++){
		pair<ll,ll> tmp;
		cin >> tmp.first >> tmp.second;
		v[i] = tmp;
	}

	//init last
	ans[m] = n*(n-1)/2;
	//init union find
	uf_init(n);

	for(ll i=m;i>0;i--)
	{
		ll tmp;
		if(same(v[i].first, v[i].second)){
			tmp = 0;
		}else{
			tmp = get_group_num(v[i].first) * get_group_num(v[i].second);
			unite(v[i].first, v[i].second);
		}

		ans[i-1] = ans[i]-tmp;
	}
	for(ll i=1;i<=m;i++) cout << ans[i] << "\r\n";
	
	return 0;
}
