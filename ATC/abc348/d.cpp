#include <bits/stdc++.h>

using namespace std;
#define BUF (1000)
#define ll long long 

bool can_move(int i, int j, int di, int dj, const vector<string> &map){
	int h = map.size();
	int w = map[0].size();
	if( (i + di >= 0 && i + di < h)&&(j + dj >= 0 && j+dj < w)){
		if(map[i+di][j+dj]!='#') return true;
	}
	return false;
}

struct status {
	int i;
	int j;
	int energy;
};

void bfs_from(int self_index, int n, int i, int j, int energy, const vector<vector<int>>& m, vector<string> a, vector<int> &v){
	queue<status> q;
	status start_status = {i, j, energy};
	q.push(start_status);
	while(!q.empty()){
		const auto p = q.front();
		q.pop();

		if(a[p.i][p.j]=='#') continue;
		if(a[p.i][p.j]=='T') v.push_back(n+1);
		if(m[p.i][p.j]>0 && m[p.i][p.j]!=self_index) v.push_back(m[p.i][p.j]);

		a[p.i][p.j]='#';

		if(p.energy>0){
			if(can_move(p.i, p.j,  1,  0, a)) q.push({p.i+1, p.j, p.energy-1});
			if(can_move(p.i, p.j, -1,  0, a)) q.push({p.i-1, p.j, p.energy-1});
			if(can_move(p.i, p.j,  0,  1, a)) q.push({p.i, p.j+1, p.energy-1});
			if(can_move(p.i, p.j,  0, -1, a)) q.push({p.i, p.j-1, p.energy-1});
		}
	}
}

void solve(int i, const vector<vector<int>> &g, vector<bool> &reachable){
	for(const auto& x : g[i]){
		if(!reachable[x]) {
			reachable[x] = true;
			solve(x, g, reachable);
		}
	}
}

int main(void){
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	for(auto& s: a) cin >> s;

	//find start and end
	using position=pair<int, int>;
	position start, end;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			char c = a[i][j];
			if (c=='S'){
				start = make_pair(i, j);
			}else if(c=='T'){
				end = make_pair(i, j);
			}
		}
	}

	// initialize all nodes
	int n;
	cin >> n;

	vector<vector<int>> m(h, vector<int>(w, -1));
	vector<int> r(n+2), c(n+2), e(n+2);
	r[0] = start.first;
	c[0] = start.second;
	e[0] = 0;

	for(int i=1;i<=n;i++){
		cin >> r[i] >> c[i] >> e[i];
		r[i]--; c[i]--;
		m[r[i]][c[i]] = i;
	}

	r[n+1] = end.first;
	c[n+1] = end.second;
	e[n+1] = 0;

	vector<vector<int>> g(n+2);

	// construct graph
	for(int i=0;i<n+1;i++){
		bfs_from(i, n, r[i], c[i], e[i], m, a, g[i]);
	}

	vector<bool> reachable(n+2, false);
	reachable[0] = true;

	solve(0, g, reachable);

	cout << (reachable[n+1] ? "Yes" : "No") << endl;
	return 0;
}
