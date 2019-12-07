#include <bits/stdc++.h>

using namespace std;
#define BUF (100005)
#define ll long long 

int n;
int mx=0;
vector<pair<int,int>> p;
map<pair<int,int> ,int> m;

typedef struct node{
	vector<int> from;
	vector<int> to;
} NODE;
vector<NODE> nodes(BUF);

void solve(int parent, int nd){
	int i=1;
	int c=0;
	if(parent!=0) c = m.at(make_pair(parent,nd));
	for(auto x: nodes[nd].to){
		if(c==i)i++;
		m.insert(make_pair(make_pair(nd,x), i));
		solve(nd, x);
		i++;
	}
}

int main(void){

	// input
	cin >> n;
	for(int i=1;i<n;i++){
		int a,b;
		cin >> a >> b;
		p.push_back(make_pair(a,b));
		nodes[a].to.push_back(b);
		nodes[b].from.push_back(a);
	}

	// calc colors
	for(int i=1;i<=n;i++){
		int s = nodes[i].to.size() +  nodes[i].from.size();
		mx = max(mx,s);
	}

	// solve 
	solve(0,1);

	// out
	cout << mx << endl;
	for(auto x : p) cout << m.at(x) << endl;

	return 0;
}
